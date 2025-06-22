/********************************************************************************
** Form generated from reading UI file 'mystorewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSTOREWINDOW_H
#define UI_MYSTOREWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myStoreWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QWidget *avatar_area;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QWidget *name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *name_edit;
    QWidget *introduction;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QPlainTextEdit *intro_edit;
    QTabWidget *tabWidget;
    QWidget *collections;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *collection_list;
    QWidget *draft_box;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea_2;
    QWidget *draft_list;

    void setupUi(QMainWindow *myStoreWindow)
    {
        if (myStoreWindow->objectName().isEmpty())
            myStoreWindow->setObjectName("myStoreWindow");
        myStoreWindow->resize(800, 600);
        centralwidget = new QWidget(myStoreWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(-1, 0, 0, 0);
        avatar_area = new QWidget(widget);
        avatar_area->setObjectName("avatar_area");

        gridLayout_3->addWidget(avatar_area, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_3->addItem(verticalSpacer_2, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_3->addItem(verticalSpacer, 2, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_3->addItem(verticalSpacer_3, 5, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        name = new QWidget(widget);
        name->setObjectName("name");
        name->setMinimumSize(QSize(200, 50));
        name->setMaximumSize(QSize(700, 100));
        horizontalLayout_2 = new QHBoxLayout(name);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(name);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        name_edit = new QLineEdit(name);
        name_edit->setObjectName("name_edit");
        name_edit->setMinimumSize(QSize(0, 40));

        horizontalLayout_2->addWidget(name_edit);


        gridLayout_3->addWidget(name, 3, 0, 1, 3);

        introduction = new QWidget(widget);
        introduction->setObjectName("introduction");
        introduction->setMinimumSize(QSize(0, 100));
        introduction->setMaximumSize(QSize(700, 80));
        horizontalLayout_3 = new QHBoxLayout(introduction);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(introduction);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2, 0, Qt::AlignTop);

        intro_edit = new QPlainTextEdit(introduction);
        intro_edit->setObjectName("intro_edit");
        intro_edit->setMinimumSize(QSize(0, 100));

        horizontalLayout_3->addWidget(intro_edit);


        gridLayout_3->addWidget(introduction, 4, 0, 1, 3);

        gridLayout_3->setRowStretch(0, 2);
        gridLayout_3->setRowStretch(1, 3);
        gridLayout_3->setRowStretch(2, 2);
        gridLayout_3->setRowStretch(3, 1);
        gridLayout_3->setRowStretch(4, 1);
        gridLayout_3->setRowStretch(5, 2);
        gridLayout_3->setColumnStretch(0, 1);
        gridLayout_3->setColumnStretch(1, 4);
        gridLayout_3->setColumnStretch(2, 1);

        horizontalLayout->addWidget(widget);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setMovable(false);
        collections = new QWidget();
        collections->setObjectName("collections");
        gridLayout = new QGridLayout(collections);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(collections);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        collection_list = new QWidget();
        collection_list->setObjectName("collection_list");
        collection_list->setGeometry(QRect(0, 0, 490, 2000));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(collection_list->sizePolicy().hasHeightForWidth());
        collection_list->setSizePolicy(sizePolicy);
        collection_list->setMinimumSize(QSize(0, 2000));
        scrollArea->setWidget(collection_list);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        tabWidget->addTab(collections, QString());
        draft_box = new QWidget();
        draft_box->setObjectName("draft_box");
        gridLayout_2 = new QGridLayout(draft_box);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea_2 = new QScrollArea(draft_box);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setWidgetResizable(true);
        draft_list = new QWidget();
        draft_list->setObjectName("draft_list");
        draft_list->setGeometry(QRect(0, 0, 490, 2000));
        sizePolicy.setHeightForWidth(draft_list->sizePolicy().hasHeightForWidth());
        draft_list->setSizePolicy(sizePolicy);
        draft_list->setMinimumSize(QSize(0, 2000));
        scrollArea_2->setWidget(draft_list);

        gridLayout_2->addWidget(scrollArea_2, 0, 0, 1, 1);

        tabWidget->addTab(draft_box, QString());

        horizontalLayout->addWidget(tabWidget);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 6);
        myStoreWindow->setCentralWidget(centralwidget);

        retranslateUi(myStoreWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(myStoreWindow);
    } // setupUi

    void retranslateUi(QMainWindow *myStoreWindow)
    {
        myStoreWindow->setWindowTitle(QCoreApplication::translate("myStoreWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("myStoreWindow", "\346\230\265\347\247\260\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("myStoreWindow", "\350\207\252\346\210\221\344\273\213\347\273\215\357\274\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(collections), QCoreApplication::translate("myStoreWindow", "\346\224\266\350\227\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(draft_box), QCoreApplication::translate("myStoreWindow", "\350\215\211\347\250\277\347\256\261", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myStoreWindow: public Ui_myStoreWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSTOREWINDOW_H
