#include "recipeswindow.h"
#include "ui_recipeswindow.h"
#include<QFile>
#include<QPushButton>
#include<QMessageBox>

recipeswindow::recipeswindow(PostData* post, PostDataManager* manager, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::recipeswindow)
    , m_currentPost(post)
    , m_postManager(manager)
    , m_isCollected(false)
{
    ui->setupUi(this);
    QFile file3(":/assets/recipeswindow.qss");
    if(file3.open(QFile::OpenModeFlag::ReadOnly)){
        this->setStyleSheet(file3.readAll());
    }
    // //向某一页插入文字
    // QString filePath0="C:/Users/fujia/Desktop/recipes_pku/changeable_files/recipes.txt";
    // QFile file0(filePath0);
    // QString textPath;
    // if(file0.open(QFile::OpenModeFlag::ReadOnly)){
    //     textPath=file0.readLine();
    // }
    // file0.close();
    // QFile file2(textPath);
    // if(file2.open(QFile::OpenModeFlag::ReadOnly)){
    //     QString sum="";
    //     while(!file2.atEnd()){
    //         QString line=file2.readLine();
    //         sum+=line;
    //     }
    //     ui->text->setText(sum);
    // }
    // //向某一页插入图片
    // QString filePath="C:/Users/fujia/Desktop/recipes_pku/changeable_files/photo.txt";
    // QFile file(filePath);
    // QString imagePath;
    // int i=0;
    // if(file.open(QFile::OpenModeFlag::ReadOnly)){
    //     while(!file.atEnd()){
    //         imagePath=file.readLine().trimmed();
    //         if(i<=ui->stackedWidget->count()-1)
    //             ui->stackedWidget->setCurrentIndex(i++);
    //         else{
    //             QWidget *newPage = new QWidget();
    //             ui->stackedWidget->addWidget(newPage);
    //             ui->stackedWidget->setCurrentIndex(i++);
    //         }
    //         QWidget* p=ui->stackedWidget->currentWidget();
    //         QVBoxLayout *imageLayout = new QVBoxLayout(p);
    //         imageLayout->setContentsMargins(0, 0, 0, 0);
    //         QLabel *imageLabel = new QLabel();
    //         imageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //         imageLabel->setAlignment(Qt::AlignCenter);
    //         QPixmap pixmap(imagePath);
    //         if(!pixmap.isNull()) {
    //             imageLabel->setPixmap(pixmap.scaledToWidth(400, Qt::SmoothTransformation));
    //         } else {
    //             imageLabel->setText("无图片");
    //             qWarning() << "图片加载失败:" << imagePath;
    //         }
    //         imageLayout->addWidget(imageLabel, 0, Qt::AlignHCenter);


    //     }
    // }
    // file.close();
    // ui->stackedWidget->setCurrentIndex(0);

    // 如果有帖子数据，显示帖子内容
    if (m_currentPost && m_postManager) {
        // 显示帖子标题和内容
        QString displayText = "<h2>" + m_currentPost->title + "</h2>";
        displayText += "<p>" + m_currentPost->content + "</p>";
        ui->text->setText(displayText);
        
        // 检查是否已收藏
        m_isCollected = (m_currentPost->type == "sss");
        
        // 设置收藏按钮状态
        QPushButton* collectButton = ui->pushButton;
        if (m_isCollected) {
            collectButton->setText("取消收藏");
        } else {
            collectButton->setText("收藏");
        }
        
        // 连接收藏按钮信号
        connect(collectButton, &QPushButton::clicked, this, &recipeswindow::on_collectButton_clicked);

        // 显示所有图片
        QVector<QString> imagePaths = m_currentPost->getImagePaths();
        QStackedWidget* stack = ui->stackedWidget;
        // 先清空已有页面
        while (stack->count() > 0) {
            QWidget* w = stack->widget(0);
            stack->removeWidget(w);
            delete w;
        }
        if (imagePaths.isEmpty()) {
            QWidget* page = new QWidget();
            QVBoxLayout* layout = new QVBoxLayout(page);
            QLabel* label = new QLabel("无图片");
            label->setAlignment(Qt::AlignCenter);
            layout->addWidget(label);
            stack->addWidget(page);
        } else {
            for (const QString& path : imagePaths) {
                QWidget* page = new QWidget();
                QVBoxLayout* layout = new QVBoxLayout(page);
                QLabel* label = new QLabel();
                label->setAlignment(Qt::AlignCenter);
                QPixmap pix(path);
                if (!pix.isNull()) {
                    label->setPixmap(pix.scaled(400, 300, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                } else {
                    label->setText("图片加载失败");
                }
                layout->addWidget(label);
                stack->addWidget(page);
            }
        }
        stack->setCurrentIndex(0);
    }

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

void recipeswindow::on_collectButton_clicked()
{
    if (!m_currentPost || !m_postManager) {
        return;
    }

    QPushButton* collectButton = ui->pushButton;
    
    // 新增：如果当前是草稿，自动保存草稿内容
    if (m_currentPost->type == "s") {
        // 假设recipeswindow只读，若允许编辑可加UI同步
        m_currentPost->savePostData();
    }
    
    if (m_isCollected) {
        // 取消收藏
        m_currentPost->type = "ss";
        collectButton->setText("收藏");
        m_isCollected = false;
        QMessageBox::information(this, "成功", "已取消收藏！");
    } else {
        // 添加收藏
        m_currentPost->type = "sss";
        collectButton->setText("取消收藏");
        m_isCollected = true;
        QMessageBox::information(this, "成功", "收藏成功！");
    }

    // 保存帖子数据
    if (m_currentPost->savePostData()) {
        // 发射信号通知主窗口刷新首页
        emit postUpdated();
    } else {
        QMessageBox::warning(this, "错误", "保存失败！");
    }
}
