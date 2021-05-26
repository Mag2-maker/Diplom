#include "pressing.h"
#include "QJsonObject"
#include "landing.h"
#include "ui_mainwindow.h"

Pressing::Pressing()
{

}


void Pressing::Variable (QString s, QJsonObject temp1)
{
   s1=s;
   temp2=temp1;
}

void Pressing:: ITD_ITd(QJsonObject temp, QString TD_k, QString Td_k,Ui::MainWindow *ui)
{
     auto map = temp.toVariantMap();
     qDebug()<<map;
     auto it=map.begin()+1;
     auto it2=it;
                  for(; it!=map.end()-1;)
                  {
                       it2++;

                            if(it.key()==Td_k)
                            {
                                Td=it.value().toString().toDouble();

                             }
                            if(it2!=map.end()-1)
                            {
                            if(it2.key()==TD_k)
                            {
                                TD=it2.value().toString().toDouble();
                            }
                      }
                 it++;
                  }
                  qDebug()<<Td;
                  qDebug()<<TD;
                  if(ui->radioButton_4->isChecked())
                  {
                  IEI_Iei(Td,TD);
                  }
                  else
                      if(ui->radioButton_3->isChecked())
                  {
                      IEI_Iei_v(Td,TD);
                  }


}

void Pressing::IEI_Iei (double Td, double TD)
{
    ES=EI+TD;
    auto map1 = temp2.toVariantMap();
    //qDebug()<<map1;
    for(auto it=map1.begin()+2; it!=map1.end();it++)
    {
        if(it.key()==s1)
        {
            ei=it.value().toString().toDouble();
        }
    }
    qDebug()<<ei;
    es=ei+Td;
    qDebug()<<es;
    N=es-EI;
    qDebug()<<N;
}

void Pressing::IEI_Iei_v (double Td, double TD)
{
    qDebug()<<"yes";
    ei1=es1-Td;
    qDebug()<<ei1;
    QString s2=s1.toLower();
    qDebug()<<s2;
    auto map1 = temp2.toVariantMap();
    qDebug()<<map1;
    for(auto it=map1.begin()+2; it!=map1.end();it++)
    {
        if(it.key()==s2)
        {
            ei=it.value().toString().toDouble();
        }
    }
    qDebug()<<ei;
    es=ei+Td;
    EI1-=es;
    ES1=EI1+TD;
    N=es1-EI1;
}



