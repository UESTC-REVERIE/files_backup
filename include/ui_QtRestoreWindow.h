/********************************************************************************
** Form generated from reading UI file 'QtRestoreWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTRESTOREWINDOW_H
#define UI_QTRESTOREWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtRestoreWindowClass
{
public:

    void setupUi(QWidget *QtRestoreWindowClass)
    {
        if (QtRestoreWindowClass->objectName().isEmpty())
            QtRestoreWindowClass->setObjectName("QtRestoreWindowClass");
        QtRestoreWindowClass->resize(600, 400);

        retranslateUi(QtRestoreWindowClass);

        QMetaObject::connectSlotsByName(QtRestoreWindowClass);
    } // setupUi

    void retranslateUi(QWidget *QtRestoreWindowClass)
    {
        QtRestoreWindowClass->setWindowTitle(QCoreApplication::translate("QtRestoreWindowClass", "QtRestoreWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtRestoreWindowClass: public Ui_QtRestoreWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTRESTOREWINDOW_H
