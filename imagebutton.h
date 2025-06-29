#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include "postdata.h"
#include "postdatamanager.h"
#include"recipeswindow.h"

class ImageButton: public QPushButton
{
    Q_OBJECT
public:
    ImageButton(const QString &text, const QString &imagePath, PostData* post = nullptr, PostDataManager* manager = nullptr, QWidget *parent = nullptr);

signals:
    void postUpdated();

protected slots:
    void onClicked();
private:
    recipeswindow  *recipeswindow_ui  = nullptr;
    PostData* m_post;
    PostDataManager* m_postManager;
};

#endif // IMAGEBUTTON_H
