#include "mystorewindow.h"
#include"avatarbutton.h"
#include "ui_mystorewindow.h"
#include "userdata.h"
#include"designui.h"
#include"imagebutton.h"
#include "createwindow.h"

#include<QFile>
#include<QShortcut>
#include<QDir>
#include <QDebug>

myStoreWindow::myStoreWindow(QWidget *parent,UserData *_user,PostDataManager *_posts)
    : QMainWindow(parent),user(_user),posts(_posts)
    , ui(new Ui::myStoreWindow)
{
    posts->loadDraftsFromDisk();
    ui->setupUi(this);
    QFile file0(":/assets/mystorewindow.qss");
    if(file0.open(QFile::OpenModeFlag::ReadOnly)){
        this->setStyleSheet(file0.readAll());
    }
    file0.close();

    user->loadUserData();
    //个人头像
    QGridLayout *ava_area = new QGridLayout();
    QString avatarPath=user->userDir+"/"+user->avatarFilename;/////
    avatarbutton *pbtn=new avatarbutton(avatarPath,user,this);
    ava_area->addWidget(pbtn,0,0);
    // 设置行列拉伸权重（确保均匀分配空间）
    ava_area->setColumnStretch(0,1);
    ava_area->setRowStretch(0,1);
    ui->avatar_area->setLayout(ava_area);

    //个人信息_加载
    ui->name_edit->setPlaceholderText("请输入昵称");
    ui->intro_edit->setPlaceholderText("请输入自我介绍，按Ctrl+Enter保存");

    QString text=user->name;
    if(text!="")
        ui->name_edit->setText(text);
    text=user->intro;
    if(text!="")
        ui->intro_edit->setPlainText(text);

    //个人信息_修改:name,intro
    connect(ui->name_edit, &QLineEdit::returnPressed, [=]()
        {
            QString text=ui->name_edit->text();
            if(!text.isEmpty())
            {
                user->changeUserData(text,user->intro);
            }
            else
            {
                ui->name_edit->setPlaceholderText("必须输入字符");
            }
        }
    );

    QShortcut *saveShortcut = new QShortcut(QKeySequence("Ctrl+Return"), ui->intro_edit);

    connect(saveShortcut, &QShortcut::activated, [=]() {
            QString text=ui->intro_edit->toPlainText();

            if(!text.isEmpty()){
                user->changeUserData(user->name,text);
            }
            else{
                ui->intro_edit->setPlainText("必须输入字符");
            }
        }
    );

    //收藏
    // 清理旧布局
    QWidget* scrollWidget = ui->scrollArea->widget();
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
    QVector<PostData*> resultposts = posts->getByType("sss");

    for(int i = 0; i < resultposts.size(); i++) {
        QString pixPath = "";
        if(resultposts[i]->pixFilename.size() > 0) {
            pixPath = resultposts[i]->postDir + "/" + resultposts[i]->pixFilename[0];
        }

        ImageButton *pBtn = new ImageButton(resultposts[i]->title, pixPath, resultposts[i], posts);
        pBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        dishes->addWidget(pBtn);
    }

    ui->scrollArea->widget()->setLayout(dishes);

    //草稿箱

    // 清理旧布局
    scrollWidget = ui->scrollArea_2->widget();
    oldLayout = scrollWidget->layout();
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
    dishes = new WaterfallLayout(scrollWidget);
    dishes->setSpacing(15);

    // 搜索结果
    resultposts = posts->getByType("s");

    for(int i = 0; i < resultposts.size(); i++) {
        QString pixPath = "";
        if(resultposts[i]->pixFilename.size() > 0) {
            pixPath = resultposts[i]->postDir + "/" + resultposts[i]->pixFilename[0];
        }

        ImageButton *pBtn = new ImageButton(resultposts[i]->title, pixPath, resultposts[i], posts);
        pBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        dishes->addWidget(pBtn);

        // 新增：点击草稿，弹出编辑窗口
        connect(pBtn, &QPushButton::clicked, [=]() {
            createwindow* editWin = new createwindow(*posts, this);
            editWin->loadDraft(resultposts[i]);
            editWin->show();
        });
    }

    ui->scrollArea_2->widget()->setLayout(dishes);

    // 新增：tab切换时刷新草稿箱
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, [=](int index) {
        // 假设草稿箱tab为1
        if (ui->tabWidget->widget(index)->objectName() == "draft_box") {
            qDebug() << "Switching to draft box tab";
            posts->loadDraftsFromDisk();
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
            QVector<PostData*> resultposts = posts->getByType("s");
            qDebug() << "Found" << resultposts.size() << "drafts to display";
            for(int i = 0; i < resultposts.size(); i++) {
                QString pixPath = "";
                if(resultposts[i]->pixFilename.size() > 0) {
                    pixPath = resultposts[i]->postDir + "/" + resultposts[i]->pixFilename[0];
                }
                ImageButton *pBtn = new ImageButton(resultposts[i]->title, pixPath, resultposts[i], posts);
                pBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                dishes->addWidget(pBtn);
                connect(pBtn, &QPushButton::clicked, [=]() {
                    createwindow* editWin = new createwindow(*posts, this);
                    editWin->loadDraft(resultposts[i]);
                    editWin->show();
                });
            }
            ui->scrollArea_2->widget()->setLayout(dishes);
        }
    });
}

myStoreWindow::~myStoreWindow()
{
    delete ui;
}
void myStoreWindow::closeEvent(QCloseEvent *event)
{
    emit closed(); // 发射关闭信号
    QWidget::closeEvent(event); // 继续默认的关闭处理
}
