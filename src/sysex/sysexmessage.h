#ifndef SYSEXMESSAGE_H
#define SYSEXMESSAGE_H

#include "../definitions.h"
#include "../device.h"
#include "midi.h"

#include <QObject>
#include <map>
#include <vector>

typedef std::vector<int> AcceptedAnswers;
typedef std::map<int, AcceptedAnswers> CommandAcceptedAnswers;

/**
 * @brief The SysExMessage class
 */
class SysExMessage {

	// enums
public:
	enum DeviceInfoItem {
		ACCESSORY_NAME = 0x01, /*!< Name of acessory */
		MANUFACTURER_NAME,	 /*!< Name of device manufacturer manufacturer */
		MODEL_NUMBER,		   /*!< Devices modelnumber */
		SERIAL_NUMBER,		   /*!< Devices serial number */
		FIRMWARE_VERSION,	  /*!< Installed firmware version */
		HARDWARE_VERSION,	  /*!< Hardware version of device */
		DEVICE_NAME = 0x10	 /*!< Name of device (writable) */
	};

	enum CommandFlags {
		ANSWER = 0x00, /*!< Answer from device */
		QUERY = 0x40   /*!< Query from device */
	};

	enum Errors {
		NO_DEVICE = -1,		  /*!< No device found or assigned */
		COMMAND_ACCEPTED = 0, /*!< No error */
		UNKNOWN_COMMAND,	  /*!< Command not known by device */
		MALFORMED_MESSAGE,	/*!< Message format has errors */
		COMMAND_FAILED		  /*!< Command failed for unknown reasin */
	};

	static CommandAcceptedAnswers commandAcceptedAnswers;

public:
	SysExMessage(Command m_Command, CommandFlags flags, Device *m_pDevice);
	SysExMessage(Command m_Command, BYTE_VECTOR *message, Device *m_pDevice);
	virtual ~SysExMessage();

	// methods
	virtual BYTE_VECTOR *getMIDISysExMessage();
	std::string getDataAsString();
	long getDataAsLong();
	Command parseAnswer(BYTE_VECTOR *m_pAnswer);
	SysExMessage *getAnswer();
	SysExMessage *query();
	int execute();
	void setDebug(bool debug);
	void printRawData();
	virtual void parseAnswerData() {}

	// getter
	unsigned char getCmdflags() const;
	Command getCommand() { return m_Command; }

	// setter
	void setCmdflags(unsigned char value);

protected:
	virtual BYTE_VECTOR *getCommandData() { return m_pCommandData; }
	virtual BYTE_VECTOR *m_pGetMessageData() { return new BYTE_VECTOR(); }
	virtual BYTE_VECTOR *getTransactionId() {
		if (m_pTransactionId == 0) {
			if (m_pDevice != 0)
				return this->m_pDevice->nextTransactionId();
			m_pTransactionId = new BYTE_VECTOR();
			m_pTransactionId->push_back(0x00);
			m_pTransactionId->push_back(0x01);
		}
		return m_pTransactionId;
	}
	bool checkAnswerValid(long answerCommandId);
	virtual void createAnswer(Command m_Command __attribute__((unused)),
							  BYTE_VECTOR *message __attribute__((unused)),
							  Device *m_pDevice __attribute__((unused)));
	void readSettings();
	void storeSettings();

	virtual int getSettingsId() = 0;
	virtual int getSettingsIndex() = 0;
	virtual std::string getStorableValue() = 0;

	void extractData(std::vector<unsigned char> *message);


	// members
protected:
	Command m_Command;
	unsigned char m_iCmdflags;
	AcceptedAnswers m_AcceptedAnswers;
	Device *m_pDevice = 0;
	SysExMessage *m_pAnswer;
	BYTE_VECTOR *m_pCommandData = 0;
	BYTE_VECTOR *m_pTransactionId = 0;
	BYTE_VECTOR *m_pDeviceHeader = 0;
	BYTE_VECTOR *m_pResultData = 0;
	BYTE_VECTOR *m_pData = 0;

	unsigned char m_iCommandVersionNumber = 0;

	bool debug = false;
};

#endif// SYSEXMESSAGE_H
