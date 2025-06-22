/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QFrame *top_frame;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_13;
    QLabel *logo;
    QSpacerItem *horizontalSpacer_14;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_13;
    QLineEdit *search_box;
    QPushButton *search_icon;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *mystore;
    QSpacerItem *horizontalSpacer_16;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *dish_list;
    QWidget *page_2;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea_2;
    QWidget *search_results;
    QFrame *bottom_frame;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *create_recipes;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(842, 610);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        top_frame = new QFrame(centralwidget);
        top_frame->setObjectName("top_frame");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(top_frame->sizePolicy().hasHeightForWidth());
        top_frame->setSizePolicy(sizePolicy1);
        top_frame->setMinimumSize(QSize(0, 50));
        top_frame->setMaximumSize(QSize(16777215, 50));
        top_frame->setFrameShape(QFrame::StyledPanel);
        top_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_9 = new QHBoxLayout(top_frame);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(-1, -1, -1, 0);
        horizontalSpacer_13 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_13);

        logo = new QLabel(top_frame);
        logo->setObjectName("logo");
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(logo->sizePolicy().hasHeightForWidth());
        logo->setSizePolicy(sizePolicy2);
        logo->setMinimumSize(QSize(130, 40));
        logo->setMaximumSize(QSize(60, 40));

        horizontalLayout_10->addWidget(logo);

        horizontalSpacer_14 = new QSpacerItem(200, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_14);

        widget_4 = new QWidget(top_frame);
        widget_4->setObjectName("widget_4");
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy3);
        widget_4->setMinimumSize(QSize(300, 40));
        horizontalLayout_13 = new QHBoxLayout(widget_4);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        search_box = new QLineEdit(widget_4);
        search_box->setObjectName("search_box");
        search_box->setMinimumSize(QSize(0, 40));
        search_box->setMaximumSize(QSize(300, 40));

        horizontalLayout_13->addWidget(search_box);

        search_icon = new QPushButton(widget_4);
        search_icon->setObjectName("search_icon");
        sizePolicy2.setHeightForWidth(search_icon->sizePolicy().hasHeightForWidth());
        search_icon->setSizePolicy(sizePolicy2);
        search_icon->setMinimumSize(QSize(40, 40));

        horizontalLayout_13->addWidget(search_icon);


        horizontalLayout_10->addWidget(widget_4, 0, Qt::AlignVCenter);

        horizontalSpacer_15 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_15);

        mystore = new QPushButton(top_frame);
        mystore->setObjectName("mystore");
        mystore->setMinimumSize(QSize(50, 40));
        mystore->setMaximumSize(QSize(50, 40));

        horizontalLayout_10->addWidget(mystore);

        horizontalSpacer_16 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_16);


        horizontalLayout_9->addLayout(horizontalLayout_10);


        gridLayout_2->addWidget(top_frame, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        gridLayout = new QGridLayout(page);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(page);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        dish_list = new QWidget();
        dish_list->setObjectName("dish_list");
        dish_list->setGeometry(QRect(0, 0, 823, 2000));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(dish_list->sizePolicy().hasHeightForWidth());
        dish_list->setSizePolicy(sizePolicy4);
        dish_list->setMinimumSize(QSize(0, 2000));
        scrollArea->setWidget(dish_list);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        gridLayout_3 = new QGridLayout(page_2);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        scrollArea_2 = new QScrollArea(page_2);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setWidgetResizable(true);
        search_results = new QWidget();
        search_results->setObjectName("search_results");
        search_results->setGeometry(QRect(0, 0, 823, 2000));
        sizePolicy4.setHeightForWidth(search_results->sizePolicy().hasHeightForWidth());
        search_results->setSizePolicy(sizePolicy4);
        search_results->setMinimumSize(QSize(0, 2000));
        scrollArea_2->setWidget(search_results);

        gridLayout_3->addWidget(scrollArea_2, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);

        gridLayout_2->addWidget(stackedWidget, 1, 0, 1, 1);

        bottom_frame = new QFrame(centralwidget);
        bottom_frame->setObjectName("bottom_frame");
        sizePolicy1.setHeightForWidth(bottom_frame->sizePolicy().hasHeightForWidth());
        bottom_frame->setSizePolicy(sizePolicy1);
        bottom_frame->setMinimumSize(QSize(0, 50));
        bottom_frame->setMaximumSize(QSize(16777215, 50));
        bottom_frame->setFrameShape(QFrame::StyledPanel);
        bottom_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_11 = new QHBoxLayout(bottom_frame);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        create_recipes = new QPushButton(bottom_frame);
        create_recipes->setObjectName("create_recipes");
        sizePolicy2.setHeightForWidth(create_recipes->sizePolicy().hasHeightForWidth());
        create_recipes->setSizePolicy(sizePolicy2);
        create_recipes->setMinimumSize(QSize(40, 40));
        create_recipes->setMaximumSize(QSize(40, 40));

        horizontalLayout_11->addWidget(create_recipes);


        gridLayout_2->addWidget(bottom_frame, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        logo->setText(QString());
        search_icon->setText(QString());
        mystore->setText(QCoreApplication::translate("MainWindow", "\346\210\221\347\232\204", nullptr));
        create_recipes->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
