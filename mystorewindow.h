#ifndef MYSTOREWINDOW_H
#define MYSTOREWINDOW_H

#include"userdata.h"
#include"postdata.h"
#include"postdatamanager.h"

#include <QMainWindow>

namespace Ui {
class myStoreWindow;
}

class myStoreWindow : public QMainWindow
{
    Q_OBJECT

public:
    UserData *user;
    PostDataManager *posts;
    explicit myStoreWindow(QWidget *parent = nullptr,UserData *_user=new UserData(),PostDataManager *_posts=new PostDataManager());
    ~myStoreWindow();
signals:
    void closed(); // 当窗口关闭时发送的信号

protected:
    void closeEvent(QCloseEvent *event) override; // 重写closeEvent

private:
    Ui::myStoreWindow *ui;
};

#endif // MYSTOREWINDOW_H
