#include "windowcontroller.h"
#include "data_struct.h"
#include"QDebug"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "landing.h"
#include "QMessageBox"
#define M_PI 3.14159265358979323846


WindowController::WindowController(MainWindow *w)
{
    window = w;
    InitializeConnections();
}

void WindowController::InitializeConnections()
{
    // сигналы от mainwindow в контроллер
     connect(window, SIGNAL(LandingClicked(data_main&)), this, SLOT(LandingChicked_handler(data_main&)));
     connect(window, SIGNAL(LandingClicked_2(data_main&)), this, SLOT(LandingChicked_handler_2(data_main&)));

     //сингалы от контроллера в mainwindow
     connect(this, SIGNAL(SendDataModelToForm(Landing&)), window, SLOT(GetDataAndFillWindow(Landing&)));
     connect(this, SIGNAL(SendDataModelToForm_2(data_pressing&)), window, SLOT(GetDataAndFillWindow_2(data_pressing&)));
}

void WindowController::LandingChicked_handler(data_main& objA)
{
   // data_main objA;
    //bool _radio_button=objA.radio_button;
    double Qm = (objA.k*sqrt(((4.0*objA.M*objA.M)/(objA.d*objA.d))+objA.A*objA.A))/(objA.f*M_PI*objA.d*objA.l)*0.001;
    qDebug()<<"Qm"<<Qm;
    double c1 = ((1.0+pow(objA.d1/objA.d, 2.0))/(1.0-pow(objA.d1/objA.d, 2.0)))-objA.n1;
    qDebug()<<"c1"<<c1;
    double c2 = ((1.0+pow(objA.d/objA.d2, 2.0))/(1.0-pow(objA.d/objA.d2, 2.0)))+objA.n2;
    qDebug()<<"c2"<<c2;
    double delta = (Qm*objA.d*(c1/objA.E1 + c2/objA.E2))*1000;
    qDebug()<<"delta"<<delta;
    double delta_n_min = delta+1.2*(objA.R1+objA.R2);
    qDebug()<<"delta min"<<delta_n_min;
    double qmax1 = 0.58*objA.qt1*(1.0-pow(objA.d1/objA.d,2.0));
    qDebug()<<"qmax1"<<qmax1;
    double qmax2 = 0.58*objA.qt2*(1.0-pow(objA.d/objA.d2,2.0));
    qDebug()<<"qmax2"<<qmax2;
    double qmax = 0;

    if(qmax1-qmax2>=0) qmax = qmax2;
    else qmax = qmax1;
    double delta_max = (qmax*objA.d*(c1/objA.E1 + c2/objA.E2))*pow(10.0,3.0);
    qDebug()<<"delta max"<<delta_max;
    double delta_n_max = delta_max+1.2*(objA.R1+objA.R2);
    qDebug()<<"delta n max"<<delta_n_max;
    data_controller objB;
    objB.TN = delta_n_max - delta_n_min;
    if (objB.TN>0)
    {
    Fils objC;
    Landing objD;
    QByteArray file = objC.loadJson(":resource/fils/qualifications(2).json");
    QByteArray file1 = objC.loadJson(":resource/fils/deviations.json");
    QJsonObject temp = objC.TD_Td(file,objA.d);
    qDebug()<<temp;
    QJsonObject temp1 = objC.EI_ei(file1,objA.d);
    objD.Variable(delta_n_min, delta_n_max,temp1,temp);
    objD.ITD_ITd(objB.TN,objA.radio_button);
    emit SendDataModelToForm(objD);
    }
    else
    {
        QMessageBox::warning(0, "Ошибка", "Введены некорректные значения");
    }
}


void WindowController::LandingChicked_handler_2(data_main& objA)
{
    QString EI_z=objA.EI;
        QString ei_z=objA.ei;
        QString s=objA.ei;
        qDebug()<<s;
        double c1 = abs(((1.0+pow(objA.d1/objA.d, 2.0))/(1.0-pow(objA.d1/objA.d, 2.0)))-objA.n1);
        qDebug()<<"c1"<<c1;
        double c2 = abs(((1.0+pow(objA.d/objA.d2, 2.0))/(1.0-pow(objA.d/objA.d2, 2.0)))+objA.n2);
        qDebug()<<"c2"<<c2;
        EI_z.remove(0,1);
        ei_z.remove(0,1);
        s.chop(1);
        qDebug()<<s;
        QString TD_k="IT";
        QString Td_k="IT";
        TD_k.append(EI_z);
        Td_k.append(ei_z);
        Fils objB;
        Pressing objC;
        QByteArray file = objB.loadJson(":resource/fils/qualifications.json");
        QByteArray file1 = objB.loadJson(":resource/fils/deviations.json");
        QJsonObject temp = objB.TD_Td_p(file,objA.d);
        QJsonObject temp1 = objB.EI_ei(file1,objA.d);
        qDebug()<<temp;
        qDebug()<<temp1;
        objC.Variable(s,temp1);
        objC.ITD_ITd(temp, TD_k,Td_k,objA.radio_button);
        double Nmax=objC.N;
        qDebug()<<Nmax;
        double pmax=(Nmax*pow(10.0,3.0))/(objA.d*(c1/objA.E1+c2/objA.E2));
        double Fmax=pmax*M_PI*objA.d*objA.l*objA.f*pow(10.0,-2.0);
        double Qmax=1.15*Fmax;
        qDebug()<<Fmax<<" "<<Qmax;
        data_pressing objD;
        objD.Fmax1.setNum(Fmax);
        objD.Qmax1.setNum(Qmax);
        emit SendDataModelToForm_2(objD);
}

