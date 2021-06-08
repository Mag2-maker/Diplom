#include "fils.h"
#include "landing.h"
#include "mainwindow.h"
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
#include <QMessageBox>
#define M_PI 3.14159265358979323846

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->radioButton_2->setChecked(true);
    ui->radioButton_4->setChecked(true);
    ui->tabWidget->setCurrentIndex(0);
    Fils objA;
    QByteArray file2 = objA.loadJson(":resource/fils/iron.json");
    QJsonDocument doc = QJsonDocument::fromJson(file2);
    QJsonArray jsonArray = doc.array();
    QJsonObject temp;
    for (int i=0; i < jsonArray.size(); i++)
    {
        temp =  jsonArray.at(i).toObject();
        ui->comboBox->addItem(temp.value("Марка").toString());
        ui->comboBox_2->addItem(temp.value("Марка").toString());
        ui->comboBox_7->addItem(temp.value("Марка").toString());
        ui->comboBox_8->addItem(temp.value("Марка").toString());
    }
    connect(ui->comboBox, SIGNAL(currentIndexChanged(QString)), SLOT(see()));
    connect(ui->comboBox_2, SIGNAL(currentIndexChanged(QString)), SLOT(see()));
    connect(ui->comboBox_7, SIGNAL(currentIndexChanged(QString)), SLOT(see()));
    connect(ui->comboBox_8, SIGNAL(currentIndexChanged(QString)), SLOT(see()));

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{    /*if(ui->lineEdit->text()=="" || ui->lineEdit_2->text()=="" ||
            ui->lineEdit_3->text()=="" || ui->lineEdit_4->text()=="" ||
            ui->lineEdit_5->text()=="" || ui->lineEdit_6->text()=="" ||
            ui->lineEdit_7->text()=="" || ui->lineEdit_8->text()=="" ||
            ui->lineEdit_9->text()=="" || ui->lineEdit_10->text()=="" ||
            ui->lineEdit_11->text()=="" || ui->lineEdit_12->text()=="" ||
            ui->lineEdit_13->text()=="" || ui->lineEdit_14->text()=="" ||
            ui->lineEdit_15->text()=="" || ui->lineEdit_16->text()=="")
        QMessageBox::warning(0, "Ошибка", "Введите текст. Не все поля заполнены");*/
    data_main objA;

    if (user_input_is_correct()){objA.d = ui->lineEdit->text().toDouble();
        objA.d1 = ui->lineEdit_2->text().toDouble();
        objA.d2 = ui->lineEdit_3->text().toDouble();
        objA.l = ui->lineEdit_4->text().toDouble()*pow(10.0,-3.0);
        objA.M = ui->lineEdit_5->text().toDouble();
        objA.A = ui->lineEdit_6->text().toDouble();
        objA.f = ui->lineEdit_7->text().toDouble();
        objA.k = ui->lineEdit_8->text().toDouble();
        objA.R1 = ui->lineEdit_9->text().toDouble();
        objA.R2 = ui->lineEdit_10->text().toDouble();
        objA.E1 = ui->lineEdit_11->text().toDouble() * pow(10.0,5.0);
        objA.E2 = ui->lineEdit_12->text().toDouble() * pow(10.0,5.0);
        objA.qt1 = ui->lineEdit_13->text().toDouble();
        objA.qt2 =ui->lineEdit_14->text().toDouble();
        objA.n1 = ui->lineEdit_15->text().toDouble();
        objA.n2 = ui->lineEdit_16->text().toDouble();
        objA.radio_button=radio_button();
        qDebug()<<objA.radio_button;
        //emit LandingClicked(objA);
        if (objA.d2>objA.d1 && objA.d>objA.d1)
        {
            emit LandingClicked(objA);
        }
        else
        {
          QMessageBox::warning(0, "Ошибка", "Введены некорректные значения");
        }
       }else{QMessageBox::warning(0, "Ошибка", "Введите значения. Не все поля заполнены");};
//    if(objA.d2>objA.d1)
//    {
//        emit LandingClicked(objA);
//    }
//    else
//    {
//        QMessageBox::warning(0, "Ошибка", "Введены некорректные значения1");
//    }
//    emit LandingClicked(objA);
}

 void MainWindow::GetDataAndFillWindow(Landing& objD)
 {
     //objD.ITD_ITd(objB.TN,ui);
//             QVector<double> kkkl= objC.N;
//             for (const auto& i: kkkl)
//             {
//                 double qmax_p = i*pow(10.0,-6.0)/objA.d*(c1/objA.E1 + c2/objA.E2);
//                 double Rn = objA.f*qmax_p*M_PI*objA.d*objA.l;
//                 qDebug()<<Rn;
//                 double Rrasp = 2.0*objA.f*qmax_p*M_PI*objA.d*objA.l;
//                 qDebug()<<Rrasp;
//             }
             QStandardItemModel *model = new QStandardItemModel;
             if(!objD.N.empty())
             {
             //QStandardItemModel *model = new QStandardItemModel;
             QStringList horizontalHeader;
             horizontalHeader.append("Td_k");
             horizontalHeader.append("TD_k");
             horizontalHeader.append("EI");
             horizontalHeader.append("ES");
             horizontalHeader.append("ei");
             horizontalHeader.append("es");

             //Заголовки строк
             QStringList verticalHeader;
             for (int i=1; i<=objD.N.size();i++)
             {
                 verticalHeader.append(QString::number(i));
             }
             model->setHorizontalHeaderLabels(horizontalHeader);
             model->setVerticalHeaderLabels(verticalHeader);
             int index=0;
             for (int row=0;row<model->rowCount();row++)
             {
                 for (int column=0;column < 2;column++)
                 {
                     QStandardItem *item;
                     item = new QStandardItem(QString(objD.keys[index]));
                     item->setTextAlignment(Qt::AlignCenter);
                     model->setItem(row, column, item);
                     index++;
                 }
             }
             int index2=0;
             for (int row=0;row<model->rowCount();row++)
             {
                 for (int column=2;column < model->columnCount();column++)
                 {
                     QStandardItem *item;
                     item = new QStandardItem(QString(QString::number(objD.ooop[index2])));
                     item->setTextAlignment(Qt::AlignCenter);
                     model->setItem(row, column, item);
                     index2++;
                 }
             }

             ui->tableView->setModel(model);
             ui->tableView->resizeRowsToContents();
             ui->tableView->resizeColumnsToContents();
             ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
             ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
             ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
             objD.keys.clear();

             objD.ooop.clear();
             objD.N.clear();
         }
             else
             {
                 QMessageBox::warning(0, "Ошибка", "Введены некорректные значения");
                 ui->tableView->reset();
             }
 }














