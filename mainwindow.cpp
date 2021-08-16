#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clearLineWidget();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Edit_clicked()
{
    if (ui->radioButton_10->isChecked()
            || ui->radioButton_100->isChecked()
            || ui->radioButton_200->isChecked())
    {

        auto _guessNumber = ui->spinBox->value();

        if (_randomValue != _guessNumber)
        {
            (_randomValue > _guessNumber) ?
                      ui->listWidget_Less->addItem(QString::number(_guessNumber)+" < ")
                    : ui->listWidget_More->addItem(" < "+QString::number(_guessNumber));

            _counter += 1;
            ui->spinBox->clear();
        }
        else
        {
        qDebug() << _counter + 1;
        _counter = 0;
        }
    }
    else
        QMessageBox::warning(this, "Внимание", "Выберите режим игры!");
}

void MainWindow::on_radioButton_10_clicked()
{
    ui->spinBox->setRange(1, 10);
    rand(10);
    clearLineWidget();
}

void MainWindow::on_radioButton_100_clicked()
{
    ui->spinBox->setRange(1, 100);
    rand(100);
    clearLineWidget();
}

void MainWindow::on_radioButton_200_clicked()
{
    ui->spinBox->setRange(-100, 100);
    rand(100);
    clearLineWidget();
}

int MainWindow::rand(int bef)
{
    std::srand(std::time(nullptr));
    _randomValue = std::rand() % bef + 1;
    return _randomValue;
}

void MainWindow::clearLineWidget()
{
    ui->listWidget_Less->clear();
    ui->listWidget_More->clear();
    ui->spinBox->clear();
}
