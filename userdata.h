#ifndef USERDATE_H
#define USERDATE_H

#include<QFile>
#include<QDir>
#include<QDebug>
#include<QString>
#include<QCoreApplication>

class UserData
{ 
public:
    QString name,intro;
    QString avatarFilename; //头像文件名
    QString userDir;//user文件夹路径

    UserData(QString _name="",QString _intro="");
    ~UserData(){}

    QString initDataDirs();
    bool changeUserData(QString _name="",QString _intro="");
    bool loadUserData();

    // 头像相关方法
    bool setAvatar(const QString &imagePath);
    QString getAvatarPath() const;
    bool hasAvatar() const;

};

#endif // USERDATE_H
