#include "portswidget.h"
#include "../sysex/retcommandlist.h"
#include "../sysex/retsetmidiinfo.h"
#include "portdisplayhelper.h"
#include "portroutingwidget.h"

#include <QLabel>
#include <QScrollArea>

PortsWidget::PortsWidget(MioMain *parent, Device *device, QString windowTitle)
	: MultiInfoWidget(parent, device, windowTitle) {
	infoSections = new std::vector<MultiInfoListEntry *>();
	if (device->getCommands()->isCommandSupported(
			Command::GET_MIDI_PORT_ROUTE)) {
		getMidiPortSections(device);
	}
}

PortsWidget::~PortsWidget() {}

void PortsWidget::getMidiPorts(
	std::vector<RetSetMidiPortInfo *> *midiPortInfos) {
	std::vector<RetSetMidiPortInfo *>::iterator it;
	for (it = midiPortInfos->begin(); it != midiPortInfos->end(); ++it) {
		RetSetMidiPortInfo *midiPortInfo = *it;
		MultiInfoListEntry *entry = new MultiInfoListEntry(
			MultiInfoListEntry::PORT_ROUTING, midiPortInfo->getPortName());
		entry->icon =
			PortDisplayHelper::getPortIcon(midiPortInfo->getPortType());
		entry->message = midiPortInfo;
		entry->enabled = midiPortInfo->getInputEnabled();
		infoSections->push_back(entry);
	}
}

void PortsWidget::getMidiPortSections(Device *device) {
	MIDI_PORT_INFOS *midiPortInfoSections = device->getMidiPortInfos();
	std::map<int, std::vector<RetSetMidiPortInfo *> *>::iterator it;
	for (it = midiPortInfoSections->begin(); it != midiPortInfoSections->end();
		 ++it) {
		int section = it->first;
		int jack = section & 255;
		MidiPortType portType = (MidiPortType)(section >> 8);
		std::string portTypeName =
			PortDisplayHelper::getMidiPortTypeName(portType);
		if (jack > 0)
			portTypeName += " " + std::to_string(jack);
		infoSections->push_back(
			new MultiInfoListEntry(MultiInfoListEntry::SECTION, portTypeName));
		std::vector<RetSetMidiPortInfo *> *midiPortInfos = it->second;
		getMidiPorts(midiPortInfos);
	}
}

QWidget *PortsWidget::createWidget(MultiInfoListEntry *entry) {
	std::cout << "create PortsWidget" << std::endl;
	RetSetMidiPortInfo *midiPortInfo = (RetSetMidiPortInfo *)entry->message;
	int portNumber = midiPortInfo->getPortId();
	PortRoutingWidget *w =
		new PortRoutingWidget(device, portNumber, this->parentWidget());
	QScrollArea *a = new QScrollArea(this);
	a->setWidget(w);
	return a;
}
