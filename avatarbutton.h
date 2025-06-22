#ifndef AVATARBUTTON_H
#define AVATARBUTTON_H
#include<QPushButton>

class avatarbutton:public QPushButton
{
    Q_OBJECT
public:
    avatarbutton(const QString &imagePath, QWidget *parent = nullptr);
protected slots:
    void onClicked();

};

#endif // AVATARBUTTON_H
