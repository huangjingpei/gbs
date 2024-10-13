#include "gbsmainbizwindow.h"
#include "ui_gbsmainbizwindow.h"
#include <QPushButton>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QTimer>
#include "naviWidgets/gbsnavidata.h"
#include "naviWidgets/gbsnaviproduct.h"
#include "naviWidgets/gbsnavilive.h"
#include "naviWidgets/gbsnavitranslate.h"
#include "naviWidgets/gbsnavisetting.h"
#include "naviWidgets/gbsnaviai.h"


#include "bizWidgets/GBSBizDeviceInfo.h"
#include "bizWidgets/GBSBizEShopData.h"
#include "bizWidgets/GBSBizAIData.h"
#include "bizWidgets/GBSBizSoYoung.h"


#include "bizWidgets/GBSBizSettingBasic.h"
#include "bizWidgets/GBSBizSettingOutput.h"
#include "bizWidgets/GBSBizSettingAV.h"


#include "bizWidgets/gbsbizlivepusher.h"

#include "../obs-http-client.hpp"




GBSMainBizWindow::GBSMainBizWindow(QWidget *parent)
	: QWidget(parent),
	  ui(new Ui::GBSMainBizWindow)
{
	ui->setupUi(this);
	currentHoriButtonIndex = 2;
	currentVertButtonIndex = 1;
	setSizePolicy(
		QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint |
		       Qt::WindowMaximizeButtonHint |
		       Qt::WindowCloseButtonHint);

	ui->imgLogo->setStyleSheet("border-image:url(:gbs/images/gbs/login/gbs-logo.png)");
	ui->imgBanner->setStyleSheet("border-image:url(:gbs/images/gbs/login/gbs-gbcg-banner.png)");


	ui->btnData->setStyleSheet(
		"QPushButton {"
		"   background-color: #9CA4AB;"
		"   border: none;" // 无边框
		"   border-radius: 5px;" // 圆角
		"   font-size: 14px;"
		"   text-align: center;"
		"}"
		"QPushButton:hover {"
		"   background-color: #EB3F5E;"
		"}"
		"QPushButton:pressed {"
		"   background-color: #F9F9F9;" // 按下状态背景颜色
		"   padding-left: 1px;  /* 向左移动 3px */"
		"   padding-top: 1px;    /* 向上移动 3px */"
		"}"
		);


	ui->btnProduct->setStyleSheet(
		"QPushButton {"
		"   background-color: #9CA4AB;"
		"   border: none;" // 无边框
		"   border-radius: 5px;" // 圆角
		"   font-size: 14px;"
		"   text-align: center;"
		"}"
		"QPushButton:hover {"
		"   background-color: #EB3F5E;"
		"}"
		"QPushButton:pressed {"
		"   background-color: #F9F9F9;" // 按下状态背景颜色
		"   padding-left: 1px;  /* 向左移动 3px */"
		"   padding-top: 1px;    /* 向上移动 3px */"
		"}"
		);

	ui->btnLive->setStyleSheet(
		"QPushButton {"
		"   background-color: #9CA4AB;"
		"   border: none;" // 无边框
		"   border-radius: 5px;" // 圆角
		"   font-size: 14px;"
		"   text-align: center;"
		"}"
		"QPushButton:hover {"
		"   background-color: #EB3F5E;"
		"}"
		"QPushButton:pressed {"
		"   background-color: #F9F9F9;" // 按下状态背景颜色
		"   padding-left: 1px;  /* 向左移动 3px */"
		"   padding-top: 1px;    /* 向上移动 3px */"
		"}"
		);

	ui->btnTranslate->setStyleSheet(
		"QPushButton {"
		"   background-color: #9CA4AB;"
		"   border: none;" // 无边框
		"   border-radius: 5px;" // 圆角
		"   font-size: 14px;"
		"   text-align: center;"
		"}"
		"QPushButton:hover {"
		"   background-color: #EB3F5E;"
		"}"
		"QPushButton:pressed {"
		"   background-color: #F9F9F9;" // 按下状态背景颜色
		"   padding-left: 1px;  /* 向左移动 3px */"
		"   padding-top: 1px;    /* 向上移动 3px */"
		"}"
		);

	ui->btnSetting->setStyleSheet(
		"QPushButton {"
		"   background-color: #9CA4AB;"
		"   border: none;" // 无边框
		"   border-radius: 5px;" // 圆角
		"   font-size: 14px;"
		"   text-align: center;"
		"}"
		"QPushButton:hover {"
		"   background-color: #EB3F5E;"
		"}"
		"QPushButton:pressed {"
		"   background-color: #F9F9F9;" // 按下状态背景颜色
		"   padding-left: 1px;  /* 向左移动 3px */"
		"   padding-top: 1px;    /* 向上移动 3px */"
		"}"
		);

	ui->btnAI->setStyleSheet(
		"QPushButton {"
		"   background-color: #9CA4AB;"
		"   border: none;" // 无边框
		"   border-radius: 5px;" // 圆角
		"   font-size: 14px;"
		"   text-align: center;"
		"}"
		"QPushButton:hover {"
		"   background-color: #EB3F5E;"
		"}"
		"QPushButton:pressed {"
		"   background-color: #F9F9F9;" // 按下状态背景颜色
		"   padding-left: 1px;  /* 向左移动 3px */"
		"   padding-top: 1px;    /* 向上移动 3px */"
		"}"
		);


	ui->btnNotification->setStyleSheet(
		"QPushButton {"
		"   background-image: url(:gbs/images/gbs/login/gbs-receive-notificaton.png);"
		"   background-repeat: no-repeat;"
		"   background-position: center;"
		"   color: white;"
		"   border: none;" // 无边框
		"   border-radius: 5px;" // 圆角
		"   font-size: 16px;"
		"   padding: 0;" // 不添加内边距
		"}"
		"QPushButton:hover {"
		"   background-color: #EB3F5E;"
		"}"

		"QPushButton:pressed {"
		"   padding-left: 1px;  /* 向左移动 3px */"
		"   padding-top: 1px;    /* 向上移动 3px */"
		"}"
		);
	ui->btnMinimize->setStyleSheet(
		"QPushButton {"
		"   background-image: url(:gbs/images/gbs/login/gbs-minimize-window.png);"
		"   background-repeat: no-repeat;"
		"   background-position: center;"
		"   color: white;"
		"   border: none;" // 无边框
		"   border-radius: 5px;" // 圆角
		"   font-size: 16px;"
		"   padding: 0;" // 不添加内边距
		"}"
		"QPushButton:hover {"
		"   background-color: #EB3F5E;"
		"}"
		"QPushButton:pressed {"
		"   padding-left: 1px;  /* 向左移动 3px */"
		"   padding-top: 1px;    /* 向上移动 3px */"
		"}"
		);
	ui->btnClose->setStyleSheet(
		"QPushButton {"
		"   background-image: url(:gbs/images/gbs/login/gbs-close-window.png);"
		"   background-repeat: no-repeat;"
		"   background-position: center;"
		"   color: white;"
		"   border: none;" // 无边框
		"   border-radius: 5px;" // 圆角
		"   font-size: 16px;"
		"   padding: 0;" // 不添加内边距
		"}"
		"QPushButton:hover {"
		"   background-color: #EB3F5E;"
		"}"
		"QPushButton:pressed {"
		"   padding-left: 1px;  /* 向左移动 3px */"
		"   padding-top: 1px;    /* 向上移动 3px */"
		"}"
		);
	ui->btnProfile->setStyleSheet(
		"QPushButton {"
		"   background-image: url(:gbs/images/gbs/login/gbs-my-profile.png);"
		"   background-repeat: no-repeat;"
		"   background-position: center;"
		"   color: white;"
		"   border: none;" // 无边框
		"   border-radius: 5px;" // 圆角
		"   font-size: 16px;"
		"   padding: 0;" // 不添加内边距
		"}"
		"QPushButton:hover {"
		"   background-color: #EB3F5E;"
		"}"
		"QPushButton:pressed {"
		"   padding-left: 1px;  /* 向左移动 3px */"
		"   padding-top: 1px;    /* 向上移动 3px */"
		"}"
		);



	horiButtons.append(ui->btnData);
	horiButtons.append(ui->btnProduct);
	horiButtons.append(ui->btnLive);
	horiButtons.append(ui->btnTranslate);
	horiButtons.append(ui->btnSetting);
	horiButtons.append(ui->btnAI);


	GBSNaviData *gbsNaviData = new GBSNaviData(this);
	QHBoxLayout* bizPageLayout = new QHBoxLayout;
	naviLayout = new QHBoxLayout;
	bizLayout.reset(new QHBoxLayout);
	GBSBizDeviceInfo *gbsBizDevieInfo = new GBSBizDeviceInfo(this);
	bizPageLayout->addLayout(naviLayout);
	bizPageLayout->addLayout(bizLayout.data());
	bizPageLayout->setStretch(0, 205);
	bizPageLayout->setStretch(1, 1234);
	naviLayout->addWidget(gbsNaviData);
	bizLayout->addWidget(gbsBizDevieInfo);

	connect(ui->btnClose, &QPushButton::clicked, this, &GBSMainBizWindow::close);
	ui->verticalLayout->setSpacing(0);
	ui->verticalLayout->addWidget(ui->horizontalNavi);
	ui->verticalLayout->addLayout(bizPageLayout);
	ui->verticalLayout->setStretch(0, 72);
	ui->verticalLayout->setStretch(1, 918);


	//横向导航菜单按钮处理事件
	connect(ui->btnData, &QPushButton::clicked, this, &GBSMainBizWindow::onDataClick);
	connect(ui->btnProduct, &QPushButton::clicked, this, &GBSMainBizWindow::onProductClick);
	connect(ui->btnLive, &QPushButton::clicked, this, &GBSMainBizWindow::onLiveClick);
	connect(ui->btnTranslate, &QPushButton::clicked, this, &GBSMainBizWindow::onTranslateClick);
	connect(ui->btnSetting, &QPushButton::clicked, this, &GBSMainBizWindow::onSettingClick);
	connect(ui->btnAI, &QPushButton::clicked, this, &GBSMainBizWindow::onAIClick);



	OBSHttpClient::getInstance()->getUserInfo();
	

}

