#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief Ventana principal del sistema de inventario.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    /**
     * @brief Agrega un componenteusando los datos ingresados en la interfaz.
     */
    void on_btnAgregar_clicked();
    /**
     * @brief Elimina el componente seleccionado en la tabla.
     */
    void on_btnEliminar_clicked();
    /**
     * @brief Edita el componente seleccionado usando los datos de la interfaz.
     */
    void on_btnEditar_clicked();
    void on_tableWidget_cellClicked(int row, int column);
    /**
     * @brief Filta en la tabla completa según el texto ingresado por el cliente.
     */
    void on_inputBuscar_textChanged(const QString &texto);

    void on_btnExportarCSV_clicked();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    /**
     * @brief Carga los componentes desde la base de datos y los muestra en la tabla.
     */
    void cargarComponentes();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
