#include <QList>
#include "componente.h"
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
    bool insertarComponente(const Componente &componente);
    QList<Componente> obtenerComponentes();

    void eliminarComponente(int id);

    void actualizarComponente(const Componente &c);
};

#endif // DATABASEMANAGER_H

