#ifndef GBSLIVEDANMAKU_H
#define GBSLIVEDANMAKU_H

#include <QWidget>

namespace Ui {
class GBSBizLiveDanmaku;
}

class GBSBizLiveDanmaku : public QWidget {
	Q_OBJECT

public:
	explicit GBSBizLiveDanmaku(QWidget *parent = nullptr);
	~GBSBizLiveDanmaku();

private:
	Ui::GBSBizLiveDanmaku *ui;
};

#endif // GBSLIVEDANMAKU_H
