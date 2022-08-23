#include <QApplication>

#include "QueueRedMainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QueueRedMainWindow w;

    w.setWindowTitle("QueueRed");
    w.setFixedSize(QSize(950, 800));
    //w.show();

    return a.exec();
}
