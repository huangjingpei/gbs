#include "GBSBizLiveGuarder.h"
#include "ui_GBSBizLiveGuarder.h"

GBSBizLiveGuarder::GBSBizLiveGuarder(QWidget *parent)
	: QWidget(parent),
	  ui(new Ui::GBSBizLiveGuarder)
{
	ui->setupUi(this);

}

GBSBizLiveGuarder::~GBSBizLiveGuarder()
{
	delete ui;
}
