# Sistema de Inventario Electrónico

Es una aplicación de escritorio desarrollada en C++ con Qt5 y SQLite3 para gestionar componentes electrónicos de laboratorio.

## Funcionalidades

- Registrar componentes electrónicos.
- Editar componentes existentes.
- Eliminar componentes.
- Consultar inventario en tabla.
- Buscar componentes en tiempo real.
- Registrar valor, proveedor y stock mínimo.
- Alertar visualmente componentes con bajo stock.
- Mostrar estadísticas de total de componentes y stock bajo.

## Tecnologías

- C++
- Qt5
- SQLite3
- Git y GitHub
- Doxygen

## Clases principales

- Componente: representa un componente del inventario.
- DatabaseManager: gestiona la conexión y operaciones con SQLite.
- MainWindow: controla la interfaz gráfica.

## Base de datos

Tabla principal: componentes.

Campos:
- id
- nombre
- categoria
- cantidad
- ubicacion
- valor
- proveedor
- stock_minimo
