#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H

#include <QMainWindow>
#include "mainwindow.h"
#include "fils.h"
#include "landing.h"
#include "ui_mainwindow.h"
#include <menu.h>
#include "values.h"
#include "data_struct.h"
#include "pressing.h"
#include <math.h>
#include <QString>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include "QStandardItemModel"
#include "QStandardItem"
#include <QComboBox>
#include <QLayout>

class WindowController: public QObject
{
    Q_OBJECT
public:
    WindowController(MainWindow *w);

private slots:
    void LandingChicked_handler(data_main&);
    void LandingChicked_handler_2(data_main&);

signals:
    void SendDataModelToForm(Landing&);
    void SendDataModelToForm_2(data_pressing&);

private:
    MainWindow *window;
    //Data_Model data_model;

    void InitializeConnections();
};

#endif // WINDOWCONTROLLER_H
