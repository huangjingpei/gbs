#ifndef FATBUTTON_H
#define FATBUTTON_H
#include <QAbstractButton>
#include <QIcon>
#include <QPainter>
#include <QStyleOptionButton>
#include <QPushButton>
#include <QIcon>

class FatButton : public QPushButton
{
	Q_OBJECT

public:
	explicit FatButton(const QString &text, const QString &iconPath, QWidget *parent = nullptr)
		: QPushButton(parent), icon(iconPath)
	{


		setLayoutDirection(Qt::LeftToRight);
		setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
		setIconSize(QSize(24, 24));  // 设置图标大小
		setIcon(QIcon(iconPath));
		setText(text);
		setStyleSheet(
			"QPushButton {"
			"   background-color: #9CA4AB;"
			"   border: none;" // 无边框
			"   border-radius: 5px;" // 圆角
			"   font-size: 14px;"
			"   text-align: center;" // 文本居中
			"   padding-left: 10px;" // 文本靠近左侧
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
	}


protected:
	void paintEvent(QPaintEvent *event) override
	{
		// 创建按钮的样式选项
		QStyleOptionButton opt;
		initStyleOption(&opt);

		// 获取 QPainter 用于自定义绘制
		QPainter painter(this);

		// 先绘制默认的按钮样式（包括文本）
		style()->drawControl(QStyle::CE_PushButton, &opt, &painter, this);

		// 手动绘制图标，固定在距离左侧 100 像素处
		if (!icon.isNull()) {
			int iconX = 100;  // 距离左侧100像素
			int iconY = (height() - iconSize().height()) / 2;  // 垂直居中

			// 绘制图标
			painter.drawPixmap(iconX, iconY, icon.pixmap(iconSize()));
		}
	}


private:
	QIcon icon;
};

#endif //FATBUTTON_H
