#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>

#include "User.h"
using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class Settings; }
QT_END_NAMESPACE

class Settings : public QWidget {
Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings() override;

private slots:
    void closeSettings();
    void uploadProfileImage();
    void handleLogout();
    void handleDeleteProfile();
    void handleSave();
    void showPrivacy();
    void showProfileInfoForm();
    void openLinksDialog();
    bool checkOldPassword();

signals:
    void settingsClosed();

private:
    Ui::Settings *ui;
    string profileImagePath;

    void initializeUserImage(string path);
    void initializeUsername(string username);
    void initializeAbout(string about);
    void initializeEditInputs(User &user);
    void validateInputs();
};


#endif //SETTINGS_H
