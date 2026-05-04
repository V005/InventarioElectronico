#include "componente.h"

Componente::Componente()
{
    id = 0;
    cantidad = 0;
    stockMinimo = 0;
}

Componente::Componente(int id,
                       const QString &nombre,
                       const QString &categoria,
                       int cantidad,
                       const QString &ubicacion,
                       const QString &valor,
                       const QString &proveedor,
                       int stockMinimo)
{
    this->id = id;
    this->nombre = nombre;
    this->categoria = categoria;
    this->cantidad = cantidad;
    this->ubicacion = ubicacion;
    this->valor = valor;
    this->proveedor = proveedor;
    this->stockMinimo = stockMinimo;
}

int Componente::getId() const { return id; }
QString Componente::getNombre() const { return nombre; }
QString Componente::getCategoria() const { return categoria; }
int Componente::getCantidad() const { return cantidad; }
QString Componente::getUbicacion() const { return ubicacion; }
QString Componente::getValor() const { return valor; }
QString Componente::getProveedor() const { return proveedor; }
int Componente::getStockMinimo() const { return stockMinimo; }

void Componente::setId(int id) { this->id = id; }
void Componente::setNombre(const QString &nombre) { this->nombre = nombre; }
void Componente::setCategoria(const QString &categoria) { this->categoria = categoria; }
void Componente::setCantidad(int cantidad) { this->cantidad = cantidad; }
void Componente::setUbicacion(const QString &ubicacion) { this->ubicacion = ubicacion; }
void Componente::setValor(const QString &valor) { this->valor = valor; }
void Componente::setProveedor(const QString &proveedor) { this->proveedor = proveedor; }
void Componente::setStockMinimo(int stockMinimo) { this->stockMinimo = stockMinimo; }

bool Componente::tieneStockBajo() const
{
    return cantidad <= stockMinimo;
}
