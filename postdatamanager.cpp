#include "postdatamanager.h"
#include <QDebug>
#include <QDir>
#include <QFileInfoList>

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
            // 直接更新原对象的属性，而不是删除和替换
            posts[i]->title = post->title;
            posts[i]->type = post->type;
            posts[i]->content = post->content;
            posts[i]->pixFilename = post->pixFilename;
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

void PostDataManager::loadDraftsFromDisk()
{
    QString appDir = QCoreApplication::applicationDirPath();
    QString postsDir = appDir + "/data/posts";
    QDir dir(postsDir);
    if (!dir.exists()) {
        qDebug() << "Posts directory does not exist:" << postsDir;
        return;
    }

    QFileInfoList postDirs = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    qDebug() << "Found" << postDirs.size() << "post directories";
    for (const QFileInfo& postDirInfo : postDirs) {
        QString postDataFile = postDirInfo.absoluteFilePath() + "/post_data.txt";
        QFile file(postDataFile);
        if (file.exists()) {
            PostData* post = new PostData();
            post->postDir = postDirInfo.absoluteFilePath();
            if (post->loadPostData() && post->type == "s") {
                qDebug() << "Loaded draft:" << post->title << "with id:" << post->id;
                // 避免重复加载
                bool exists = false;
                for (auto* p : posts) {
                    if (p->id == post->id) { exists = true; break; }
                }
                if (!exists) {
                    posts.append(post);
                    qDebug() << "Added draft to posts list";
                } else {
                    qDebug() << "Draft already exists, deleting duplicate";
                    delete post;
                }
            } else {
                qDebug() << "Failed to load post data or not a draft:" << postDataFile;
                delete post;
            }
        } else {
            qDebug() << "Post data file does not exist:" << postDataFile;
        }
    }
    qDebug() << "Total drafts loaded:" << posts.size();
}
