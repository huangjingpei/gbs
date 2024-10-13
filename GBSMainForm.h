#ifndef GBSMAINFORM_H
#define GBSMAINFORM_H

#include <QWidget>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include "GBSNormalLoginForm.h"
#include "GBSRegisterForm.h"
#include "GBSAuthorizedCodeForm.h"
#include "GBSQRCodeLoginForm.h"
#include "window-main.hpp"



namespace Ui {
class GBSMainForm;
}

class GBSMainForm : public OBSMainWindow {

    Q_OBJECT
private:
	enum LoginType {
		NORMAL_LOGIN,
		AUTHORIZED_LOGIN,
		QRCODE_LOGIN
	};
	void initLoginPanel(LoginType type);
	void initEmailLogin();
	void initPasswordLogin();
	void initQRCodeLogin();
public:
    explicit GBSMainForm(QWidget *parent = nullptr);
    ~GBSMainForm();
    void setMainWindow(QMainWindow *window);

signals:
    void signalDestroyLoginWindow();

public slots:
        void slotDestroyLoginWindow();
        void onLinkActivated(const QString &link);
        void onLoginTypeChanged(int type);
private slots:
    void on_btnLoginAccount_clicked();

    private:
    Ui::GBSMainForm *ui;
    QMainWindow *mainWindow;
    QVBoxLayout *loginBizLayout;
    GBSNormalLoginForm* normalLoginForm;
    GBSRegisterForm* registerForm;
    GBSAuthorizedCodeForm* authorizedCodeForm;
    GBSQRCodeLoginForm* scanQRcodeForm;
    QWidget* currentFrom;
    LoginType currentLoginType;

    QLabel* leftImage;

public:

// 通过 OBSMainWindow 继承
    config_t *Config() const override;
    void OBSInit() override;
    int GetProfilePath(char *path, size_t size,
		       const char *file) const override;

};

#endif // GBSMAINFORM_H
