#include <QApplication>
#include "../includes/mainwindow.hpp"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
