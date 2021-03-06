#include "getinfo.h"

GetInfo::GetInfo(Device *device)
	: SysExMessage(Command::GET_INFO, SysExMessage::QUERY, device) {
	m_pRetSetInfos = new std::map<DeviceInfoItem, RetSetInfo *>();
}

GetInfo::GetInfo(Device *device, RetInfoList *infoList)
	: SysExMessage(Command::GET_INFO, SysExMessage::QUERY, device),
	  m_pInfoList(infoList) {
	m_pRetSetInfos = new std::map<DeviceInfoItem, RetSetInfo *>();
	std::vector<DeviceInfoItem> *implementedInfos =
		infoList->getImplementedInfos();
	for (std::vector<DeviceInfoItem>::iterator it = implementedInfos->begin();
		 it < implementedInfos->end(); ++it) {
		this->setInfoItem(*it);
		execute();
		RetSetInfo *info = (RetSetInfo *)getAnswer();
		(*m_pRetSetInfos)[*it] = info;
	}
}

GetInfo::~GetInfo() { delete m_pRetSetInfos; }

BYTE_VECTOR *GetInfo::m_pGetMessageData() {
	BYTE_VECTOR *messageData = new BYTE_VECTOR();
	messageData->push_back(this->m_InfoItem);
	return messageData;
}

std::string GetInfo::getDataAsString() {
	if (m_pData && m_pData->size() > 0) {
		std::string result(m_pData->begin() + 1, m_pData->end());
		return result;
	} else {
		return std::string();
	}
}

std::string GetInfo::getItemValue(SysExMessage::DeviceInfoItem item) {
	RetSetInfo *i = (*m_pRetSetInfos)[item];
	return i->getValue();
}

std::map<SysExMessage::DeviceInfoItem, RetSetInfo *> *
GetInfo::getRetSetInfos() {
	return m_pRetSetInfos;
}

void GetInfo::deviceInfoChanged(SysExMessage::DeviceInfoItem item,
								std::string value) {
	std::cout << "DeviceInfo: Item " << item
			  << " in DeviceInfoTable changed to value " << value << std::endl;
}

void GetInfo::createAnswer(Command cmd, std::vector<unsigned char> *message,
						   Device *device) {
	m_pAnswer = new RetSetInfo(cmd, message, device);
	m_pAnswer->parseAnswerData();
}
