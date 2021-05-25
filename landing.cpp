#include "landing.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>
#include <QVector>

Landing::Landing()
{

}


void Landing::Variable (double delta_n_min, double delta_max, QJsonObject temp1)
{
    delta_n_min_1= delta_n_min;
    delta_max_1=delta_max;
    temp2=temp1;
}


void Landing::ITD_ITd(QJsonObject temp, double TN,Ui::MainWindow *ui)
{
    auto map = temp.toVariantMap();
    //temp2=temp1;
    //d=dd;
    auto it=map.begin()+1;
    auto it2=it;
    for(; it!=map.end()-1;)
    {
        it2++;

        if(it.value().toString().toDouble()<=TN/2)
        {
            Td=it.value().toString().toDouble();
            Td_k=it.key();
        }
        if(it2!=map.end()-1)
        {
            if(it2.value().toString().toDouble()<=TN-TD && it2.value().toString().toDouble()>TD)
            {
                TD=it2.value().toString().toDouble();
                TD_k=it2.key();
            }
        }
        //                           if(Td==TD)
        //                           {
        //                               it2--;
        //                               Td=it2.value().toString().toDouble();
        //                               Td_k=it2.key();
        //                           }
        it++;
    }

    if(Td==TD)
    {
        it2--;
        TD=it2.value().toString().toDouble();
        TD_k=it2.key();
    }
    qDebug()<<"TD"<<TD;
    qDebug()<<"Td"<<Td;
    if(ui->radioButton_2->isChecked())
    {
        if(TD+TD<=TN && Td+Td<=TN && TD+Td<=TN && Td+TD<=TN )
        {
            Td_k.remove(0,2);
            TD_k.remove(0,2);
            IEI_Iei(TD,TD, TD_k, TD_k);
            IEI_Iei(Td,Td, Td_k, Td_k);
            IEI_Iei(TD,Td, TD_k, Td_k);
            IEI_Iei(Td,TD, Td_k, TD_k);
        }
        else
        {
            it=it-2;
            it2=it2-2;
            Td=it2.value().toString().toDouble();
            Td_k=it2.key();
            TD=it.value().toString().toDouble();
            TD_k=it.key();
            //                     TD=it2.value().toString().toDouble();
            //                     TD_k=it2.key();
            Td_k.remove(0,2);
            TD_k.remove(0,2);
            qDebug()<<"TD"<<TD;
            qDebug()<<"Td"<<Td;
            qDebug()<<"TD_k"<<TD_k;
            qDebug()<<"Td_k"<<Td_k;
            IEI_Iei(TD,TD, TD_k, TD_k);
            IEI_Iei(Td,Td, Td_k, Td_k);
            IEI_Iei(TD,Td, TD_k, Td_k);
            IEI_Iei(Td,TD, Td_k, TD_k);
        }
    }
    else
    {
        if (ui->radioButton->isChecked())
        {
            if(TD+TD<=TN && Td+Td<=TN && TD+Td<=TN && Td+TD<=TN )
            {
                Td_k.remove(0,2);
                TD_k.remove(0,2);
                IEI_Iei_v(TD,TD, TD_k, TD_k);
                IEI_Iei_v(Td,Td, Td_k, Td_k);
                IEI_Iei_v(TD,Td, TD_k, Td_k);
                IEI_Iei_v(Td,TD, Td_k, TD_k);
            }
            else
            {
                it=it-2;
                it2=it2-2;
                Td=it2.value().toString().toDouble();
                Td_k=it2.key();
                TD=it.value().toString().toDouble();
                TD_k=it.key();
                //                     TD=it2.value().toString().toDouble();
                //                     TD_k=it2.key();
                Td_k.remove(0,2);
                TD_k.remove(0,2);
                qDebug()<<"TD"<<TD;
                qDebug()<<"Td"<<Td;
                qDebug()<<"TD_k"<<TD_k;
                qDebug()<<"Td_k"<<Td_k;
                IEI_Iei_v(TD,TD, TD_k, TD_k);
                IEI_Iei_v(Td,Td, Td_k, Td_k);
                IEI_Iei_v(TD,Td, TD_k, Td_k);
                IEI_Iei_v(Td,TD, Td_k, TD_k);
            }
        }
    }
    //                    qDebug()<<"TD"<<TD;
    //                    qDebug()<<"Td"<<Td;
    //                 Td_k.remove(0,2);
    //                 TD_k.remove(0,2);
    //                 if (TD+TD<=TN)
    //                 {
    //                     IEI_Iei(TD,TD, TD_k, TD_k);

    //                 }
    //                 if (Td+Td<=TN)
    //                 {
    //                     IEI_Iei(Td,Td, Td_k, Td_k);
    //                 }
    //                 if (TD+Td<=TN)
    //                 {
    //                     IEI_Iei(TD, Td, TD_k, Td_k);
    //                 }
    //                 if (Td+TD<=TN)
    //                 {
    //                     IEI_Iei(Td, TD, Td_k, TD_k);
    //                 }

}