//void MainWindow::on_pushButton_clicked()
//{
//    double d = ui->lineEdit->text().toDouble();
//    double d1 = ui->lineEdit_2->text().toDouble();
//    double d2 = ui->lineEdit_3->text().toDouble();
//    double l = ui->lineEdit_4->text().toDouble()*pow(10.0,-3.0);
//    double M = ui->lineEdit_5->text().toDouble();
//    double A = ui->lineEdit_6->text().toDouble();
//    double f = ui->lineEdit_7->text().toDouble();
//    double k = ui->lineEdit_8->text().toDouble();
//    double R1 = ui->lineEdit_9->text().toDouble();
//    double R2 = ui->lineEdit_10->text().toDouble();
//    double E1 = ui->lineEdit_11->text().toDouble() * pow(10.0,5.0);
//    double E2 = ui->lineEdit_12->text().toDouble() * pow(10.0,5.0);
//    double qt1 = ui->lineEdit_13->text().toDouble();
//    double qt2 =ui->lineEdit_14->text().toDouble();
//    double n1 = ui->lineEdit_15->text().toDouble();
//    double n2 = ui->lineEdit_16->text().toDouble();

//    double Qm = (k*sqrt(((4.0*M*M)/(d*d))+A*A))/(f*M_PI*d*l)*0.001;
//    qDebug()<<"Qm"<<Qm;
//    double c1 = ((1.0+pow(d1/d, 2.0))/(1.0-pow(d1/d, 2.0)))-n1;
//    qDebug()<<"c1"<<c1;
//    double c2 = ((1.0+pow(d/d2, 2.0))/(1.0-pow(d/d2, 2.0)))+n2;
//    qDebug()<<"c2"<<c2;
//    double delta = (Qm*d*(c1/E1 + c2/E2))*1000;
//    qDebug()<<"delta"<<delta;
//    double delta_n_min = delta+1.2*(R1+R2);
//    qDebug()<<"delta min"<<delta_n_min;
//    double qmax1 = 0.58*qt1*(1.0-pow(d1/d,2.0));
//    qDebug()<<"qmax1"<<qmax1;
//    double qmax2 = 0.58*qt2*(1.0-pow(d/d2,2.0));
//    qDebug()<<"qmax2"<<qmax2;
//    double qmax = 0;

