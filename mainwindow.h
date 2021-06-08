#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <fils.h>
#include "data_struct.h"
#include "landing.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:

private slots:
    void on_pushButton_clicked();//расчитать посадку
    void on_pushButton_2_clicked();// расчитать запрессовку




    void on_action_triggered();// сохранение в файл



    void on_action_2_triggered();// выйти

    void see();
bool user_input_is_correct();
bool radio_button();
    // вызываются в контроллере
    void GetDataAndFillWindow(Landing&);
    void GetDataAndFillWindow_2(data_pressing&);

signals:
    void LandingClicked(data_main&);
    void LandingClicked_2(data_main&);


private:
    Ui::MainWindow *ui;
    MainWindow* controller;

};

#endif // MAINWINDOW_H
