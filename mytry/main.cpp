#include "widget.h"

#include <QApplication>
#include <QPushButton>
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Widget window;
    window.show();
    return app.exec();

}
