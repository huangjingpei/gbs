#include "gbsnavisetting.h"
#include "ui_gbsnavisetting.h"

#include "../common/VertNaviButton.h"
#include "../bizWidgets/GBSBizSettingBasic.h"
#include "../bizWidgets/GBSBizSettingOutput.h"
#include "../bizWidgets/GBSBizSettingAV.h"


GBSNaviSetting::GBSNaviSetting(QWidget *parent)
	: QWidget(parent),
	  ui(new Ui::GBSNaviSetting)
{
	ui->setupUi(this);
	ui->imgTheme->setStyleSheet("border-image:url(:gbs/images/gbs/biz/gbs-theme-dark.png)");
	ui->imgAvator->setStyleSheet("border-image:url(:gbs/images/gbs/biz/gbs-logo.png)");
	QString naviTitle = R"(
	    <p style="font-size: 16px; text-align: center;">
		<span style="color: #9CA4AB;">直播设置</span>
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


	VertNaviButton* btnBasic = new VertNaviButton("基础设置", ":gbs/images/gbs/biz/gbs-setting-basic.png", this);
	VertNaviButton* btnOutput = new VertNaviButton("直播输出", ":gbs/images/gbs/biz/gbs-setting-output.png", this);
	VertNaviButton* btnAV = new VertNaviButton("音视频", ":gbs/images/gbs/biz/gbs-setting-av.png", this);
	btnBasic->setFixedSize(205, 40);
	btnOutput->setFixedSize(205, 40);
	btnAV->setFixedSize(205, 40);

	ui->verticalLayout->addWidget(btnBasic);
	ui->verticalLayout->addWidget(btnOutput);
	ui->verticalLayout->addWidget(btnAV);

	QSpacerItem* verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
	ui->verticalLayout->addSpacerItem(verticalSpacer);

	ui->lblNickName->setText(nickName);

	connect(btnBasic, &QPushButton::clicked, this, &GBSNaviSetting::onBaiscClick);
	connect(btnOutput, &QPushButton::clicked, this, &GBSNaviSetting::onOutputClick);
	connect(btnAV, &QPushButton::clicked, this, &GBSNaviSetting::onAVClick);


}

GBSNaviSetting::~GBSNaviSetting()
{
	delete ui;
}

void GBSNaviSetting::addLayoutRef(QSharedPointer<QLayout> layout, QWidget* widget) {
	weakLayoutPtr = layout;
	currentWidgetRef = widget;
}


void GBSNaviSetting::onBaiscClick() {

	QSharedPointer<QLayout> layout = weakLayoutPtr.toStrongRef();
	if (layout) {
//这里是否可以使用replaceWidget ???
		layout->removeWidget(currentWidgetRef);
		delete currentWidgetRef;
		GBSBizSettingBasic* gbsBizSettingBasic = new GBSBizSettingBasic(this);
		layout->addWidget(gbsBizSettingBasic);
		currentWidgetRef = gbsBizSettingBasic;
	}
}
void GBSNaviSetting::onOutputClick()
{
	QSharedPointer<QLayout> layout = weakLayoutPtr.toStrongRef();
	if (layout) {


		layout->removeWidget(currentWidgetRef);
		delete currentWidgetRef;

		GBSBizSettingOutput* gbsBizSettingOutput = new GBSBizSettingOutput(this);
		layout->addWidget(gbsBizSettingOutput);
		currentWidgetRef = gbsBizSettingOutput;

	}
}
void GBSNaviSetting::onAVClick() {
	QSharedPointer<QLayout> layout = weakLayoutPtr.toStrongRef();
	if (layout) {

		layout->removeWidget(currentWidgetRef);
		delete currentWidgetRef;
		GBSBizSettingAV* gbsBizSettingAV = new GBSBizSettingAV(this);
		layout->addWidget(gbsBizSettingAV);
		currentWidgetRef = gbsBizSettingAV;



	}
}
