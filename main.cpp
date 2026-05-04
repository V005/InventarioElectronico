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

        Componente c1(0, "Resistencia", "Resistencia", 50, "Caja A1", "220 ohm", "Steren", 10);
        db.insertarComponente(c1);
    }


    MainWindow w;
    w.show();
    return a.exec();
}
