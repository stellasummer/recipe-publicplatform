#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imagebutton.h"
#include "mystorewindow.h"
#include"createwindow.h"
#include "mystorewindow.h"
#include"designui.h"

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

    QVector<QString> dishlist{u8"番茄炒鸡蛋",u8"韭菜炒虾仁",u8"鸡蛋灌饼",u8"土豆烧牛肉",u8"水煮肉片",u8"清炒土豆丝",u8"凉拌黄瓜",u8"骨汤米线",u8"清炒油菜",u8"醪糟汤圆"};
    for(int i=0;i<10;i++)
    {
        posts.addPost(new PostData(i,dishlist[i]));
        posts[i]->addImage(":/assets/"+QString::number(i)+".png");
    }
    posts.updatePost(new PostData(0,u8"番茄炒鸡蛋","sss"));
    posts[0]->addImage(":/assets/"+QString::number(0)+".png");

    // 创建瀑布流布局
    WaterfallLayout *dishes = new WaterfallLayout();
    dishes->setSpacing(15);
    QFile file2(":/assets/dish.qss");

    QVector<PostData*> ssposts = posts.getByType("ss");
    ssposts.append(posts.getByType("sss"));
    for(int i = 0; i < ssposts.size(); i++) {
        QString pixPath = "";
        if(ssposts[i]->pixFilename.size() > 0) {
            pixPath = ssposts[i]->postDir + "/" + ssposts[i]->pixFilename[0];
        }
        ImageButton *pBtn = new ImageButton(ssposts[i]->title, pixPath);
        dishes->addWidget(pBtn);
    }

    ui->scrollArea->widget()->setLayout(dishes);

    // 安装事件过滤器监听大小变化
    ui->scrollArea->installEventFilter(this);


    // 搜索
    connect(ui->search_icon, &QPushButton::clicked, [=]() mutable {
        ui->stackedWidget->setCurrentIndex(1);

        // 清理旧布局
        QWidget* scrollWidget = ui->scrollArea_2->widget();
        QLayout* oldLayout = scrollWidget->layout();
        if (oldLayout) {
            while (QLayoutItem* item = oldLayout->takeAt(0)) {
                if (item->widget()) {
                    delete item->widget();
                }
                delete item;
            }
            delete oldLayout;
        }

        // 创建瀑布流布局
        WaterfallLayout *dishes = new WaterfallLayout(scrollWidget);
        dishes->setSpacing(15);

        // 搜索结果
        QVector<PostData*> resultposts = posts.searchByAll(ui->search_box->text());

        for(int i = 0; i < resultposts.size(); i++) {
            QString pixPath = "";
            if(resultposts[i]->pixFilename.size() > 0) {
                pixPath = resultposts[i]->postDir + "/" + resultposts[i]->pixFilename[0];
            }

            ImageButton *pBtn = new ImageButton(resultposts[i]->title, pixPath);
            pBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            dishes->addWidget(pBtn);
        }

        ui->scrollArea_2->widget()->setLayout(dishes);

        // 返回按钮
        if (return_button) {
            return_button->deleteLater();
            return_button = nullptr;
        }

        return_button = new QPushButton("返回");
        return_button->setFixedSize(60, 40);
        return_button->setStyleSheet(R"(
        QPushButton {
        border: none;
        background-color: rgb(156, 52, 1);
        color: white;
        border-radius: 5px;
        padding: 8px;
        }
        QPushButton:hover {
            background-color: #e0e0e0;
        }
    )");

        ui->bottom_frame->layout()->addWidget(return_button);

        connect(return_button, &QPushButton::clicked, [this]() {
            ui->stackedWidget->setCurrentIndex(0);
            return_button->deleteLater();
            return_button = nullptr;
        });

        // 安装事件过滤器
        ui->scrollArea_2->installEventFilter(this);
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
        mystorewindow_ui = new myStoreWindow(this,this->user,&(this->posts));
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


bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
    if (obj == ui->scrollArea_2 && event->type() == QEvent::Resize) {
        QLayout *layout = ui->scrollArea_2->widget()->layout();
        if (layout && layout->inherits("WaterfallLayout")) {
            static_cast<WaterfallLayout*>(layout)->updateLayout();
        }
    }
    return QMainWindow::eventFilter(obj, event);
}

