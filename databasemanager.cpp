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

bool DatabaseManager::insertarComponente(const Componente &componente)
{
    QSqlQuery query;

    query.prepare("INSERT INTO componentes (nombre, categoria, cantidad, ubicacion, valor, proveedor, stock_minimo) "
                  "VALUES (:nombre, :categoria, :cantidad, :ubicacion, :valor, :proveedor, :stock_minimo)");

    query.bindValue(":nombre", componente.getNombre());
    query.bindValue(":categoria", componente.getCategoria());
    query.bindValue(":cantidad", componente.getCantidad());
    query.bindValue(":ubicacion", componente.getUbicacion());
    query.bindValue(":valor", componente.getValor());
    query.bindValue(":proveedor", componente.getProveedor());
    query.bindValue(":stock_minimo", componente.getStockMinimo());

    if (!query.exec())
    {
        qDebug() << "Error al insertar componente:" << query.lastError().text();
        return false;
    }

    qDebug() << "Componente insertado correctamente.";
    return true;
}

QList<Componente> DatabaseManager::obtenerComponentes()
{
    QList<Componente> lista;
    QSqlQuery query("SELECT * FROM componentes");

    while (query.next())
    {
        int id = query.value("id").toInt();
        QString nombre = query.value("nombre").toString();
        QString categoria = query.value("categoria").toString();
        int cantidad = query.value("cantidad").toInt();
        QString ubicacion = query.value("ubicacion").toString();
        QString valor = query.value("valor").toString();
        QString proveedor = query.value("proveedor").toString();
        int stockMinimo = query.value("stock_minimo").toInt();

        Componente c(id, nombre, categoria, cantidad, ubicacion, valor, proveedor, stockMinimo);
        lista.append(c);
    }

    qDebug() << "Componentes leídos:" << lista.size();
    return lista;
}
void DatabaseManager::eliminarComponente(int id)
{
    QSqlQuery query;

    query.prepare("DELETE FROM componentes WHERE id = :id");

    query.bindValue(":id", id);

    query.exec();
}

void DatabaseManager::actualizarComponente(const Componente &c)
{
    QSqlQuery query;

    query.prepare("UPDATE componentes SET "
                  "nombre = :nombre, "
                  "categoria = :categoria, "
                  "cantidad = :cantidad, "
                  "ubicacion = :ubicacion, "
                  "valor = :valor, "
                  "proveedor = :proveedor, "
                  "stock_minimo = :stock_minimo "
                  "WHERE id = :id");

    query.bindValue(":nombre", c.getNombre());
    query.bindValue(":categoria", c.getCategoria());
    query.bindValue(":cantidad", c.getCantidad());
    query.bindValue(":ubicacion", c.getUbicacion());
    query.bindValue(":valor", c.getValor());
    query.bindValue(":proveedor", c.getProveedor());
    query.bindValue(":stock_minimo", c.getStockMinimo());
    query.bindValue(":id", c.getId());

    query.exec();
}

