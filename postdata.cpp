#include "postdata.h"
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <QCryptographicHash>
#include <QDateTime>
#include <QDebug>

PostData::PostData(int _id, QString _title, QString _type, QString _content)
    : id(_id), title(_title), type(_type), content(_content)
{
    this->postDir = initDataDirs();
    if (id == -1) {
        this->id = QDateTime::currentMSecsSinceEpoch() % 1000000;
    }
}

QString PostData::initDataDirs()
{
    QString appDir = QCoreApplication::applicationDirPath();
    QString postDir = appDir + "/data/posts/post_" + QString::number(id);

    QDir dir;
    if (!dir.exists(postDir))
    {
        dir.mkpath(postDir);
    }

    return postDir;
}

bool PostData::addImage(const QString &imagePath)
{
    QFile sourceFile(imagePath);
    if (!sourceFile.exists()) {
        qDebug() << "图片源文件不存在:" << imagePath;
        return false;
    }

    QString fileHash = QCryptographicHash::hash(imagePath.toUtf8(), QCryptographicHash::Md5).toHex();
    QString fileExt = QFileInfo(imagePath).suffix();
    QString imageFileName = QString("image_%1.%2").arg(fileHash).arg(fileExt);
    QString imageFilePath = postDir + "/" + imageFileName;

    QFile destinationFile(imageFilePath);
    if (!destinationFile.exists()) {
        if (!sourceFile.copy(imageFilePath)) {
            qDebug() << "图片复制失败:" << sourceFile.errorString();
            return false;
        }
    }

    pixFilename.append(imageFileName);
    return savePostData();
}

bool PostData::removeImage(const QString &imageFileName)
{
    if (!pixFilename.contains(imageFileName)) {
        return false;
    }

    pixFilename.removeOne(imageFileName);
    QFile file(postDir + "/" + imageFileName);
    file.remove();

    return savePostData();
}

QVector<QString> PostData::getImagePaths() const
{
    QVector<QString> paths;
    for (const QString &filename : pixFilename) {
        paths.append(postDir + "/" + filename);
    }
    return paths;
}

int PostData::imageCount() const
{
    return pixFilename.size();
}

bool PostData::savePostData()
{
    QString filePath = this->postDir + "/post_data.txt";
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "无法打开文件" << filePath;
        return false;
    }

    QTextStream out(&file);
    out << this->id << "|"
        << this->title << "|"
        << this->type << "|"
        << this->content << "|";

    out << this->pixFilename.join(",");
    file.close();
    return true;
}

bool PostData::loadPostData()
{
    QString filePath = this->postDir + "/post_data.txt";
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "帖子不存在或文件读取失败:" << filePath;
        return false;
    }

    QTextStream in(&file);
    QString line = in.readLine();
    file.close();

    if (line.isEmpty()) return false;

    QStringList parts = line.split("|");
    if (parts.size() >= 4) {
        id = parts[0].toInt();
        title = parts[1];
        type = parts[2];
        content = parts[3];

        pixFilename.clear();
        if (parts.size() >= 5 && !parts[4].isEmpty()) {
            QStringList imageList = parts[4].split(",");
            for (const QString &image : imageList) {
                pixFilename.append(image);
            }
        }
        return true;
    }
    return false;
}
