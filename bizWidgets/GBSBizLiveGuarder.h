#ifndef GBSBIZLIVEGUARDER_H
#define GBSBIZLIVEGUARDER_H

#include <QWidget>

namespace Ui {
class GBSBizLiveGuarder;
}

class GBSBizLiveGuarder : public QWidget {
	Q_OBJECT

public:
	explicit GBSBizLiveGuarder(QWidget *parent = nullptr);
	~GBSBizLiveGuarder();

private:
	Ui::GBSBizLiveGuarder *ui;
};

#endif // GBSBIZLIVEGUARDER_H
