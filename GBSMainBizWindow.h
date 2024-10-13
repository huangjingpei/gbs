#ifndef GBSMAINBIZWINDOW_H
#define GBSMAINBIZWINDOW_H

#include <QWidget>
#include <QKeyEvent>
#include <QList>
#include <QPushButton>
#include <QBoxLayout>
#include <QHBoxLayout>
#include <QSharedPointer>
#include <QWeakPointer>
namespace Ui {
class GBSMainBizWindow;
}

class GBSMainBizWindow : public QWidget {
	Q_OBJECT

public:
	explicit GBSMainBizWindow(QWidget *parent = nullptr);
	~GBSMainBizWindow();

protected:
	void keyPressEvent(QKeyEvent *event) override;

public slots:
	void onDataClick(bool checked = false);
	void onProductClick(bool checked = false);
	void onLiveClick(bool checked = false);
	void onTranslateClick(bool checked = false);
	void onSettingClick(bool checked = false);
	void onAIClick(bool checked = false);

private:
	void clearWidgetsFromLayout(QBoxLayout* layout);

private:
	Ui::GBSMainBizWindow *ui;

	QList<QPushButton*> horiButtons;
	QList<QPushButton*> vertButtons;
	int currentHoriButtonIndex;
	int currentVertButtonIndex;
	QHBoxLayout* naviLayout;
	//QHBoxLayout* bizLayout;
	QSharedPointer<QHBoxLayout> bizLayout;

};

#endif // GBSMAINBIZWINDOW_H
