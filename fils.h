#ifndef FILS_H
#define FILS_H

#include <QMainWindow>

class Fils
{
public:
    Fils();
    QByteArray loadJson(QString filename);
    QJsonObject EI_ei(QByteArray file1, double d);
    QJsonObject TD_Td(QByteArray file, double d);
    QJsonObject TD_Td_p(QByteArray file, double d);
    QVector<QString> keys;
    double TD=0,Td=0,EI=0, es=0, ES=0;
    QString TD_k,Td_k, ei_k;
};


#endif // FILS_H
