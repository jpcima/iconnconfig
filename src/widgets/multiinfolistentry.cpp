#include "multiinfolistentry.h"

MultiInfoListEntry::MultiInfoListEntry() {}

MultiInfoListEntry::MultiInfoListEntry(
		MultiInfoListEntry::ListEntryCode entryCode, std::string name, int index)
		: entryCode(entryCode), name(name), index(index) {
	icon = QIcon();
	if (entryCode == SECTION) {
		enabled = false;
		selectable = false;
	}
}
