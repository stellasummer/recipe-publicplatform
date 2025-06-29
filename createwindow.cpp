#include "createwindow.h"
#include "ui_createwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>

static int newId = 10;
createwindow::createwindow(PostDataManager& manager, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::createwindow),
    m_postManager(manager)
{
    ui->setupUi(this);
    //
    newId += 1;
    m_currentPost = new PostData(newId, "", "s", ""); // "s" for draft
    m_currentPost->initDataDirs();
    connect(ui->pushButton_2, &QPushButton::clicked, this, &createwindow::on_saveDraftButton_clicked);
}

createwindow::~createwindow()
{
    // If the window is closed and the post was never saved,
    // it remains a draft and can be cleaned up later if necessary.
    delete ui;
}

void createwindow::on_addImageButton_clicked()
{
    QString imagePath = QFileDialog::getOpenFileName(this, tr("选择图片"), "", tr("图片文件 (*.png *.jpg *.jpeg)"));
    if (!imagePath.isEmpty()) {
        if (m_currentPost->addImage(imagePath)) {
            m_imagePaths.append(imagePath);
            // You can add a QLabel to preview the image or a QListWidget to show all image paths.
            // For simplicity, let's just show a confirmation.
            QMessageBox::information(this, "成功", "图片添加成功！");
        } else {
            QMessageBox::warning(this, "错误", "添加图片失败！");
        }
    }
}

void createwindow::on_sendButton_clicked()
{
    if (ui->titleLineEdit->text().isEmpty()) {
        QMessageBox::warning(this, "错误", "菜品名称不能为空！");
        return;
    }
    if (ui->contentPlainTextEdit->toPlainText().isEmpty()) {
        QMessageBox::warning(this, "错误", "菜品做法不能为空！");
        return;
    }

    bool wasDraft = (m_currentPost->type == "s");
    int draftId = m_currentPost->id;

    // 发布时新建一个正式PostData对象，避免复用草稿导致数据错乱
    PostData* newPost = new PostData(draftId, ui->titleLineEdit->text(), "ss", ui->contentPlainTextEdit->toPlainText());
    newPost->pixFilename = m_currentPost->pixFilename;
    newPost->postDir = m_currentPost->postDir;
    if (newPost->savePostData()) {
        if (wasDraft) {
            m_postManager.deletePost(draftId);
        }
        m_postManager.addPost(newPost);
        QMessageBox::information(this, "成功", "菜品发布成功！");
        emit postCreated();
        // 重置
        ui->titleLineEdit->clear();
        ui->contentPlainTextEdit->clear();
        m_imagePaths.clear();
        int newId = m_postManager.size();
        m_currentPost = new PostData(newId, "", "s", "");
        m_currentPost->initDataDirs();
    } else {
        QMessageBox::warning(this, "错误", "保存菜品失败！");
        m_currentPost->type = "s";
    }
}

void createwindow::on_titleLineEdit_textChanged(const QString &arg1)
{
    m_currentPost->title = arg1;
}

void createwindow::on_contentPlainTextEdit_textChanged()
{
    m_currentPost->content = ui->contentPlainTextEdit->toPlainText();
}

void createwindow::on_saveDraftButton_clicked()
{
    m_currentPost->title = ui->titleLineEdit->text();
    m_currentPost->content = ui->contentPlainTextEdit->toPlainText();
    m_currentPost->type = "s"; // 草稿

    if (m_currentPost->savePostData()) {
        // 查重
        bool exists = false;
        for (int i = 0; i < m_postManager.size(); ++i) {
            if (m_postManager[i]->id == m_currentPost->id) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            m_postManager.addPost(m_currentPost);
        }
        QMessageBox::information(this, "成功", "已保存到草稿箱！");
        // 不重置，保留内容
    } else {
        QMessageBox::warning(this, "错误", "保存草稿失败！");
    }
}

void createwindow::loadDraft(PostData* draft)
{
    if (!draft) return;
    *m_currentPost = *draft;
    ui->titleLineEdit->setText(m_currentPost->title);
    ui->contentPlainTextEdit->setPlainText(m_currentPost->content);
    // 可根据需要加载图片等
}
