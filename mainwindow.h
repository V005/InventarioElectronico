#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void on_btnAgregar_clicked();
    void on_btnEliminar_clicked();
    void on_btnEditar_clicked();
    void on_tableWidget_cellClicked(int row, int column);
    void on_inputBuscar_textChanged(const QString &texto);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void cargarComponentes();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
