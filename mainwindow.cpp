#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imagebutton.h"
#include "mystorewindow.h"
#include"createwindow.h"
#include "mystorewindow.h"
#include<QFile>
#include<QLabel>
#include<QScrollArea>
#include<QScrollBar>
#include<QVector>
#include<QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->search_box->setPlaceholderText("请输入要搜索的菜品名称");
    //基本界面
    QFile file(":/assets/mainwindow.qss");
    if(file.open(QFile::OpenModeFlag::ReadOnly)){
        this->setStyleSheet(file.readAll());
    }
    //首页菜品
    QGridLayout *dishes = new QGridLayout();
    dishes->setSpacing(15);
    QVector<QString> dishlist{u8"番茄炒鸡蛋",u8"韭菜炒虾仁",u8"鸡蛋灌饼",u8"土豆烧牛肉",u8"水煮肉片",u8"清炒土豆丝"
    ,u8"凉拌黄瓜",u8"骨汤米线",u8"清炒油菜",u8"醪糟汤圆"};
    int columns = 2;
    QFile file2(":/assets/dish.qss");
    for(int i = 0; i < 10; i++) {
        ImageButton *pBtn = new ImageButton(dishlist[i],":/assets/"+QString::number(i)+".png");
        // 计算行和列的位置
        int row = i / columns;
        int col = i % columns;
        dishes->addWidget(pBtn, row, col);
        // 设置行列拉伸权重（确保均匀分配空间）
        dishes->setRowStretch(row, 1);
        dishes->setColumnStretch(col, 1);
    }
    ui->scrollArea->widget()->setLayout(dishes);//把布局放置到QScrollArea的内部QWidget中
    //返回键
    connect(ui->search_icon, &QPushButton::clicked, [=]() {
        ui->stackedWidget->setCurrentIndex(1);
        if(!this->return_button){
            QPushButton* return_button=new QPushButton();
            this->return_button=return_button;
            return_button->setText("返回");
            return_button->setFixedSize(60,40);
            return_button->setStyleSheet(
            "QPushButton{"
            "border:none;"
            "background-color:rgb(156, 52, 1);"
            "   color:white;"
            "   border-radius: 5px;"
            "   padding: 8px;"
            "}"
            "QPushButton:hover { background-color:#e0e0e0; }"
            );
            ui->bottom_frame->layout()->addWidget(return_button);
            connect(return_button,&QPushButton::clicked,[=](){
                ui->stackedWidget->setCurrentIndex(0);
                return_button->deleteLater();
            });
        }
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
//我的按钮
void MainWindow::on_mystore_clicked()
{
    if(!mystorewindow_ui)
    {
        this->setEnabled(false);//禁用主窗口
        mystorewindow_ui = new myStoreWindow(this);
        connect(mystorewindow_ui, &myStoreWindow::closed,this,&MainWindow::mystorewindow_close); //连接主窗口close信号到主窗口槽函数
        mystorewindow_ui -> show();
    }

}
void MainWindow::mystorewindow_close()//当子窗口关闭时，将指针置空并启用主窗口
{
    mystorewindow_ui = nullptr;
    this->setEnabled(true);
}

void MainWindow::on_create_recipes_clicked()
{
    createwindow* createwindow_ui=new createwindow(this);
    createwindow_ui->show();
    QFile file(":/assets/createwindow.qss");
    if(file.open(QFile::OpenModeFlag::ReadOnly)){
        createwindow_ui->setStyleSheet(file.readAll());
    }
}

