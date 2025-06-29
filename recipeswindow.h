#ifndef RECIPESWINDOW_H
#define RECIPESWINDOW_H

#include <QMainWindow>
#include "postdata.h"
#include "postdatamanager.h"

namespace Ui {
class recipeswindow;
}

class recipeswindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit recipeswindow(PostData* post = nullptr, PostDataManager* manager = nullptr, QWidget *parent = nullptr);
    ~recipeswindow();

signals:
    void postUpdated(); // 新增：帖子更新信号

private slots:
    void on_collectButton_clicked(); // 新增：收藏按钮点击事件

private:
    Ui::recipeswindow *ui;
    PostData* m_currentPost; // 新增：当前显示的帖子
    PostDataManager* m_postManager; // 新增：帖子管理器
    bool m_isCollected; // 新增：是否已收藏
};

#endif // RECIPESWINDOW_H
