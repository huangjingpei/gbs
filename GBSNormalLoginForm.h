#ifndef GBSNORMALLOGINFORM_H
#define GBSNORMALLOGINFORM_H

#include <QWidget>


namespace Ui {
class GBSNormalLoginForm;
}

class GBSNormalLoginForm : public QWidget {
	Q_OBJECT

public:
	explicit GBSNormalLoginForm(QWidget *parent = nullptr);
	~GBSNormalLoginForm();
signals:
	void linkActivated(QString link);
	void loginTypeChanged(int type);
	void closeLoginWindow();

private slots:
	void onLinkActivated(const QString &link);
	void onLoginTypeChanged(int type);
	void onQRcodeLogin();
	void onAuthorizedLogin();
	void onPasswordForgot();
	void onLoginGBS();
private:
	Ui::GBSNormalLoginForm *ui;

};

#endif // GBSNORMALLOGINFORM_H
