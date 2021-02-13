#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "endianconverter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int num = 1;
    IsLittleEndian = (*(char *)&num == 1);
    conv = new EndianConverter;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int buf = ui->lineEdit->text().toInt();
    ui->tbNumbers->append(QString::number(buf));
    if(IsLittleEndian){
        ui->tbLittleEndian->append(conv->toHex(buf));
        ui->tbBigEndian->append(conv->toHex(conv->ChangeEndiannes(buf)));
    }
    else{
        ui->tbLittleEndian->append(conv->toHex(conv->ChangeEndiannes(buf)));
        ui->tbBigEndian->append(conv->toHex(buf));
    }
    ui->lineEdit->setText("");
}
