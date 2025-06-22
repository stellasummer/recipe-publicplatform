#ifndef POSTSDATA_H
#define POSTSDATA_H
#include<QString>
#include<QVector>
#include<QCoreApplication>
#include<QFile>
#include<QDebug>
#include<QDir>

//储存单个post的信息
class PostData
{
public:
    int id;
    QString title;
    QString type;//区分收藏、普通内容和草稿,规则：s:草稿，ss：普通，sss：收藏
    QString content;
    QString postDir;//post文件夹路径
    QVector<QString> pixFilename;//post图片名称

    PostData(int _id = -1, QString _title = "", QString _type = "ss", QString _content = "");

    // 建立文件夹
    QString initDataDirs();

    // 图片管理
    bool addImage(const QString &imagePath);
    bool removeImage(const QString &imageFileName);
    QVector<QString> getImagePaths() const;
    int imageCount() const;

    // 数据操作
    bool savePostData();
    bool loadPostData();




};


#endif // POSTSDATA_H