//void Landing::ITD_ITd_v(QJsonObject temp, double TN)
//{
//    auto map = temp.toVariantMap();
//    //temp2=temp1;
//    //d=dd;
//    auto it=map.begin()+1;
//    auto it2=it;
//                 for(; it!=map.end()-1;)
//                 {
//                     //auto it2=it;
//                     it2++;

//                           if(it.value().toString().toDouble()<=TN/2)
//                           {
//                               Td=it.value().toString().toDouble();
//                               Td_k=it.key();
//                            }
//                           if(it2!=map.end()-1)
//                           {
//                           if(it2.value().toString().toDouble()<=TN-TD && it2.value().toString().toDouble()>TD)
//                           {
//                               TD=it2.value().toString().toDouble();
//                               TD_k=it2.key();
//                           }
//                     }
////                           if(Td==TD)
////                           {
////                               it2--;
////                               TD=it2.value().toString().toDouble();
////                               TD_k=it2.key();
////                           }
//                           it++;
//                }
//                 qDebug()<<"TD"<<TD;
//                 qDebug()<<"Td"<<Td;
////                 Td_k.remove(0,2);
////                 TD_k.remove(0,2);
////                 if (TD+TD<=TN)
////                 {
////                     IEI_Iei_v(TD,TD, TD_k, TD_k);

////                 }
////                 if (Td+Td<=TN)
////                 {
////                     IEI_Iei_v(Td,Td, Td_k, Td_k);
////                 }
////                 if (TD+Td<=TN)
////                 {
////                     IEI_Iei_v(TD,Td, TD_k, Td_k);
////                 }
////                 if (Td+TD<=TN)
////                 {
////                     IEI_Iei_v(Td,TD, Td_k, TD_k);
////                 }
//                 if(Td==TD)
//                 {
//                     it2--;
//                     TD=it2.value().toString().toDouble();
//                     TD_k=it2.key();
//                 }
//                 qDebug()<<"TD"<<TD;
//                 qDebug()<<"Td"<<Td;
//                 if(TD+TD<=TN && Td+Td<=TN && TD+Td<=TN && Td+TD<=TN )
//                 {
//                     Td_k.remove(0,2);
//                     TD_k.remove(0,2);
//                     IEI_Iei_v(TD,TD, TD_k, TD_k);
//                     IEI_Iei_v(Td,Td, Td_k, Td_k);
//                     IEI_Iei_v(TD,Td, TD_k, Td_k);
//                     IEI_Iei_v(Td,TD, Td_k, TD_k);
//                 }
//                 else
//                 {
//                     it=it-2;
//                     it2=it2-2;
//                     Td=it2.value().toString().toDouble();
//                     Td_k=it2.key();
//                     TD=it.value().toString().toDouble();
//                     TD_k=it.key();
////                     TD=it2.value().toString().toDouble();
////                     TD_k=it2.key();
//                     Td_k.remove(0,2);
//                     TD_k.remove(0,2);
//                     qDebug()<<"TD"<<TD;
//                     qDebug()<<"Td"<<Td;
//                     qDebug()<<"TD_k"<<TD_k;
//                     qDebug()<<"Td_k"<<Td_k;
//                     IEI_Iei_v(TD,TD, TD_k, TD_k);
//                     IEI_Iei_v(Td,Td, Td_k, Td_k);
//                     IEI_Iei_v(TD,Td, TD_k, Td_k);
//                     IEI_Iei_v(Td,TD, Td_k, TD_k);
//                 }

