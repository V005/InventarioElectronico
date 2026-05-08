#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "databasemanager.h"
#include "componente.h"
#include <QHeaderView>

#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cargarComponentes();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setAlternatingRowColors(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cargarComponentes()
{
    DatabaseManager db;

    if (db.conectar())
    {
        QList<Componente> lista = db.obtenerComponentes();

        ui->tableWidget->setRowCount(lista.size());

        int fila = 0;
        int stockBajo = 0;
        for (const Componente &c : lista)
        {
            QTableWidgetItem *itemId = new QTableWidgetItem(QString::number(c.getId()));
            QTableWidgetItem *itemNombre = new QTableWidgetItem(c.getNombre());
            QTableWidgetItem *itemCategoria = new QTableWidgetItem(c.getCategoria());
            QTableWidgetItem *itemCantidad = new QTableWidgetItem(QString::number(c.getCantidad()));
            QTableWidgetItem *itemUbicacion = new QTableWidgetItem(c.getUbicacion());
            QTableWidgetItem *itemValor = new QTableWidgetItem(c.getValor());
            QTableWidgetItem *itemProveedor = new QTableWidgetItem(c.getProveedor());
            QTableWidgetItem *itemStockMinimo = new QTableWidgetItem(QString::number(c.getStockMinimo()));

            if (c.tieneStockBajo())
            {
                stockBajo++;
                itemId->setBackground(Qt::red);
                itemNombre->setBackground(Qt::red);
                itemCategoria->setBackground(Qt::red);
                itemCantidad->setBackground(Qt::red);
                itemUbicacion->setBackground(Qt::red);
            }

            ui->tableWidget->setItem(fila, 0, itemId);
            ui->tableWidget->setItem(fila, 1, itemNombre);
            ui->tableWidget->setItem(fila, 2, itemCategoria);
            ui->tableWidget->setItem(fila, 3, itemCantidad);
            ui->tableWidget->setItem(fila, 4, itemUbicacion);
            ui->tableWidget->setItem(fila, 5, itemValor);
            ui->tableWidget->setItem(fila, 6, itemProveedor);
            ui->tableWidget->setItem(fila, 7, itemStockMinimo);

            fila++;
        }
        ui->labelTotal->setText(
            "Total componentes: " + QString::number(lista.size()));

        ui->labelStockBajo->setText(
            "Stock bajo: " + QString::number(stockBajo));
    }
}

void MainWindow::on_btnAgregar_clicked()
{
    QString nombre = ui->inputNombre->text();
    QString categoria = ui->inputCategoria->text();
    int cantidad = ui->inputCantidad->value();
    QString ubicacion = ui->inputUbicacion->text();
    QString valor = ui->inputValor->text();
    QString proveedor = ui->inputProveedor->text();
    int stockMinimo = ui->inputStockMinimo->value();

    Componente nuevo(0, nombre, categoria, cantidad, ubicacion, valor, proveedor, stockMinimo);

    DatabaseManager db;

    if (db.conectar())
    {
        db.insertarComponente(nuevo);
    }

    ui->inputNombre->clear();
    ui->inputCategoria->clear();
    ui->inputCantidad->setValue(0);
    ui->inputUbicacion->clear();
    ui->inputValor->clear();
    ui->inputProveedor->clear();
    ui->inputStockMinimo->setValue(0);

    cargarComponentes();
}
void MainWindow::on_btnEliminar_clicked()
{
    int fila = ui->tableWidget->currentRow();

    if (fila == -1)
        return;

    int id = ui->tableWidget->item(fila, 0)->text().toInt();

    DatabaseManager db;

    if (db.conectar())
    {
        db.eliminarComponente(id);
    }

    cargarComponentes();
}
void MainWindow::on_btnEditar_clicked()
{
    int fila = ui->tableWidget->currentRow();

    if (fila == -1)
        return;

    int id = ui->tableWidget->item(fila, 0)->text().toInt();

    QString nombre = ui->inputNombre->text();
    QString categoria = ui->inputCategoria->text();
    int cantidad = ui->inputCantidad->value();
    QString ubicacion = ui->inputUbicacion->text();
    QString valor = ui->inputValor->text();
    QString proveedor = ui->inputProveedor->text();
    int stockMinimo = ui->inputStockMinimo->value();

    Componente componenteEditado(
        id,
        nombre,
        categoria,
        cantidad,
        ubicacion,
        valor,
        proveedor,
        stockMinimo
    );

    DatabaseManager db;

    if (db.conectar())
    {
        db.actualizarComponente(componenteEditado);
    }

    cargarComponentes();
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    Q_UNUSED(column);

    ui->inputNombre->setText(ui->tableWidget->item(row, 1)->text());
    ui->inputCategoria->setText(ui->tableWidget->item(row, 2)->text());
    ui->inputCantidad->setValue(ui->tableWidget->item(row, 3)->text().toInt());
    ui->inputUbicacion->setText(ui->tableWidget->item(row, 4)->text());
    ui->inputValor->setText(ui->tableWidget->item(row, 5)->text());
    ui->inputProveedor->setText(ui->tableWidget->item(row, 6)->text());
    ui->inputStockMinimo->setValue(ui->tableWidget->item(row, 7)->text().toInt());
}

void MainWindow::on_inputBuscar_textChanged(const QString &texto)
{
    for (int fila = 0; fila < ui->tableWidget->rowCount(); fila++)
    {
        bool coincide = false;

        for (int columna = 0; columna < ui->tableWidget->columnCount(); columna++)
        {
            QTableWidgetItem *item = ui->tableWidget->item(fila, columna);

            if (item && item->text().contains(texto, Qt::CaseInsensitive))
            {
                coincide = true;
                break;
            }
        }

        ui->tableWidget->setRowHidden(fila, !coincide);
    }
}
