#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdexcept>
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
    void on_pushButton_Edit_clicked();
    void on_radioButton_10_clicked();
    void on_radioButton_100_clicked();
    void on_radioButton_200_clicked();

private:
    Ui::MainWindow *ui;
    int rand(int bef);
    void clearLineWidget();

    int _randomValue = 0;
    int _counter = 0;
};
#endif // MAINWINDOW_H
