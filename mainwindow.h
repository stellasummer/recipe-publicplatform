#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ui_mainwindow.h"
#include"mystorewindow.h"
#include"createwindow.h"
#include "userdata.h"
#include "postdata.h"
#include "postdatamanager.h"
#include"postdatamanager.h"
#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    UserData *user=new UserData();
    PostDataManager posts;//储存了所有信息
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void on_mystore_clicked();
    void mystorewindow_close();
    void on_create_recipes_clicked();
    void refreshHomePage();

private:
    Ui::MainWindow *ui;
    myStoreWindow  *mystorewindow_ui  = nullptr;
    QPushButton* return_button=nullptr;
    createwindow* createwindow_ui = nullptr;

};
#endif // MAINWINDOW_H
