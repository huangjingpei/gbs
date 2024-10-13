#ifndef GBSNAVILIVE_H
#define GBSNAVILIVE_H

#include <QWidget>

#include <QLayout>
#include <QSharedPointer>
#include <QWeakPointer>




namespace Ui {
class GBSNaviLive;
}

class GBSNaviLive : public QWidget {
	Q_OBJECT

public:
	explicit GBSNaviLive(QWidget *parent = nullptr);
	~GBSNaviLive();

	void addLayoutRef(QSharedPointer<QLayout> layout, QWidget* widget);
signals:
	void singalZBZBClicked();
	void signalDBZBClicked();
	void signalDMSZClicked();
	void signalCKGLClicked();

public slots:
	void onZBZBClicked();
	void onDBZBClicked();
	void onDMSZClicked();
	void onCKGLClicked();
private:
	Ui::GBSNaviLive *ui;
	QWeakPointer<QLayout> weakLayoutPtr;
	QWidget* currentWidgetRef;
};

#endif // GBSNAVILIVE_H
