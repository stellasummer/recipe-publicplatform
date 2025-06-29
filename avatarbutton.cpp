#include "avatarbutton.h"
#include<QVBoxLayout>
#include<QLabel>
#include<QFileDialog>
//接受图片路径、指向userdata的指针、父窗口部件
avatarbutton::avatarbutton(const QString &imagePath, UserData* user,QWidget *parent): QPushButton(parent) {

    QVBoxLayout *layout = new QVBoxLayout(this);//设置一个垂直布局
    layout->setContentsMargins(3, 3, 3, 3);
    QWidget *imageContainer = new QWidget();//image container用于容纳图片。widget是窗口基类
    imageContainer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QVBoxLayout *imageLayout = new QVBoxLayout(imageContainer);//为image container设置垂直布局
    imageLayout->setContentsMargins(0, 0, 0, 0);

    QLabel *imageLabel = new QLabel();//Qlabel是widget的子类，用于显示文本或图片
    imageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);//大小策略
    imageLabel->setAlignment(Qt::AlignCenter);//缩放方式
    QPixmap pixmap(imagePath);//Pixmap用于处理图片
    if(!pixmap.isNull()) {
        // 保持宽高比缩放，限制最大高度
        imageLabel->setPixmap(pixmap.scaledToWidth(200, Qt::SmoothTransformation));
    } else {
        imageLabel->setText("无图片");
        qWarning() << "图片加载失败:" << imagePath;
    }

    imageLayout->addWidget(imageLabel, 0, Qt::AlignHCenter);
    layout->addWidget(imageContainer);
    setStyleSheet( "QPushButton {"
                  "   border: 1px solid #ddd;"
                  "   border-radius: 8px;"
                  "   background-color: #f8f8f8;"
                  "}"
                  "QPushButton:hover {"
                  "   background-color: #e0e0e0;"
                  "}");
    setMinimumSize(60, 60);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //处理点击事件
    connect(this, &QPushButton::clicked, this, [=]
    {
        // 弹出文件选择对话框
        QString path = QFileDialog::getOpenFileName(
            this,                   // 父窗口
            tr("选择文件"),         // 标题
            QDir::homePath(),       // 默认目录
            tr("所有文件 (*.*)")    // 文件过滤器
            );
        user->setAvatar(path);
        QString imagePath=user->userDir+"/"+user->avatarFilename;
        QPixmap pixmap(imagePath);
        if(!pixmap.isNull()) {
            // 保持宽高比缩放，限制最大高度
            imageLabel->setPixmap(pixmap.scaledToWidth(200, Qt::SmoothTransformation));
        } else {
            imageLabel->setText("无图片");
            qWarning() << "图片加载失败:" << imagePath;
        }
    });
}
