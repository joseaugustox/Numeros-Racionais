#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_soma_clicked()
{
    try {
        int numeradorA = ui->lineEdit_numeradorA->text().toInt();
        int denominadorA = ui->lineEdit_denominadorA->text().toInt();
        int numeradorB = ui->lineEdit_numeradorB->text().toInt();
        int denominadorB = ui->lineEdit_denominadorB->text().toInt();
        jaos::Racionais A(numeradorA,denominadorA), B(numeradorB,denominadorB);
        jaos::Racionais resultado = A+B;
        ui->textEdit_resultado->setText(resultado.obterRacional());
    } catch (QString E) {
        QMessageBox::warning(this, "Aviso",E);
    }
}

void MainWindow::on_pushButton_subtrai_clicked()
{
    try {
        int numeradorA = ui->lineEdit_numeradorA->text().toInt();
        int denominadorA = ui->lineEdit_denominadorA->text().toInt();
        int numeradorB = ui->lineEdit_numeradorB->text().toInt();
        int denominadorB = ui->lineEdit_denominadorB->text().toInt();
        jaos::Racionais A(numeradorA,denominadorA), B(numeradorB,denominadorB);
        jaos::Racionais resultado = A-B;
        ui->textEdit_resultado->setText(resultado.obterRacional());
    } catch (QString E) {
        QMessageBox::warning(this, "Aviso",E);
    }
}

void MainWindow::on_pushButton_multiplica_clicked()
{
    try {
        int numeradorA = ui->lineEdit_numeradorA->text().toInt();
        int denominadorA = ui->lineEdit_denominadorA->text().toInt();
        int numeradorB = ui->lineEdit_numeradorB->text().toInt();
        int denominadorB = ui->lineEdit_denominadorB->text().toInt();
        jaos::Racionais A(numeradorA,denominadorA), B(numeradorB,denominadorB);
        jaos::Racionais resultado = A*B;
        ui->textEdit_resultado->setText(resultado.obterRacional());
    } catch (QString E) {
        QMessageBox::warning(this, "Aviso",E);
    }
}

void MainWindow::on_pushButton_divide_clicked()
{
    try {
        int numeradorA = ui->lineEdit_numeradorA->text().toInt();
        int denominadorA = ui->lineEdit_denominadorA->text().toInt();
        int numeradorB = ui->lineEdit_numeradorB->text().toInt();
        int denominadorB = ui->lineEdit_denominadorB->text().toInt();
        jaos::Racionais A(numeradorA,denominadorA), B(numeradorB,denominadorB);
        jaos::Racionais resultado = A/B;
        ui->textEdit_resultado->setText(resultado.obterRacional());
    } catch (QString E) {
        QMessageBox::warning(this, "Aviso",E);
    }
}

void MainWindow::on_pushButton_verificaIgualdade_clicked()
{
    try {
        int numeradorA = ui->lineEdit_numeradorA->text().toInt();
        int denominadorA = ui->lineEdit_denominadorA->text().toInt();
        int numeradorB = ui->lineEdit_numeradorB->text().toInt();
        int denominadorB = ui->lineEdit_denominadorB->text().toInt();
        jaos::Racionais A(numeradorA,denominadorA), B(numeradorB,denominadorB);
        if(A==B)
        {
            ui->textEdit_resultado->setText("Sao Iguais");
        }
        else
        {
            ui->textEdit_resultado->setText("Nao sao Iguais");
        }

    } catch (QString E) {
        QMessageBox::warning(this, "Aviso",E);
    }
}

void MainWindow::on_pushButton_limpaTela_clicked()
{
    ui->lineEdit_numeradorA->clear();
    ui->lineEdit_numeradorB->clear();
    ui->lineEdit_denominadorA->clear();
    ui->lineEdit_denominadorB->clear();
    ui->textEdit_resultado->clear();
}
