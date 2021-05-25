#include "values.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>
Values::Values()
{

}

void Values::see(Ui::MainWindow *ui)
{

         Fils objA;
         QByteArray file2 = objA.loadJson("output(2).json");
         QJsonDocument doc = QJsonDocument::fromJson(file2);
         QJsonArray jsonArray = doc.array();
         QJsonObject temp;
         for (int i=0; i < jsonArray.size(); i++)
         {
              temp =  jsonArray.at(i).toObject();
              if(ui->comboBox->currentText()==temp.value("Марка").toString())
              {
                    auto map = temp.toVariantMap();
                    qDebug()<<map;
                    //auto mn=map.value("E").toString().toDouble();
                    //qDebug()<<mn;
                    ui->lineEdit_11->setText(QString::number(map.value("E").toString().toDouble()));
                    ui->lineEdit_13->setText(QString::number(map.value("qt").toString().toDouble()));
                    ui->lineEdit_15->setText(QString::number(map.value("v").toString().toDouble()));
              }

              if(ui->comboBox_2->currentText()==temp.value("Марка").toString())
              {
                    auto map = temp.toVariantMap();
                    qDebug()<<map;
                    //auto mn=map.value("E").toString().toDouble();
                    //qDebug()<<mn;
                    ui->lineEdit_12->setText(QString::number(map.value("E").toString().toDouble()));
                    ui->lineEdit_14->setText(QString::number(map.value("qt").toString().toDouble()));
                    ui->lineEdit_16->setText(QString::number(map.value("v").toString().toDouble()));
              }
         }
}
