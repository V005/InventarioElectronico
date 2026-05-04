#include "databasemanager.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DatabaseManager db;

    if (db.conectar())
    {
        db.crearTablaComponentes();
    }

    MainWindow w;
    w.show();
    return a.exec();
}
