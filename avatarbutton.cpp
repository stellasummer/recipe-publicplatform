#include "avatarbutton.h"
#include<QVBoxLayout>
#include<QLabel>
#include<QFileDialog>
avatarbutton::avatarbutton(const QString &imagePath, QWidget *parent): QPushButton(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(3, 3, 3, 3);
    QWidget *imageContainer = new QWidget();
    imageContainer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QVBoxLayout *imageLayout = new QVBoxLayout(imageContainer);
    imageLayout->setContentsMargins(0, 0, 0, 0);

    QLabel *imageLabel = new QLabel();
    imageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    imageLabel->setAlignment(Qt::AlignCenter);
    QPixmap pixmap(imagePath);
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
    connect(this, &QPushButton::clicked, this, &avatarbutton::onClicked);
}
void avatarbutton::onClicked() {
    // 弹出文件选择对话框
    QString path = QFileDialog::getOpenFileName(
        this,                   // 父窗口
        tr("选择文件"),         // 标题
        QDir::homePath(),       // 默认目录
        tr("所有文件 (*.*)")    // 文件过滤器
        );

    if (!path.isEmpty()) {
        QFile file("C:/Users/fujia/Desktop/recipes_pku/changeable_files/avatar.txt");
        if(file.open(QFile::OpenModeFlag::WriteOnly)){
            const char* temp=path.toStdString().c_str();
            file.write(temp);
        }
        file.close();
    }
}
