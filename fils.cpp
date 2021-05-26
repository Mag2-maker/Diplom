#include "fils.h"
#include <QString>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>
#include <QVector>

Fils::Fils()
{

}

QByteArray Fils::loadJson(QString filename)
{

    QByteArray val;
    QFile jsonFile(filename);
    jsonFile.open(QFile::ReadOnly);
    val = jsonFile.readAll();
    jsonFile.close();
    return val;
}

QJsonObject Fils::TD_Td(QByteArray file, double d)
{
    QJsonDocument doc = QJsonDocument::fromJson(file);
    QJsonArray jsonArray = doc.array();
    QJsonObject temp;
   for (int i=0; i < jsonArray.size(); i++)
     {
         temp =  jsonArray.at(i).toObject();
        if(d > temp.value("A").toString().toDouble() && d <=temp.value("B").toString().toDouble())
        {
            return temp;
          // qDebug() << temp;
            break;
        }
   }
}

QJsonObject Fils::TD_Td_p(QByteArray file, double d)
{
    QJsonDocument doc = QJsonDocument::fromJson(file);
    QJsonArray jsonArray = doc.array();
    QJsonObject temp;
   for (int i=0; i < jsonArray.size(); i++)
     {
         temp =  jsonArray.at(i).toObject();
        if(d > temp.value("СВ.").toString().toDouble() && d <=temp.value("До включ.").toString().toDouble())
        {
            return temp;
          // qDebug() << temp;
            break;
        }
   }
}


//             auto map = temp.toVariantMap();
//             for(auto it=map.begin()+1; it!=map.end()-1;it++)
//             {
//                 auto it2=it; it2++;

//                       if(it.value().toString().toDouble()<=TN/2)
//                       {
//                           Td=it.value().toString().toDouble();
//                           Td_k=it.key();
//                        }
//                       if(it2!=map.end()-1)
//                       {
//                       if(it2.value().toString().toDouble()<=TN-TD && it2.value().toString().toDouble()>TD)
//                       {
//                           TD=it2.value().toString().toDouble();
//                           TD_k=it2.key();
//                       }
//                 }
//                       if(Td==TD)
//                       {
//                           it2--;
//                           Td=it2.value().toString().toDouble();
//                           Td_k=it2.key();
//                       }
//            }
//             Td_k.remove(0,2);
//             TD_k.remove(0,2);
//             if (TD+TD<=TN)
//             {
//                 Ei_ei(TD,TD, TD_k, TD_k, d);
//             }
//             if(Td+Td<=TN)
//             {
//                 Ei_ei(Td,Td, Td_k, Td_k,d);
//             }
//             if (TD+Td<=TN)
//             {
//                 Ei_ei(TD, Td, TD_k, Td_k,d);
//             }
//             if (Td+TD<=TN)
//             {
//                 Ei_ei(Td, TD, Td_k, TD_k,d);
//             }
//}

QJsonObject Fils::EI_ei(QByteArray file1, double d)
{
    //QByteArray var1=loadJson("output(1++).json");
       QJsonDocument doc1 = QJsonDocument::fromJson(file1);
       QJsonArray jsonArray1 = doc1.array();
       QJsonObject temp1;
       for (int i=0; i < jsonArray1.size(); i++)
         {
             temp1 =  jsonArray1.at(i).toObject();
             //qDebug() << temp1;
            if(d > temp1.value("A").toString().toDouble() && d <=temp1.value("B").toString().toDouble())
            {
                return temp1;
              //qDebug() << temp1;
                break;
            }
       }
}
//       ES=EI+ITD;
//       //QVector<QString> keys;
//       qDebug()<<ES;
//       double ei_r=ES+9.245,ei=0;
//       qDebug()<<ei_r;
//       auto map1 = temp1.toVariantMap();
//      for(auto it=map1.begin()+2; it!=map1.end();it++)
//      {
//          if(it.value().toString().toDouble()>=ei_r && it.value().toString().toDouble()>=ei)
//          {
//              ei=it.value().toString().toDouble();
//              ei_k=it.key();
//              break;
//      }
//      }
//QString EI_k="H";
//      ei_k.append(ITd_k);
//      EI_k.append(ITD_k);
//      qDebug()<<ei;
//      qDebug()<<ei_k;
//      qDebug()<<EI_k;
//      es=ei+ITd;
//      qDebug()<<es;
//      double N_max=es-EI;
//      double N_min=ei-ES;

//      if(N_max<=331.223 && N_min>=9.245)
//      {
//          qDebug()<<"YEs";
//          keys.push_back(EI_k);
//          keys.push_back(ei_k);
//          qDebug()<<keys;
//      }
//      return N_max;
//      //qDebug()<<keys;
//}

