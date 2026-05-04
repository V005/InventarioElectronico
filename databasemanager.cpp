#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager()
{
}

bool DatabaseManager::conectar()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("inventario.db");

    if (!db.open())
    {
        qDebug() << "Error al abrir la base de datos:" << db.lastError().text();
        return false;
    }

    qDebug() << "Base de datos conectada correctamente.";
    return true;
}

bool DatabaseManager::crearTablaComponentes()
{
    QSqlQuery query;

    QString sql = "CREATE TABLE IF NOT EXISTS componentes ("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "nombre TEXT NOT NULL, "
                  "categoria TEXT NOT NULL, "
                  "cantidad INTEGER NOT NULL, "
                  "ubicacion TEXT, "
                  "valor TEXT, "
                  "proveedor TEXT, "
                  "stock_minimo INTEGER NOT NULL);";

    if (!query.exec(sql))
    {
        qDebug() << "Error al crear la tabla:" << query.lastError().text();
        return false;
    }

    qDebug() << "Tabla creada o ya existente.";
    return true;
}
