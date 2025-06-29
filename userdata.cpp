#include "userdata.h"
#include<QCryptographicHash>

UserData::UserData(QString _name,QString _intro):name(_name),intro(_intro)
{
    this->userDir=initDataDirs();
}

//建立文件夹
QString UserData::initDataDirs()
{
    QString appDir=QCoreApplication::applicationDirPath();
    QString userDir=appDir+"/data/users";

    QDir dir;
    if(!dir.exists(userDir))
    {
        dir.mkpath(userDir);
    }

    return userDir;
}

// 设置头像
bool UserData::setAvatar(const QString &imagePath)
{
    QFile sourceFile(imagePath);
    if (!sourceFile.exists()) {
        qDebug() << "头像源文件不存在:" << imagePath;
        return false;
    }

    // 生成唯一的文件名（使用哈希）
    QString fileHash = QCryptographicHash::hash(imagePath.toUtf8(), QCryptographicHash::Md5).toHex();
    QString fileExt = QFileInfo(imagePath).suffix();
    QString avatarFileName = QString("avatar_%1.%2").arg(fileHash).arg(fileExt);
    QString avatarFilePath = userDir + "/" + avatarFileName;

    // 复制文件到用户目录
    QFile destinationFile(avatarFilePath);
    if (destinationFile.exists()) {
        // 验证文件内容重复
        avatarFilename = avatarFileName;
        return changeUserData(name, intro);
    }

    if (sourceFile.copy(avatarFilePath)) {
        avatarFilename = avatarFileName;  // 只保存文件名，不保存完整路径
        // 更新用户数据文件
        return changeUserData(name, intro);
    } else {
        qDebug() << "头像复制失败:" << sourceFile.errorString();
        return false;
    }
}

// 获取头像路径
QString UserData::getAvatarPath() const
{
    if (avatarFilename.isEmpty())
        return "";

    return userDir + "/" + avatarFilename;
}

// 检查是否有头像
bool UserData::hasAvatar() const
{
    return !avatarFilename.isEmpty();
}

//个人信息_修改,格式：用户名|用户简介
bool UserData::changeUserData(QString _name,QString _intro)
{
    name=_name;
    intro=_intro;

    QString filePath=this->userDir+"/user01.txt";
    QFile file(filePath);
    if(! file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        qDebug()<<"fail to open the file"<<filePath;
        return false;
    }

    QTextStream out(&file);
    out<<this->name<<"|"<<this->intro<<"|"<< this->avatarFilename;
    file.close();
    return true;
}

//个人信息_加载
bool UserData::loadUserData()
{
    QString filePath = this->userDir+"/user01.txt";
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "用户不存在或文件读取失败:" << filePath;
        return false;
    }

    QTextStream in(&file);
    QString line = in.readLine();
    file.close();

    if (line.isEmpty()) return false;

    // 按分隔符解析数据
    QStringList parts = line.split("|");
    if (parts.size() >= 2) {
        name = parts[0];
        intro = parts[1];
        if (parts.size() >= 3)  // 检查是否有头像信息
            avatarFilename = parts[2];
        return true;
    }
    return false;
}
