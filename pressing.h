#ifndef PRESSING_H
#define PRESSING_H

#include <QMainWindow>
#include "QJsonObject"
#include "ui_mainwindow.h"

class Pressing
{
public:
    Pressing();
    void ITD_ITd(QJsonObject temp, QString TD_k, QString Td_k,bool _radio_button);
    void Variable(QString s,QJsonObject temp1);
    void IEI_Iei (double Td, double TD);
    void IEI_Iei_v (double Td, double TD);
    double Td=0, TD=0, EI=0, ES=0,es=0, ei=0, N=0,EI1=0, ES1=0,es1=0, ei1=0, N1=0;
    QString s1;
    QJsonObject temp2;
};

#endif // PRESSING_H
