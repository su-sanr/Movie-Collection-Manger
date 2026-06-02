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
    QVBoxLayout *verticalLayout_3;
    QListWidget *movieListWidget;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout_2;
    QLabel *label_5;
    QLineEdit *filterGenreInput;
    QLineEdit *filterYearInput;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *filterButton;
    QPushButton *clearFilterButton;
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
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        movieListWidget = new QListWidget(centralwidget);
        movieListWidget->setObjectName("movieListWidget");

        verticalLayout_3->addWidget(movieListWidget);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");

        formLayout_2->setWidget(0, QFormLayout::ItemRole::LabelRole, label_5);

        filterGenreInput = new QLineEdit(groupBox_2);
        filterGenreInput->setObjectName("filterGenreInput");

        formLayout_2->setWidget(0, QFormLayout::ItemRole::FieldRole, filterGenreInput);

        filterYearInput = new QLineEdit(groupBox_2);
        filterYearInput->setObjectName("filterYearInput");

        formLayout_2->setWidget(1, QFormLayout::ItemRole::FieldRole, filterYearInput);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");

        formLayout_2->setWidget(1, QFormLayout::ItemRole::LabelRole, label_6);


        verticalLayout_2->addLayout(formLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        filterButton = new QPushButton(groupBox_2);
        filterButton->setObjectName("filterButton");

        horizontalLayout_2->addWidget(filterButton);

        clearFilterButton = new QPushButton(groupBox_2);
        clearFilterButton->setObjectName("clearFilterButton");

        horizontalLayout_2->addWidget(clearFilterButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(groupBox_2);

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


        verticalLayout_3->addWidget(groupBox);

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
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Filters", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Genre", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Year", nullptr));
        filterButton->setText(QCoreApplication::translate("MainWindow", "Filter", nullptr));
        clearFilterButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
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