void GBSMainBizWindow::clearWidgetsFromLayout(QBoxLayout* layout) {
	QLayoutItem *child;
	while ((child = layout->takeAt(0)) != 0)
	{
		//setParent为NULL，防止删除之后界面不消失
		if(child->widget())
		{
			child->widget()->setParent(NULL);
			delete child->widget();//释放
		}

		delete child;
	}

}
void GBSMainBizWindow::onDataClick(bool checked) {
	clearWidgetsFromLayout(naviLayout);
	GBSNaviData *gbsNaviData = new GBSNaviData(this);
	naviLayout->addWidget(gbsNaviData);

	clearWidgetsFromLayout(bizLayout.data());
	GBSBizDeviceInfo* gbsDeviceInfo = new GBSBizDeviceInfo(this);
	bizLayout->addWidget(gbsDeviceInfo);

}
void GBSMainBizWindow::onProductClick(bool checked) {
	clearWidgetsFromLayout(naviLayout);
	GBSNaviProduct *gbsNaviProduct = new GBSNaviProduct(this);
	naviLayout->addWidget(gbsNaviProduct);

	clearWidgetsFromLayout(bizLayout.data());
	GBSBizSoYoung *gbsSoYoung = new GBSBizSoYoung(this);
	bizLayout->addWidget(gbsSoYoung);
}
void GBSMainBizWindow::onLiveClick(bool checked) {
	clearWidgetsFromLayout(naviLayout);
	GBSNaviLive* gbsNaviLive = new GBSNaviLive(this);
	naviLayout->addWidget(gbsNaviLive);
	clearWidgetsFromLayout(bizLayout.data());
	GBSBizLivePusher* gbsBizlivePusher = new GBSBizLivePusher(this);
	bizLayout->addWidget(gbsBizlivePusher);
	gbsNaviLive->addLayoutRef(bizLayout, gbsBizlivePusher);


}
void GBSMainBizWindow::onTranslateClick(bool checked) {
	clearWidgetsFromLayout(naviLayout);
	GBSNaviTranslate *gbsNaviTranslate = new GBSNaviTranslate(this);
	naviLayout->addWidget(gbsNaviTranslate);
	clearWidgetsFromLayout(bizLayout.data());
	GBSBizSoYoung *gbsBizSoYoung = new GBSBizSoYoung(this);
	bizLayout->addWidget(gbsBizSoYoung);
	gbsNaviTranslate->addLayoutRef(bizLayout, gbsBizSoYoung);
}
void GBSMainBizWindow::onSettingClick(bool checked) {
	clearWidgetsFromLayout(naviLayout);
	GBSNaviSetting *gbsNaviSetting = new GBSNaviSetting(this);
	naviLayout->addWidget(gbsNaviSetting);
	clearWidgetsFromLayout(bizLayout.data());
	GBSBizSettingBasic *gbsBizSettingBasic = new GBSBizSettingBasic(this);
	bizLayout->addWidget(gbsBizSettingBasic);
	gbsNaviSetting->addLayoutRef(bizLayout, gbsBizSettingBasic);


}
void GBSMainBizWindow::onAIClick(bool checked) {
	clearWidgetsFromLayout(naviLayout);
	GBSNaviAI *gbsNaviAI = new GBSNaviAI(this);
	naviLayout->addWidget(gbsNaviAI);
	clearWidgetsFromLayout(bizLayout.data());
	GBSBizSoYoung *gbsBizSoYoung = new GBSBizSoYoung(this);
	bizLayout->addWidget(gbsBizSoYoung);
	gbsNaviAI->addLayoutRef(bizLayout, gbsBizSoYoung);
}



