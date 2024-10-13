#include "gbsnavilive.h"
#include "ui_gbsnavilive.h"
#include "../common/VertNaviButton.h"

#include "../bizWidgets/GBSBizLivePusher.h"
#include "../bizWidgets/GBSBizLiveBridger.h"
#include "../bizWidgets/GBSBizLiveDanmaku.h"
#include "../bizWidgets/GBSBizLiveGuarder.h"


GBSNaviLive::GBSNaviLive(QWidget *parent)
	: QWidget(parent),
	  ui(new Ui::GBSNaviLive)
{
	ui->setupUi(this);
	ui->imgTheme->setStyleSheet("border-image:url(:gbs/images/gbs/biz/gbs-theme-dark.png)");
	ui->imgAvator->setStyleSheet("border-image:url(:gbs/images/gbs/biz/gbs-logo.png)");
	QString naviTitle = R"(
	    <p style="font-size: 16px; text-align: center;">
		<span style="color: #9CA4AB;">远程代播</span>
	    </p>
	)";

	ui->lblNaviTitle->setText(naviTitle);


        QString welcomeMessage = R"(
            <p style="font-size: 12px; text-align: center;">
                <span style="color: black;">Hi！</span>
                <span style="color: black;">尊贵的用户</span>
            </p>
        )";
        ui->lblHelloMessage->setText(welcomeMessage);

        QString nickName = R"(
            <p style="font-size: 10px; text-align: center;">
                <span style="color: black;">hjp9221@163.com</span>
            </p>
        )";

        ui->lblNickName->setText(nickName);


	VertNaviButton* btnZBZB = new VertNaviButton("主播直播", ":gbs/images/gbs/biz/gbs-live-zbzb.png", this);
	VertNaviButton* btnDBZB = new VertNaviButton("代播直播", ":gbs/images/gbs/biz/gbs-live-dbzb.png", this);
	VertNaviButton* btnDMSZ = new VertNaviButton("弹幕设置", ":gbs/images/gbs/biz/gbs-live-dmsz.png", this);
	VertNaviButton* btnCKGL = new VertNaviButton("场控管理", ":gbs/images/gbs/biz/gbs-live-ckgl.png", this);
	btnZBZB->setFixedSize(205, 40);
	btnDBZB->setFixedSize(205, 40);
	btnDMSZ->setFixedSize(205, 40);
	btnCKGL->setFixedSize(205, 40);
	ui->verticalLayout->addWidget(btnZBZB);
	ui->verticalLayout->addWidget(btnDBZB);
	ui->verticalLayout->addWidget(btnDMSZ);
	ui->verticalLayout->addWidget(btnCKGL);
	QSpacerItem* verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
	ui->verticalLayout->addSpacerItem(verticalSpacer);

	connect(btnZBZB, &QPushButton::clicked, this,
		&GBSNaviLive::onZBZBClicked);
	connect(btnDBZB, &QPushButton::clicked, this,
		&GBSNaviLive::onDBZBClicked);
	connect(btnDMSZ, &QPushButton::clicked, this,
		&GBSNaviLive::onDMSZClicked);
	connect(btnCKGL, &QPushButton::clicked, this,
		&GBSNaviLive::onCKGLClicked);

}

void GBSNaviLive::addLayoutRef(QSharedPointer<QLayout> layout, QWidget* widget) {
	weakLayoutPtr = layout;
	currentWidgetRef = widget;
	qDebug() << "addLayoutRef debug layout ptr " << layout.data();
}


GBSNaviLive::~GBSNaviLive()
{
	delete ui;
}

void GBSNaviLive::onZBZBClicked() {

	QSharedPointer<QLayout> layout = weakLayoutPtr.toStrongRef();
	if (layout) {
		//这里是否可以使用replaceWidget ???
		layout->removeWidget(currentWidgetRef);
		delete currentWidgetRef;
		GBSBizLivePusher* gbsBizLivePusher = new GBSBizLivePusher(this);
		layout->addWidget(gbsBizLivePusher);
		currentWidgetRef = gbsBizLivePusher;

	}


}
void GBSNaviLive::onDBZBClicked() {

	QSharedPointer<QLayout> layout = weakLayoutPtr.toStrongRef();
	if (layout) {
		layout->removeWidget(currentWidgetRef);
		delete currentWidgetRef;
		GBSBizLiveBridger* gbsBizLiveBridger = new GBSBizLiveBridger(this);
		layout->addWidget(gbsBizLiveBridger);
		currentWidgetRef = gbsBizLiveBridger;
	}
}
void GBSNaviLive::onDMSZClicked() {
	QSharedPointer<QLayout> layout = weakLayoutPtr.toStrongRef();
	if (layout) {
		layout->removeWidget(currentWidgetRef);
		delete currentWidgetRef;
		GBSBizLiveDanmaku* gbsBizLiveDanmaku = new GBSBizLiveDanmaku(this);
		layout->addWidget(gbsBizLiveDanmaku);
		currentWidgetRef = gbsBizLiveDanmaku;
	}
}
void GBSNaviLive::onCKGLClicked() {
	QSharedPointer<QLayout> layout = weakLayoutPtr.toStrongRef();
	if (layout) {
		layout->removeWidget(currentWidgetRef);
		delete currentWidgetRef;
		GBSBizLiveGuarder* gbsBizLiveGuarder = new GBSBizLiveGuarder(this);
		layout->addWidget(gbsBizLiveGuarder);
		currentWidgetRef = gbsBizLiveGuarder;
	}
}
