/********************************************************************************
** Form generated from reading UI file 'recipeswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECIPESWINDOW_H
#define UI_RECIPESWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_recipeswindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QWidget *prev_page;
    QSpacerItem *verticalSpacer;
    QScrollArea *scrollArea;
    QWidget *text_area;
    QGridLayout *gridLayout_3;
    QLabel *text;
    QWidget *next_page;
    QSpacerItem *verticalSpacer_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QPushButton *pushButton;

    void setupUi(QMainWindow *recipeswindow)
    {
        if (recipeswindow->objectName().isEmpty())
            recipeswindow->setObjectName("recipeswindow");
        recipeswindow->resize(800, 600);
        centralwidget = new QWidget(recipeswindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        prev_page = new QWidget(centralwidget);
        prev_page->setObjectName("prev_page");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(prev_page->sizePolicy().hasHeightForWidth());
        prev_page->setSizePolicy(sizePolicy);
        prev_page->setMinimumSize(QSize(60, 40));

        gridLayout->addWidget(prev_page, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 200, QSizePolicy::Policy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        text_area = new QWidget();
        text_area->setObjectName("text_area");
        text_area->setGeometry(QRect(0, 0, 629, 2000));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(text_area->sizePolicy().hasHeightForWidth());
        text_area->setSizePolicy(sizePolicy1);
        text_area->setMinimumSize(QSize(0, 2000));
        gridLayout_3 = new QGridLayout(text_area);
        gridLayout_3->setObjectName("gridLayout_3");
        text = new QLabel(text_area);
        text->setObjectName("text");
        text->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        gridLayout_3->addWidget(text, 0, 0, 1, 1);

        scrollArea->setWidget(text_area);

        gridLayout->addWidget(scrollArea, 1, 1, 1, 1);

        next_page = new QWidget(centralwidget);
        next_page->setObjectName("next_page");
        sizePolicy.setHeightForWidth(next_page->sizePolicy().hasHeightForWidth());
        next_page->setSizePolicy(sizePolicy);
        next_page->setMinimumSize(QSize(60, 40));

        gridLayout->addWidget(next_page, 2, 3, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 200, QSizePolicy::Policy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer_2, 1, 3, 1, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy2);
        stackedWidget->setMinimumSize(QSize(505, 350));
        page = new QWidget();
        page->setObjectName("page");
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        gridLayout->addWidget(stackedWidget, 0, 1, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMaximumSize(QSize(60, 40));

        gridLayout->addWidget(pushButton, 2, 1, 1, 1, Qt::AlignmentFlag::AlignRight);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        recipeswindow->setCentralWidget(centralwidget);

        retranslateUi(recipeswindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(recipeswindow);
    } // setupUi

    void retranslateUi(QMainWindow *recipeswindow)
    {
        recipeswindow->setWindowTitle(QCoreApplication::translate("recipeswindow", "MainWindow", nullptr));
        text->setText(QCoreApplication::translate("recipeswindow", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("recipeswindow", "\346\224\266\350\227\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class recipeswindow: public Ui_recipeswindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECIPESWINDOW_H