GBSMainBizWindow::~GBSMainBizWindow()
{
	horiButtons.clear();
	vertButtons.clear();
	delete ui;
}

void GBSMainBizWindow::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Qt::Key_Up || event->key() == Qt::Key_Down) {

		if (event->key() == Qt::Key_Up) {
			currentVertButtonIndex = (currentVertButtonIndex - 1 + vertButtons.size()) % vertButtons.size();
		} else if (event->key() == Qt::Key_Down) {
			currentVertButtonIndex = (currentVertButtonIndex + 1) % vertButtons.size();
		}

		//vertButtons[currentVertButtonIndex]->click();

		QPushButton *button =vertButtons[currentVertButtonIndex];
		// 模拟按钮按下和松开的过程
		QTimer::singleShot(1000, [button]() {
			// 模拟按钮按下
			Q_EMIT button->pressed();
			button->setDown(true);  // 视觉上表现为按下
			button->repaint();

			// 0.2秒后模拟松开按钮
			QTimer::singleShot(200, [button]() {
				Q_EMIT button->released();
				button->setDown(false);  // 恢复正常状态
				button->repaint();
				Q_EMIT button->clicked();  // 模拟点击信号
			});
		});
	}
	else if (event->key() == Qt::Key_Left || event->key() == Qt::Key_Right) {

		if (event->key() == Qt::Key_Left) {
			currentHoriButtonIndex = (currentHoriButtonIndex - 1 + horiButtons.size()) % horiButtons.size();
		} else if (event->key() == Qt::Key_Right) {
			currentHoriButtonIndex = (currentHoriButtonIndex + 1) % horiButtons.size();
		}

		//horiButtons[currentHoriButtonIndex]->click();

		QPushButton *button =horiButtons[currentHoriButtonIndex];

		// 模拟按钮按下和松开的过程
		QTimer::singleShot(2000, [button]() {
			// 模拟按钮按下
			Q_EMIT button->pressed();

			button->setDown(true);  // 视觉上表现为按下
			button->repaint();

			// 0.2秒后模拟松开按钮
			QTimer::singleShot(200, [button]() {
				Q_EMIT button->released();
				button->setDown(false);  // 恢复正常状态
				button->repaint();

				Q_EMIT button->clicked();  // 模拟点击信号
			});
		});

	}


}

