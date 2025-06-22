#include "postdatamanager.h"
#include <QDebug>

PostDataManager::PostDataManager()
{
}

PostDataManager::~PostDataManager()
{
    // 清理所有动态分配的PostData对象
    qDeleteAll(posts);
    posts.clear();
}

void PostDataManager::addPost(PostData* post)
{
    posts.append(post);
}

bool PostDataManager::updatePost(PostData* post)
{
    for (int i = 0; i < posts.size(); ++i) {
        if (posts[i]->id == post->id) {
            // 更新内存中的对象
            delete posts[i];
            posts[i] = post;
            return true;
        }
    }
    return false; // 未找到对应ID的帖子
}

bool PostDataManager::deletePost(int postId)
{
    for (int i = 0; i < posts.size(); ++i) {
        if (posts[i]->id == postId) {
            delete posts[i]; // 删除动态分配的对象
            posts.remove(i);
            return true;
        }
    }
    return false; // 未找到对应ID的帖子
}

PostData* PostDataManager::getPostById(int postId) const
{
    for (PostData* post : posts) {
        if (post->id == postId) {
            return post;
        }
    }
    return nullptr; // 未找到
}

QVector<PostData*> PostDataManager::getAllPosts() const
{
    return posts;
}
PostData* PostDataManager::operator [](int i)
{
    return posts[i];
}

QVector<PostData*> PostDataManager::getByType(const QString& type) const
{
    QVector<PostData*> result;
    for (PostData* post : posts) {
        if (post->type == type) {
            result.append(post);
        }
    }
    return result;
}

QVector<PostData*> PostDataManager::searchByTitle(const QString& keyword) const
{
    QVector<PostData*> result;
    for (PostData* post : posts) {
        if (post->title.contains(keyword, Qt::CaseInsensitive)) {
            result.append(post);
        }
    }
    return result;
}

QVector<PostData*> PostDataManager::searchByContent(const QString& keyword) const
{
    QVector<PostData*> result;
    for (PostData* post : posts) {
        if (post->content.contains(keyword, Qt::CaseInsensitive)) {
            result.append(post);
        }
    }
    return result;
}

QVector<PostData*> PostDataManager::searchByAll(const QString& keyword) const
{
    QVector<PostData*> result;
    for (PostData* post : posts) {
        if (post->title.contains(keyword, Qt::CaseInsensitive) ||
            post->content.contains(keyword, Qt::CaseInsensitive)) {
            result.append(post);
        }
    }
    return result;
}
