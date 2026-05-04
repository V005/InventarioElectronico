#ifndef COMPONENTE_H
#define COMPONENTE_H

#include <QString>

class Componente
{
private:
    int id;
    QString nombre;
    QString categoria;
    int cantidad;
    QString ubicacion;
    QString valor;
    QString proveedor;
    int stockMinimo;

public:
    Componente();

    Componente(int id,
               const QString &nombre,
               const QString &categoria,
               int cantidad,
               const QString &ubicacion,
               const QString &valor,
               const QString &proveedor,
               int stockMinimo);

    int getId() const;
    QString getNombre() const;
    QString getCategoria() const;
    int getCantidad() const;
    QString getUbicacion() const;
    QString getValor() const;
    QString getProveedor() const;
    int getStockMinimo() const;

    void setId(int id);
    void setNombre(const QString &nombre);
    void setCategoria(const QString &categoria);
    void setCantidad(int cantidad);
    void setUbicacion(const QString &ubicacion);
    void setValor(const QString &valor);
    void setProveedor(const QString &proveedor);
    void setStockMinimo(int stockMinimo);

    bool tieneStockBajo() const;
};

#endif // COMPONENTE_H
