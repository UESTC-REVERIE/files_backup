#include "../include/QtMainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QIcon icon(":/src/img/icon.png");  // 使用相对路径或绝对路径
    a.setWindowIcon(icon);
    QtMainWindow w;
    w.show();

    return a.exec();
}
