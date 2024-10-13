#ifndef GBSBizDeviceInfo_H
#define GBSBizDeviceInfo_H

#include <QWidget>

namespace Ui {
class GBSBizDeviceInfo;
}

class GBSBizDeviceInfo : public QWidget {
	Q_OBJECT

public:
	explicit GBSBizDeviceInfo(QWidget *parent = nullptr);
	~GBSBizDeviceInfo();

private:
	Ui::GBSBizDeviceInfo *ui;
};

#endif // GBSBizDeviceInfo_H
