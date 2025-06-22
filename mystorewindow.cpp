#include "mystorewindow.h"
#include"avatarbutton.h"
#include "ui_mystorewindow.h"
#include<QFile>
#include<QShortcut>
#include<QDir>
myStoreWindow::myStoreWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::myStoreWindow)
{
    ui->setupUi(this);
    QFile file0(":/assets/mystorewindow.qss");
    if(file0.open(QFile::OpenModeFlag::ReadOnly)){
        this->setStyleSheet(file0.readAll());
    }
    file0.close();

    QGridLayout *ava_area = new QGridLayout();
    QString filePath3="C:/Users/fujia/Desktop/recipes_pku/changeable_files/avatar.txt";
    QFile file3(filePath3);
    QString avatarPath;
    if(file3.open(QFile::OpenModeFlag::ReadOnly)){
        avatarPath=file3.readLine();
    }
    avatarbutton *pbtn=new avatarbutton(avatarPath);
    ava_area->addWidget(pbtn,0,0);
    // 设置行列拉伸权重（确保均匀分配空间）
    ava_area->setColumnStretch(0,1);
    ava_area->setRowStretch(0,1);
    ui->avatar_area->setLayout(ava_area);
    file3.close();

    ui->name_edit->setPlaceholderText("请输入昵称");
    ui->intro_edit->setPlaceholderText("请输入自我介绍，按Ctrl+Enter保存");
    QString filePath ="C:/Users/fujia/Desktop/recipes_pku/changeable_files/info.txt";
    QFile file(filePath);
    if(file.open(QFile::OpenModeFlag::ReadOnly)){
        QString text=file.readLine();
        if(text!="")
            ui->name_edit->setText(text);

    }
    file.close();
    QString filePath2 ="C:/Users/fujia/Desktop/recipes_pku/changeable_files/intro.txt";
    QFile file2(filePath2);
    if(file2.open(QFile::OpenModeFlag::ReadOnly)){
        while(!file2.atEnd()){
            QString line=file2.readLine().trimmed();;
            ui->intro_edit->appendPlainText(line);
        }
    }
    file2.close();
    connect(ui->name_edit, &QLineEdit::returnPressed, [=]() {
        QString filePath ="C:/Users/fujia/Desktop/recipes_pku/changeable_files/info.txt";
        QFile file(filePath);
        if(file.open(QFile::OpenModeFlag::WriteOnly)){
            QString text=ui->name_edit->text();
            const char* temp=text.toStdString().c_str();
            int len=strlen(temp);
            if(len>0){
                file.write(temp,len);
            }
            else{
                ui->name_edit->setPlaceholderText("必须输入字符");
            }
        }
        file.flush();
        file.close();
    });

    QShortcut *saveShortcut = new QShortcut(QKeySequence("Ctrl+Return"), ui->intro_edit);
    connect(saveShortcut, &QShortcut::activated, [=]() {
        QString filePath ="C:/Users/fujia/Desktop/recipes_pku/changeable_files/intro.txt";
        QFile file(filePath);
        if(file.open(QFile::OpenModeFlag::WriteOnly|QIODevice::Truncate)){
            QString text=ui->intro_edit->toPlainText();
            const char* temp=text.toStdString().c_str();
            int len=strlen(temp);

            if(len>0){
                file.write(temp,len);
            }
            else{
                ui->name_edit->setPlaceholderText("必须输入字符");
            }
        }
        file.flush();
        file.close();
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
