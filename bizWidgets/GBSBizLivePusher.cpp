#include "GBSBizLivePusher.h"
#include "ui_GBSBizLivePusher.h"
#include "qscrollbar.h"
#include <QGraphicsDropShadowEffect>
#include "../common/DanmakuWidget.h"


/**
QFrame边框的样式
background-color:#F9F9F9;
border: 1px solid  #FFFFFF;
border-radius: 16px;



 */

GBSBizLivePusher::GBSBizLivePusher(QWidget *parent)
	: QWidget(parent),
	  ui(new Ui::GBSBizLivePusher)
{
	ui->setupUi(this);
	danmaindex = 0;
	ui->dockWidget->setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetMovable);
	ui->dockWidget->setAllowedAreas( Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea );
	ui->dockWidget->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);

	ui->dockWidget->setStyleSheet("QDockWidget::title { background: transparent; }");


	// 创建阴影效果
	QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(4);          // 模糊半径
	shadowEffect->setOffset(0, 10);          // 偏移 (水平 0px, 垂直 10px)
	shadowEffect->setColor(QColor(12, 12, 12));  // 阴影颜色 #0C0C0C
	ui->lblPreview->setGraphicsEffect(shadowEffect);


	// 初始化布局
	danmaKuAreaLayout = new QVBoxLayout();
	danmaKuAreaLayout->setSpacing(6);  // 设置widget之间的固定间距为6像素
	danmaKuAreaLayout->setAlignment(Qt::AlignBottom);  // 保证最新widget在最底部

	QWidget *containerWidget = new QWidget();  // 用于容纳所有widgets
	// 为containerWidget设置一个类名
	containerWidget->setObjectName("ContainerWidget");
	qApp->setStyleSheet("#ContainerWidget {"
			    "   border: 2px solid blue;"
			    "   border-radius: 5px;"
			    "}");

	containerWidget->setLayout(danmaKuAreaLayout);

	// ScrollArea 包裹 widgets 的容器
	danmakuscrollArea = new QScrollArea(this);
	danmakuscrollArea->setWidget(containerWidget);
	danmakuscrollArea->setWidgetResizable(true);
	danmakuscrollArea->setStyleSheet(
		"QScrollArea { border: none; }"
		"QScrollBar:vertical { width: 10px; }"  // 调整垂直滚动条的宽度
		"QScrollBar::handle:vertical { background: #CCCCCC; }"  // 滚动条手柄颜色
		);

	ui->verticalLayout->addWidget(danmakuscrollArea);

	ui->btnAgainstRule->setStyleSheet("border-image:url(:gbs/images/gbs/biz/gbs-widget-docking.png)");

	ui->butStartLive->setStyleSheet("border-image:url(:gbs/images/gbs/biz/gbs-start-living.png)");


	// 添加按钮来添加新 widget
	QPushButton *addButton = new QPushButton("弹幕测试", this);
	connect(addButton, &QPushButton::clicked, this, &GBSBizLivePusher::addNewWidget);
	ui->verticalLayout->addWidget(addButton);

	ui->lblPreview->setStyleSheet(
		"QLabel {"
		"   background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, "
		"       stop:0 #000000, stop:0.525 #434343, stop:1 #000000);"  // 渐变背景
		"   border-radius: 20px;"  // 圆角20px
		"   color: white;"  // 文本颜色
		"   font-size: 16px;"  // 字体大小
		"   padding: 10px;"  // 内边距
		"}"
		);




}


void GBSBizLivePusher::addNewWidget() {
	++danmaindex;
	QString text = "这是动态设置的第" + QString::number(danmaindex) + "行文本";
	addNewWidget2(text, ":gbs/images/gbs/biz/gbs-logo-douyin.png", "文本会自动换行以适应窗口宽度。我这里就需要看到你换行,这是动态设置的第二行文本。文本会自动换行以适应窗口宽度。我这里就需要看到你换行");

}

void GBSBizLivePusher::addNewWidget2(const QString &text, const QString &imagePath, const QString &text2)
{
	// 创建新 widget
	DanmakuWidget *newWidget = new DanmakuWidget(this);
	newWidget->setFirstRowContent(text, imagePath);
	newWidget->setSecondRowContent(text2);

	// 添加到布局
	widgetList.append(newWidget);

	// 插入到布局的最底部
	danmaKuAreaLayout->insertWidget(danmaKuAreaLayout->count(), newWidget);  // 最新的 widget 添加到布局的最后
	qDebug() << "danmaKuAreaLayout count " << danmaKuAreaLayout->count();

	// 滚动到最底部显示最新添加的widget
	QScrollBar *vScrollBar = danmakuscrollArea->verticalScrollBar();
	vScrollBar->setValue(vScrollBar->maximum());

	// 检查是否超过 50 个 widget
	if (widgetList.size() > 30) {
		// 移除最早的 widget
		DanmakuWidget *oldestWidget = widgetList.takeFirst();
		danmaKuAreaLayout->removeWidget(oldestWidget);
		delete oldestWidget;
	}
}

GBSBizLivePusher::~GBSBizLivePusher()
{
	delete ui;
}
