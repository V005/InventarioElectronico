#include <QList>
#include "componente.h"
#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QSqlDatabase>
#include <QString>

/**
 * @brief Clase encargada de gestionar la base de datos SQLite.
 */
class DatabaseManager
{
private:
    QSqlDatabase db;

public:
    DatabaseManager();

    bool conectar();
    bool crearTablaComponentes();

    /**
     * @brief Inserta un componente en la base de datos.
     */
    bool insertarComponente(const Componente &componente);
    QList<Componente> obtenerComponentes();

    /**
     * @brief Elimina un componente en la base de datos.
     */
    void eliminarComponente(int id);

    /**
     * @brief Actualiza un componente en la base de datos.
     */
    void actualizarComponente(const Componente &c);
};

#endif // DATABASEMANAGER_H

