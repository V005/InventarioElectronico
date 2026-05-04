#include <QList>
#include "databasemanager.h"
#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DatabaseManager db;

    if (db.conectar())
    {
        db.crearTablaComponentes();

        Componente c1(0, "Resistencia", "Resistencia", 50, "Caja A1", "220 ohm", "Steren", 10);
        db.insertarComponente(c1);

        QList<Componente> lista = db.obtenerComponentes();

        for (const Componente &c : lista)
        {
            qDebug() << "Nombre:" << c.getNombre()
                     << "| Cantidad:" << c.getCantidad();
        }
    }


    MainWindow w;
    w.show();
    return a.exec();
}
