#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include"recipeswindow.h"
class ImageButton: public QPushButton
{
    Q_OBJECT
public:
    ImageButton(const QString &text, const QString &imagePath, QWidget *parent = nullptr);
protected slots:
    void onClicked();
private:
    recipeswindow  *recipeswindow_ui  = nullptr;
};

#endif // IMAGEBUTTON_H
