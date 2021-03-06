#include "multiinfowidget.h"
#include "../iconnconfigmain.h"
#include "ui_multiinfowidget.h"

MultiInfoWidget::MultiInfoWidget(MioMain *parent, Device *device,
                                 QString windowTitle)
    : QDockWidget(parent), ui(new Ui::MultiInfoWidget), device(device) {
  ui->setupUi(this);
  setWindowTitle(windowTitle);
  connect(this, SIGNAL(visibilityChanged(bool)), this, SLOT(visible(bool)));
  // hack to delete the titlebar

  QWidget *lTitleBar = titleBarWidget();
  setTitleBarWidget(new QWidget());
  delete lTitleBar;
}

MultiInfoWidget::~MultiInfoWidget() { delete ui; }

void MultiInfoWidget::on_infoList_currentRowChanged(int currentRow) {
  MultiInfoListEntry *selectedInfo = infoSections->at(currentRow);
	if (!selectedInfo->enabled)
		return;
  if (selectedInfo->widget == 0) {
    selectedInfo->widget = createWidget(selectedInfo);
  }
  if (selectedInfo->widget) {
    QWidget *w = selectedInfo->widget;
    ((MioMain *)this->parentWidget())->replacePanel(w);
    emit infoTabChanged(currentRow);
  }
}

void MultiInfoWidget::visible(bool visible) {
  if (visible)
    openLastSelectedSection();
}

void MultiInfoWidget::createInfoSections() {
  std::vector<MultiInfoListEntry *>::iterator it;
  for (it = infoSections->begin(); it != infoSections->end(); ++it) {
		MultiInfoListEntry *entry = (*it);
		QListWidgetItem *item = new QListWidgetItem();
    if (entry->index == -1)
			item->setText(QString(entry->name.c_str()));
    else {
			QString qstr(entry->name.c_str());
                        qstr.append(" ");
                        QString num = QString::number(entry->index + 1);
                        qstr.append(num);
			item->setText(qstr);
//			item->setText("asprintf");
//					QString::asprintf("%s %i", entry->name.c_str(), entry->index + 1));
    }
    Qt::ItemFlags flags = item->flags();
    if (!entry->enabled)
	flags = flags & ~Qt::ItemIsEnabled;
    if (!entry->selectable)
	flags = flags & ~Qt::ItemIsSelectable;
    item->setFlags(flags);
    if (!entry->icon.isNull())
	item->setIcon(entry->icon);
    ui->infoList->addItem(item);
  }
}

int MultiInfoWidget::getFirstSelectableRow() {
	for (int i = 0; i < this->ui->infoList->count(); ++i) {
		MultiInfoListEntry *selectedInfo = infoSections->at(i);
		if (selectedInfo->enabled)
			return i;
	}
	return 0;
}

void MultiInfoWidget::openLastSelectedSection() {
  if (this->ui->infoList->currentRow() == -1) {
		this->ui->infoList->setCurrentRow(getFirstSelectableRow());
  } else {
    on_infoList_currentRowChanged(this->ui->infoList->currentRow());
  }
}
