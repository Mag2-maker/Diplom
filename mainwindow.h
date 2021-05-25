#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <fils.h>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();




    void on_action_triggered();



    void on_action_2_triggered();

    void see();



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H