//    if(qmax1-qmax2>=0) qmax = qmax2;
//    else qmax = qmax1;
//    double delta_max = (qmax*d*(c1/E1 + c2/E2))*pow(10.0,3.0);
//    qDebug()<<"delta max"<<delta_max;
//    double delta_n_max = delta_max+1.2*(R1+R2);
//    qDebug()<<"delta n max"<<delta_n_max;
//    double TN = delta_n_max - delta_n_min;
//    qDebug()<<"TN"<<TN;
//    qDebug()<<TN;
//    Fils objA;
//    Landing objB;
//    QByteArray file = objA.loadJson(":resource/fils/qualifications(2).json");
//    QByteArray file1 = objA.loadJson(":resource/fils/deviations.json");
//    QJsonObject temp = objA.TD_Td(file,d);
//    qDebug()<<temp;
//    QJsonObject temp1 = objA.EI_ei(file1,d);
//    objB.Variable(delta_n_min, delta_n_max,temp1);
//    objB.ITD_ITd(temp, TN,ui);
//    QVector<double> kkkl= objB.N;
//    for (const auto& i: kkkl)
//    {
//        double qmax_p = i*pow(10.0,-6.0)/d*(c1/E1 + c2/E2);
//        double Rn = f*qmax_p*M_PI*d*l;
//        qDebug()<<Rn;
//        double Rrasp = 2.0*f*qmax_p*M_PI*d*l;
//        qDebug()<<Rrasp;
//    }

//    QStandardItemModel *model = new QStandardItemModel;
//    QStringList horizontalHeader;
//    horizontalHeader.append("Td_k");
//    horizontalHeader.append("TD_k");
//    horizontalHeader.append("EI");
//    horizontalHeader.append("ES");
//    horizontalHeader.append("ei");
//    horizontalHeader.append("es");

//    //Заголовки строк
//    QStringList verticalHeader;
//    for (int i=1; i<=objB.N.size();i++)
//    {
//        verticalHeader.append(QString::number(i));
//    }
//    model->setHorizontalHeaderLabels(horizontalHeader);
//    model->setVerticalHeaderLabels(verticalHeader);
//    int index=0;
//    for (int row=0;row<model->rowCount();row++)
//    {
//        for (int column=0;column < 2;column++)
//        {
//            QStandardItem *item;
//            item = new QStandardItem(QString(objB.keys[index]));
//            item->setTextAlignment(Qt::AlignCenter);
//            model->setItem(row, column, item);
//            index++;
//        }
//    }
//    int index2=0;
//    for (int row=0;row<model->rowCount();row++)
//    {
//        for (int column=2;column < model->columnCount();column++)
//        {
//            QStandardItem *item;
//            item = new QStandardItem(QString(QString::number(objB.ooop[index2])));
//            item->setTextAlignment(Qt::AlignCenter);
//            model->setItem(row, column, item);
//            index2++;
//        }
//    }

//    ui->tableView->setModel(model);
//    ui->tableView->resizeRowsToContents();
//    ui->tableView->resizeColumnsToContents();
//    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
//    objB.keys.clear();
//    objB.ooop.clear();
//    objB.N.clear();
//}

