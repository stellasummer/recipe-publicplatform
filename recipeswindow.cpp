#include "recipeswindow.h"
#include "ui_recipeswindow.h"
#include<QFile>
#include<QPushButton>
recipeswindow::recipeswindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::recipeswindow)
{
    ui->setupUi(this);
    QFile file3(":/assets/recipeswindow.qss");
    if(file3.open(QFile::OpenModeFlag::ReadOnly)){
        this->setStyleSheet(file3.readAll());
    }
    //向某一页插入文字
    QString filePath0="C:/Users/fujia/Desktop/recipes_pku/changeable_files/recipes.txt";
    QFile file0(filePath0);
    QString textPath;
    if(file0.open(QFile::OpenModeFlag::ReadOnly)){
        textPath=file0.readLine();
    }
    file0.close();
    QFile file2(textPath);
    if(file2.open(QFile::OpenModeFlag::ReadOnly)){
        QString sum="";
        while(!file2.atEnd()){
            QString line=file2.readLine();
            sum+=line;
        }
        ui->text->setText(sum);
    }
    //向某一页插入图片
    QString filePath="C:/Users/fujia/Desktop/recipes_pku/changeable_files/photo.txt";
    QFile file(filePath);
    QString imagePath;
    int i=0;
    if(file.open(QFile::OpenModeFlag::ReadOnly)){
        while(!file.atEnd()){
            imagePath=file.readLine().trimmed();
            if(i<=ui->stackedWidget->count()-1)
                ui->stackedWidget->setCurrentIndex(i++);
            else{
                QWidget *newPage = new QWidget();
                ui->stackedWidget->addWidget(newPage);
                ui->stackedWidget->setCurrentIndex(i++);
            }
            QWidget* p=ui->stackedWidget->currentWidget();
            QVBoxLayout *imageLayout = new QVBoxLayout(p);
            imageLayout->setContentsMargins(0, 0, 0, 0);
            QLabel *imageLabel = new QLabel();
            imageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            imageLabel->setAlignment(Qt::AlignCenter);
            QPixmap pixmap(imagePath);
            if(!pixmap.isNull()) {
                imageLabel->setPixmap(pixmap.scaledToWidth(400, Qt::SmoothTransformation));
            } else {
                imageLabel->setText("无图片");
                qWarning() << "图片加载失败:" << imagePath;
            }
            imageLayout->addWidget(imageLabel, 0, Qt::AlignHCenter);


        }
    }
    file.close();
    ui->stackedWidget->setCurrentIndex(0);
    //插入按钮
    QPushButton* prev_button=new QPushButton(ui->prev_page);
    prev_button->setText("上一页");
    prev_button->setFixedSize(60,40);
    prev_button->setStyleSheet(
        "QPushButton{"
        "border:none;"
        "background-color:rgb(156, 52, 1);"
        "   color:white;"
        "   border-radius: 5px;"
        "   padding: 8px;"
        "}"
        "QPushButton:hover { background-color:#e0e0e0; }"
        );
    connect(prev_button,&QPushButton::clicked,[=](){
        if(ui->stackedWidget->currentIndex()-1>=0){
            ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex()-1);

        }

    });
    QPushButton* next_button=new QPushButton(ui->next_page);
    next_button->setText("下一页");
    next_button->setFixedSize(60,40);
    next_button->setStyleSheet(
        "QPushButton{"
        "border:none;"
        "background-color:rgb(156, 52, 1);"
        "   color:white;"
        "   border-radius: 5px;"
        "   padding: 8px;"
        "}"
        "QPushButton:hover { background-color:#e0e0e0; }"
        );
    connect(next_button,&QPushButton::clicked,[=](){
        if(ui->stackedWidget->currentIndex()+1<=ui->stackedWidget->count()-1){
            ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex()+1);
        }

    });
}

recipeswindow::~recipeswindow()
{
    delete ui;
}
