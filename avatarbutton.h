#ifndef AVATARBUTTON_H
#define AVATARBUTTON_H
#include"userdata.h"
#include<QPushButton>

class avatarbutton:public QPushButton
{
    Q_OBJECT
public:
    avatarbutton(const QString &imagePath, UserData* user,QWidget *parent = nullptr);
protected slots:

};

#endif // AVATARBUTTON_H