void MainWindow::on_pushButton_2_clicked()
{
    data_main objA;
    if (user_input_is_correct())
    {
    objA.d = ui->lineEdit_31->text().toDouble();
    objA.d1 = ui->lineEdit_19->text().toDouble();
    objA.d2 = ui->lineEdit_21->text().toDouble();
    objA.l = ui->lineEdit_32->text().toDouble()*pow(10.0,-3.0);
    objA.f = ui->lineEdit_25->text().toDouble();
    objA.E1 = ui->lineEdit_29->text().toDouble() * pow(10.0,5.0);
    objA.E2 = ui->lineEdit_23->text().toDouble() * pow(10.0,5.0);
    objA.n1 = ui->lineEdit_28->text().toDouble();
    objA.n2 = ui->lineEdit_18->text().toDouble();
    objA.EI = ui->lineEdit_20->text();
    objA.ei = ui->lineEdit_26->text();
    objA.radio_button=radio_button();
    qDebug()<<objA.radio_button;
    //emit LandingClicked(objA);
    if (objA.d2>objA.d1 && objA.d>objA.d1)
    {
        emit LandingClicked_2(objA);
    }
    else
    {
      QMessageBox::warning(0, "Ошибка", "Введены некорректные значения");
    }
   }else{QMessageBox::warning(0, "Ошибка", "Введите значения. Не все поля заполнены");};

}


void MainWindow::GetDataAndFillWindow_2(data_pressing& objD)
{
        data_main objA;
        qDebug()<<objA.EI;
        qDebug()<<objA.ei;
        qDebug()<<objD.Fmax1;
        qDebug()<<objD.Qmax1;
        QStandardItemModel *model = new QStandardItemModel;
        QStandardItem *item;
        QStringList horizontalHeader;
        horizontalHeader.append("Td_k");
        horizontalHeader.append("TD_k");
        horizontalHeader.append("Fраспр");
        horizontalHeader.append("Fвыпр");
        QStringList verticalHeader;
        verticalHeader.append(QString("1"));
        model->setHorizontalHeaderLabels(horizontalHeader);
        model->setVerticalHeaderLabels(verticalHeader);
        item = new QStandardItem(QString(objA.EI));
        model->setItem(0, 0, item);
        item->setTextAlignment(Qt::AlignCenter);

        item = new QStandardItem(QString(objA.ei));
        model->setItem(0, 1, item);
        item->setTextAlignment(Qt::AlignCenter);

        item = new QStandardItem(QString(objD.Fmax1));
        model->setItem(0, 2, item);
        item->setTextAlignment(Qt::AlignCenter);

        item = new QStandardItem(QString(objD.Qmax1));
        model->setItem(0, 3, item);
        item->setTextAlignment(Qt::AlignCenter);
//        ui->tableView_2->setModel(model);
//        ui->tableView_2->resizeRowsToContents();
//        ui->tableView_2->resizeColumnsToContents();
//        ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//        ui->tableView_2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//        ui->tableView_2->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);

}











//    QString EI_z=EI;
//    QString ei_z=ei;
//    QString s=ei;
//    qDebug()<<s;
//    double c1 = abs(((1.0+pow(d1/d, 2.0))/(1.0-pow(d1/d, 2.0)))-n1);
//    qDebug()<<"c1"<<c1;
//    double c2 = abs(((1.0+pow(d/d2, 2.0))/(1.0-pow(d/d2, 2.0)))+n2);
//    qDebug()<<"c2"<<c2;
//    EI.remove(0,1);
//    ei.remove(0,1);
//    s.chop(1);
//    qDebug()<<s;
//    QString TD_k="IT";
//    QString Td_k="IT";
//    TD_k.append(EI);
//    Td_k.append(ei);
//    Fils objA;
//    Pressing objB;
//    QByteArray file = objA.loadJson(":resource/fils/qualifications.json");
//    QByteArray file1 = objA.loadJson(":resource/fils/deviations.json");
//    QJsonObject temp = objA.TD_Td_p(file,d);
//    QJsonObject temp1 = objA.EI_ei(file1,d);
//    qDebug()<<temp;
//    qDebug()<<temp1;
//    objB.Variable(s,temp1);
//    objB.ITD_ITd(temp, TD_k,Td_k,ui);
//    double Nmax=objB.N;
//    qDebug()<<Nmax;
//    double pmax=(Nmax*pow(10.0,3.0))/(d*(c1/E1+c2/E2));
//    double Fmax=pmax*M_PI*d*l*f*pow(10.0,-2.0);
//    double Qmax=1.15*Fmax;

