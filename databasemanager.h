#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QString>

class DatabaseManager
{
private:
    QSqlDatabase db;

public:
    DatabaseManager();

    bool conectar();
    bool crearTablaComponentes();
};

#endif // DATABASEMANAGER_H
