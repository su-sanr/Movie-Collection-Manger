/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QListWidget *movieListWidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *titleInput;
    QLabel *label_3;
    QLineEdit *genreInput;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *yearInput;
    QLineEdit *trailerInput;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *updateButton;
    QPushButton *undoButton;
    QPushButton *redoButton;
    QMenuBar *menubar;
    QMenu *menuMovie_Collection_Manager;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(857, 565);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        movieListWidget = new QListWidget(centralwidget);
        movieListWidget->setObjectName("movieListWidget");

        verticalLayout_2->addWidget(movieListWidget);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        titleInput = new QLineEdit(groupBox);
        titleInput->setObjectName("titleInput");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, titleInput);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_3);

        genreInput = new QLineEdit(groupBox);
        genreInput->setObjectName("genreInput");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, genreInput);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_2);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        yearInput = new QLineEdit(groupBox);
        yearInput->setObjectName("yearInput");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, yearInput);

        trailerInput = new QLineEdit(groupBox);
        trailerInput->setObjectName("trailerInput");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, trailerInput);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        addButton = new QPushButton(groupBox);
        addButton->setObjectName("addButton");

        horizontalLayout->addWidget(addButton);

        deleteButton = new QPushButton(groupBox);
        deleteButton->setObjectName("deleteButton");

        horizontalLayout->addWidget(deleteButton);

        updateButton = new QPushButton(groupBox);
        updateButton->setObjectName("updateButton");

        horizontalLayout->addWidget(updateButton);

        undoButton = new QPushButton(groupBox);
        undoButton->setObjectName("undoButton");

        horizontalLayout->addWidget(undoButton);

        redoButton = new QPushButton(groupBox);
        redoButton->setObjectName("redoButton");

        horizontalLayout->addWidget(redoButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addWidget(groupBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 857, 20));
        menuMovie_Collection_Manager = new QMenu(menubar);
        menuMovie_Collection_Manager->setObjectName("menuMovie_Collection_Manager");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMovie_Collection_Manager->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Movie Details", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Title", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Genre", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Year", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "URl", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        updateButton->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        undoButton->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        redoButton->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        menuMovie_Collection_Manager->setTitle(QCoreApplication::translate("MainWindow", "Movie Collection Manager", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