//    }

void Landing::IEI_Iei(double ITD, double ITd, QString ITD_k, QString ITd_k)
{
    qDebug()<<"Отверстие";
    ES=EI+ITD;
    qDebug()<<ES;
    double ei_r=ES+delta_n_min_1,ei=0;
    qDebug()<<ei_r;
    auto map1 = temp2.toVariantMap();
    for(auto it=map1.begin()+2; it!=map1.end();it++)
    {
        if(it.value().toString().toDouble()>=ei_r && it.value().toString().toDouble()>=ei)
        {
            ei=it.value().toString().toDouble();
            ei_k=it.key();
            break;
        }
    }

    QString EI_k="H";
    ei_k.append(ITd_k);
    EI_k.append(ITD_k);
    qDebug()<<ei_k;
    qDebug()<<EI_k;
    qDebug()<<ei;
    qDebug()<<ei_k;
    qDebug()<<EI_k;
    es=ei+ITd;
    qDebug()<<es;
    double N_max=es-EI;
    double N_min=ei-ES;

    if(N_max<=delta_max_1 && N_min>=delta_n_min_1)
    {
        qDebug()<<"YEs";
        keys.push_back(EI_k);
        keys.push_back(ei_k);
        N.push_back(N_max);
        ooop.push_back(EI);ooop.push_back(ES);ooop.push_back(ei);ooop.push_back(es);
        qDebug()<<ooop;
        qDebug()<<keys;
    }
    //return N_max;
    //qDebug()<<keys;
}

void Landing::IEI_Iei_v(double ITD, double ITd, QString ITD_k, QString ITd_k)
{
    qDebug()<<"Вал";
    ES=EI+ITD;
    qDebug()<<"ES"<<ES;
    double ei_r=ES+delta_n_min_1,ei=0, ei1=0;
    qDebug()<<"ei_r"<<ei_r;
    auto map3 = temp2.toVariantMap();
    QString EI_k1;
    for(auto it=map3.begin()+2; it!=map3.end();it++)
    {
        if(it.value().toString().toDouble()>=ei_r && it.value().toString().toDouble()>=ei)
        {
            ei=it.value().toString().toDouble();
            qDebug()<<ei;
            EI_k1=it.key().toUpper();
            break;
        }
    }
    qDebug()<<"ei"<<ei;
    ei_k1='h';
    EI_k1.append(ITd_k);
    ei_k1.append(ITD_k);
    es=ei+ITd;
    qDebug()<<"es"<<es;
    //qDebug()<<es;
    EI1=-es;
    qDebug()<<"EI1"<<EI1;
    ES1=EI1+ITD;
    qDebug()<<"ES1"<<ES1;
    qDebug()<<ES1;
    ei1=es1-ITd;
    qDebug()<<"ei1"<<ei1;
    qDebug()<<ei_k1;
    qDebug()<<EI_k1;
    double N_max=es1-EI1;
    double N_min=ei1-ES1;
    if(N_max<=delta_max_1 && N_min>=delta_n_min_1)
    {
        qDebug()<<"YEs";
        keys.push_back(EI_k1);
        keys.push_back(ei_k1);
        N.push_back(N_max);
        ooop.push_back(EI1);ooop.push_back(ES1);ooop.push_back(ei1);ooop.push_back(es1);
        qDebug()<<ooop;
    }

}


