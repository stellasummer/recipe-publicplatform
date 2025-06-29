#ifndef CREATEWINDOW_H
#define CREATEWINDOW_H

#include <QMainWindow>
#include "postdata.h"
#include "postdatamanager.h"

namespace Ui {
class createwindow;
}

class createwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit createwindow(PostDataManager& manager, QWidget *parent = nullptr);
    ~createwindow();
    void loadDraft(PostData* draft);

signals:
    void postCreated();

private slots:
    void on_addImageButton_clicked();
    void on_sendButton_clicked();
    void on_titleLineEdit_textChanged(const QString &arg1);
    void on_contentPlainTextEdit_textChanged();
    void on_saveDraftButton_clicked();

private:
    Ui::createwindow *ui;
    PostData *m_currentPost;
    PostDataManager& m_postManager;
    QStringList m_imagePaths;
};

#endif // CREATEWINDOW_H
