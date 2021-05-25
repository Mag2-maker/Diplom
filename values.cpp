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
         QByteArray file2 = objA.loadJson(":resource/fils/iron.json");
         QJsonDocument doc = QJsonDocument::fromJson(file2);
         QJsonArray jsonArray = doc.array();
         QJsonObject temp;
         for (int i=0; i < jsonArray.size(); i++)
         {
              temp =  jsonArray.at(i).toObject();
              if(ui->comboBox->currentText()==temp.value("Марка").toString())
              {
                    auto map = temp.toVariantMap();
                    ui->lineEdit_11->setText(QString::number(map.value("E").toString().toDouble()));
                    ui->lineEdit_13->setText(QString::number(map.value("qt").toString().toDouble()));
                    ui->lineEdit_15->setText(QString::number(map.value("v").toString().toDouble()));
              }

              if(ui->comboBox_2->currentText()==temp.value("Марка").toString())
              {
                    auto map = temp.toVariantMap();
                    ui->lineEdit_12->setText(QString::number(map.value("E").toString().toDouble()));
                    ui->lineEdit_14->setText(QString::number(map.value("qt").toString().toDouble()));
                    ui->lineEdit_16->setText(QString::number(map.value("v").toString().toDouble()));
              }
              if(ui->comboBox_7->currentText()==temp.value("Марка").toString())
              {
                    auto map = temp.toVariantMap();
                    ui->lineEdit_29->setText(QString::number(map.value("E").toString().toDouble()));
                    ui->lineEdit_28->setText(QString::number(map.value("v").toString().toDouble()));
              }
              if(ui->comboBox_8->currentText()==temp.value("Марка").toString())
              {
                    auto map = temp.toVariantMap();
                    ui->lineEdit_23->setText(QString::number(map.value("E").toString().toDouble()));
                    ui->lineEdit_18->setText(QString::number(map.value("v").toString().toDouble()));
              }
         }
}
