#include <iostream>
#include <QtWidgets>
#include <window.h>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Window w;
    w.show();

    return app.exec();
}

