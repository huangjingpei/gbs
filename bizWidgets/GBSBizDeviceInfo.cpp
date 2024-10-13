#include "GBSBizDeviceInfo.h"
#include "ui_GBSBizDeviceInfo.h"

GBSBizDeviceInfo::GBSBizDeviceInfo(QWidget *parent)
	: QWidget(parent),
	  ui(new Ui::GBSBizDeviceInfo)
{
	ui->setupUi(this);
	ui->wdgLocalInfo->setStyleSheet(
		"QWidget {"
		"   background-color: #F5F5F5;"  // 主窗口的背景颜色
		"   border: 2px solid #B0B0B0;"  // 窗口边框
		"   border-radius: 10px;"        // 窗口圆角
		"   padding: 10px;"              // 内边距
		"}");

	ui->wdgRemoteInfo->setStyleSheet(
		"QWidget {"
		"   background-color: #F5F5F5;"  // 主窗口的背景颜色
		"   border: 2px solid #B0B0B0;"  // 窗口边框
		"   border-radius: 10px;"        // 窗口圆角
		"   padding: 10px;"              // 内边距
		"}");

	ui->wdgRunningInfo->setStyleSheet(
		"QWidget {"
		"   background-color: #F5F5F5;"  // 主窗口的背景颜色
		"   border: 2px solid #B0B0B0;"  // 窗口边框
		"   border-radius: 10px;"        // 窗口圆角
		"   padding: 10px;"              // 内边距
		"}");

	ui->wdgStreamInfo->setStyleSheet(
		"QWidget {"
		"   background-color: #F5F5F5;"  // 主窗口的背景颜色
		"   border: 2px solid #B0B0B0;"  // 窗口边框
		"   border-radius: 10px;"        // 窗口圆角
		"   padding: 10px;"              // 内边距
		"}");


}

GBSBizDeviceInfo::~GBSBizDeviceInfo()
{
	delete ui;
}