//    qDebug()<<Fmax<<" "<<Qmax;
//    QString Fmax1,Qmax1;
//    Fmax1.setNum(Fmax);
//    Qmax1.setNum(Qmax);
//    QStandardItemModel *model = new QStandardItemModel;
//    QStandardItem *item;
//    QStringList horizontalHeader;
//    horizontalHeader.append("Td_k");
//    horizontalHeader.append("TD_k");
//    horizontalHeader.append("Fраспр");
//    horizontalHeader.append("Fвыпр");
//    QStringList verticalHeader;
//    verticalHeader.append(QString("1"));
//    model->setHorizontalHeaderLabels(horizontalHeader);
//    model->setVerticalHeaderLabels(verticalHeader);
//    item = new QStandardItem(QString(EI_z));
//    model->setItem(0, 0, item);
//    item->setTextAlignment(Qt::AlignCenter);

//    item = new QStandardItem(QString(ei_z));
//    model->setItem(0, 1, item);
//    item->setTextAlignment(Qt::AlignCenter);

//    item = new QStandardItem(QString(Fmax1));
//    model->setItem(0, 2, item);
//    item->setTextAlignment(Qt::AlignCenter);

//    item = new QStandardItem(QString(Qmax1));
//    model->setItem(0, 3, item);
//    item->setTextAlignment(Qt::AlignCenter);

//    ui->tableView_2->setModel(model);
//    ui->tableView_2->resizeRowsToContents();
//    ui->tableView_2->resizeColumnsToContents();
//    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableView_2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableView_2->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);

//}


bool MainWindow::user_input_is_correct()
{
    QObject* button = QObject::sender();
    if(button==ui->pushButton)
    {
    if(ui->lineEdit->text()=="" || ui->lineEdit_2->text()=="" ||
               ui->lineEdit_3->text()=="" || ui->lineEdit_4->text()=="" ||
               ui->lineEdit_5->text()=="" || ui->lineEdit_6->text()=="" ||
               ui->lineEdit_7->text()=="" || ui->lineEdit_8->text()=="" ||
               ui->lineEdit_9->text()=="" || ui->lineEdit_10->text()=="" ||
               ui->lineEdit_11->text()=="" || ui->lineEdit_12->text()=="" ||
               ui->lineEdit_13->text()=="" || ui->lineEdit_14->text()=="" ||
               ui->lineEdit_15->text()=="" || ui->lineEdit_16->text()=="")
    {
        return false;
    }
    else
    {
        return true;
    }
    }
    else
    {
        if (button==ui->pushButton_2)
        {
            if(ui->lineEdit_31->text()=="" || ui->lineEdit_19->text()=="" ||
                       ui->lineEdit_21->text()=="" || ui->lineEdit_32->text()=="" ||
                       ui->lineEdit_25->text()=="" || ui->lineEdit_29->text()=="" ||
                       ui->lineEdit_23->text()=="" || ui->lineEdit_28->text()=="" ||
                       ui->lineEdit_18->text()=="" || ui->lineEdit_20->text()=="" ||
                       ui->lineEdit_26->text()=="")
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
}


bool MainWindow::radio_button()
{
    if (ui->radioButton->isChecked() || ui->radioButton_3->isChecked())
    {
        return false;
    }
       if(ui->radioButton_2->isChecked() || ui->radioButton_4->isChecked())
       {
            return true;
       }
}

void MainWindow::on_action_triggered()
{
    Menu ob1;
    ob1.SaveFile(ui);
}

void MainWindow::on_action_2_triggered()
{
    QApplication::quit();
}


void MainWindow::see()
{
    Values obj3;
    obj3.see(ui);
}
