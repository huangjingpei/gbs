#ifndef GBSBIZLIVEPUSHER_H
#define GBSBIZLIVEPUSHER_H

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QList>
#include "../common/DanmakuWidget.h"
namespace Ui {
class GBSBizLivePusher;
}

class GBSBizLivePusher : public QWidget {
	Q_OBJECT

public:
	explicit GBSBizLivePusher(QWidget *parent = nullptr);
	~GBSBizLivePusher();

public slots:
	// 添加新 widget 的槽函数
	void addNewWidget();
protected:
	void addNewWidget2(const QString &text, const QString &imagePath, const QString &text2);
private:
	Ui::GBSBizLivePusher *ui;
	QScrollArea *danmakuscrollArea;

	QVBoxLayout* danmaKuAreaLayout;

	QList<DanmakuWidget*> widgetList;
	int danmaindex;

};

#endif // GBSBIZLIVEPUSHER_H
