/********************************************************************************
** Form generated from reading UI file 'QtBackupWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTBACKUPWINDOW_H
#define UI_QTBACKUPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtBackupWindowClass
{
public:

    void setupUi(QWidget *QtBackupWindowClass)
    {
        if (QtBackupWindowClass->objectName().isEmpty())
            QtBackupWindowClass->setObjectName("QtBackupWindowClass");
        QtBackupWindowClass->resize(600, 400);

        retranslateUi(QtBackupWindowClass);

        QMetaObject::connectSlotsByName(QtBackupWindowClass);
    } // setupUi

    void retranslateUi(QWidget *QtBackupWindowClass)
    {
        QtBackupWindowClass->setWindowTitle(QCoreApplication::translate("QtBackupWindowClass", "QtBackupWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtBackupWindowClass: public Ui_QtBackupWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTBACKUPWINDOW_H
