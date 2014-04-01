#include "chatgui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    chatGui w;
    w.show();

    return a.exec();
}
