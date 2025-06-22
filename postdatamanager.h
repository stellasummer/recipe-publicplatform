#ifndef POSTDATAMANAGER_H
#define POSTDATAMANAGER_H

#include "postdata.h"
#include <QVector>
#include <QString>

//对post进行增加，修改，删除，筛选和搜索
class PostDataManager
{
public:
    QVector<PostData*> posts;

    PostDataManager();
    ~PostDataManager();

    // 管理操作
    void addPost(PostData* post);
    bool updatePost(PostData* post);
    bool deletePost(int postId);
    PostData* getPostById(int postId) const;
    QVector<PostData*> getAllPosts() const;
    PostData* operator [](int i);
    int size()
    {
        return posts.size();
    }
    // 筛选和搜索
    QVector<PostData*> getByType(const QString& type) const;
    QVector<PostData*> searchByTitle(const QString& keyword) const;
    QVector<PostData*> searchByContent(const QString& keyword) const;
    QVector<PostData*> searchByAll(const QString& keyword) const;

};

#endif // POSTDATAMANAGER_H
