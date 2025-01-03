#include "../include/QtMainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QIcon icon(":/src/img/icon.png");  // ʹ�����·�������·��
    a.setWindowIcon(icon);
    QtMainWindow w;
    w.show();

    return a.exec();
}
