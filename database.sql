CREATE TABLE componentes (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nombre TEXT NOT NULL,
    categoria TEXT NOT NULL,
    cantidad INTEGER NOT NULL,
    ubicacion TEXT,
    valor TEXT,
    proveedor TEXT,
    stock_minimo INTEGER NOT NULL
);
