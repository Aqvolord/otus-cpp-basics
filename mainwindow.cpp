#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clearLineWidget();
    makeColum();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Edit_clicked()
{
    /* Условие установленного режима игры */
    if (ui->radioButton_10->isChecked()
            || ui->radioButton_100->isChecked()
            || ui->radioButton_200->isChecked())
    {
        qDebug() << _randomValue;
        auto _guessNumber = ui->spinBox->value();

        /* Проверка на соответсвтие загаданному числу и счетчик попыток */
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
            ui->label->show();
            ui->label_2->show();
            ui->label->setText(QString::number(_counter + 1));
        }
    }
    else
        QMessageBox::warning(this, "Внимание", "Выберите режим игры!");
}

void MainWindow::on_pushButton_Name_clicked()
{
    if(ui->radioButton_10->isChecked()){
        // Запись в файл 10
    }
    else if (ui->radioButton_100->isChecked()) {
        // Запись в файл 100
    }
    else if(ui->radioButton_200->isChecked()){
        // Запись в файл 200
    }
    else
        QMessageBox::warning(this, "Внимание", "Выберите режим игры!");
}

void MainWindow::createTable()
{
   //Создание таблиц на основе файлов
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
    rand(201);
    clearLineWidget();
}

/* Установка загаданного числа в зависимости от выбранного режима игры */
int MainWindow::rand(int bef)
{
    if ( bef <= 100)
    {
        std::srand(std::time(nullptr));
        _randomValue = std::rand() % bef + 1;
        return _randomValue;
    }
    else
    {
        std::srand(std::time(nullptr));
        _randomValue = std::rand() % bef - 100;
        return _randomValue;
    }
}

/* Очитска всех форм и данных при новой игре или после завершения игры */
void MainWindow::clearLineWidget()
{
    ui->listWidget_Less->clear();
    ui->listWidget_More->clear();
    ui->spinBox->clear();
    ui->label_2->hide();
    ui->label->hide();
    _counter = 0;
}

void MainWindow::makeColum()
{
    ui->tableWidget_10->setColumnCount(2);
    ui->tableWidget_10->setHorizontalHeaderLabels(QStringList() << "Имя" << "Попыток");
    ui->tableWidget_100->setColumnCount(2);
    ui->tableWidget_100->setHorizontalHeaderLabels(QStringList() << "Имя" << "Попыток");
    ui->tableWidget_200->setColumnCount(2);
    ui->tableWidget_200->setHorizontalHeaderLabels(QStringList() << "Имя" << "Попыток");
}
