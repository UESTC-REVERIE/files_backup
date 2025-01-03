/********************************************************************************
** Form generated from reading UI file 'QtMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTMAINWINDOW_H
#define UI_QTMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtMainWindowClass
{
public:

    void setupUi(QWidget *QtMainWindowClass)
    {
        if (QtMainWindowClass->objectName().isEmpty())
            QtMainWindowClass->setObjectName("QtMainWindowClass");
        QtMainWindowClass->resize(600, 400);

        retranslateUi(QtMainWindowClass);

        QMetaObject::connectSlotsByName(QtMainWindowClass);
    } // setupUi

    void retranslateUi(QWidget *QtMainWindowClass)
    {
        QtMainWindowClass->setWindowTitle(QCoreApplication::translate("QtMainWindowClass", "QtMainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtMainWindowClass: public Ui_QtMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTMAINWINDOW_H
