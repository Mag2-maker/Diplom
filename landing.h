 #ifndef LANDING_H
#define LANDING_H
#include <QJsonObject>
#include "ui_mainwindow.h"
#include "data_struct.h"

#include <QMainWindow>

class Landing
{
public:
    Landing();
    void ITD_ITd(double TN,bool _radio_button);
    void IEI_Iei(double ITD, double ITd, QString ITD_k, QString ITd_k);
    void IEI_Iei_v(double ITD, double ITd, QString ITD_k, QString ITd_k);
    void Variable (double delta_n_min, double delta_max, QJsonObject temp1,QJsonObject temp);
    double TD=0, TD1=0,Td=0, Td1=0,d, EI=0, es=0, ES=0,EI1=0, es1=0, ES1=0,delta_n_min_1=0,  delta_max_1=0;
    QString TD_k,Td_k, ei_k,TD_k1,Td_k1, ei_k1;
    QJsonObject _temp1,_temp;
    QVector<QString> keys, keys1; QVector<double> N,N1;
    QVector<double> ooop, ooop1;
};

#endif // LANDING_H
