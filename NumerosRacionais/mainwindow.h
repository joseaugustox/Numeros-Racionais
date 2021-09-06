#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Racionais.h>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_soma_clicked();

    void on_pushButton_subtrai_clicked();

    void on_pushButton_multiplica_clicked();

    void on_pushButton_divide_clicked();

    void on_pushButton_verificaIgualdade_clicked();

    void on_pushButton_limpaTela_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
