#include "imagebutton.h"
#include<QFile>
#include<QLabel>
#include<QScrollArea>
#include<QScrollBar>
#include<QVector>
#include<QString>
//创建一个带有文本和图片的按钮
ImageButton::ImageButton(const QString &text, const QString &imagePath, PostData* post, PostDataManager* manager, QWidget *parent)
    : QPushButton(parent)
    , m_post(post)
    , m_postManager(manager)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(3, 3, 3, 3);
    layout->setSpacing(3);
    // 添加图片
    QWidget *imageContainer = new QWidget();
    imageContainer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QVBoxLayout *imageLayout = new QVBoxLayout(imageContainer);
    imageLayout->setContentsMargins(0, 0, 0, 0);

    QLabel *imageLabel = new QLabel();
    QPixmap pixmap(imagePath);
    if(!pixmap.isNull()) {
        // 保持宽高比缩放，限制最大高度
        imageLabel->setPixmap(pixmap.scaledToWidth(500, Qt::SmoothTransformation));
    } else {
        imageLabel->setText("无图片");
        qWarning() << "图片加载失败:" << imagePath;
    }
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLayout->addWidget(imageLabel, 0, Qt::AlignHCenter);

    // 文本区域（固定高度30%）
    QWidget *textContainer = new QWidget();
    textContainer->setFixedHeight(70); // 增加高度以容纳简介
    QVBoxLayout *textLayout = new QVBoxLayout(textContainer);
    textLayout->setContentsMargins(0, 0, 0, 0);
    QLabel *titleLabel = new QLabel(text);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 20px; color: black;");
    textLayout->addWidget(titleLabel, 0, Qt::AlignHCenter | Qt::AlignTop);
    // 新增简介
    if (post && !post->content.isEmpty()) {
        QLabel *descLabel = new QLabel(post->content.left(30) + (post->content.size() > 30 ? "..." : ""));
        descLabel->setAlignment(Qt::AlignCenter);
        descLabel->setStyleSheet("font-size: 14px; color: #666;");
        textLayout->addWidget(descLabel, 0, Qt::AlignHCenter | Qt::AlignBottom);
    }
    // 添加到主布局（设置拉伸因子）
    layout->addWidget(imageContainer, 7); // 图片占70%空间
    layout->addWidget(textContainer, 3);

    setStyleSheet( "QPushButton {"
                  "   text-align: bottom center;"
                  "   padding-bottom: 8px;"
                  "   font-size: 14px;"
                  "   border: 1px solid #ddd;"
                  "   border-radius: 8px;"
                  "   background-color: #f8f8f8;"
                  "}"
                  "QPushButton:hover {"
                  "   background-color: #e0e0e0;"
                  "}");
    setMinimumSize(60, 60);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(this, &QPushButton::clicked, this, &ImageButton::onClicked);
}
void ImageButton::onClicked() {
    if(!recipeswindow_ui){
        recipeswindow_ui = new recipeswindow(m_post, m_postManager, this);
        // 连接信号，当帖子更新后通知主窗口刷新
        connect(recipeswindow_ui, &recipeswindow::postUpdated, this, &ImageButton::postUpdated);
    }
    recipeswindow_ui -> show();
}
