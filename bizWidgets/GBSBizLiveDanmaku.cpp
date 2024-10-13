#include "GBSBizLiveDanmaku.h"
#include "ui_GBSBizLiveDanmaku.h"

GBSBizLiveDanmaku::GBSBizLiveDanmaku(QWidget *parent)
	: QWidget(parent),
	  ui(new Ui::GBSBizLiveDanmaku)
{
	ui->setupUi(this);

}

GBSBizLiveDanmaku::~GBSBizLiveDanmaku()
{
	delete ui;
}
