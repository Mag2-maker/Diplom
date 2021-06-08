#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H
#include "QString"


struct data_main
{
    double d,d1,d2,l,M,A,f,k,R1,R2,E1,E2,qt1,qt2,n1,n2;
    bool radio_button;
    QString EI,ei;
};
struct data_controller
{
    double TN=0;
};

struct data_pressing
{
    QString Fmax1,Qmax1;
};

#endif // DATA_STRUCT_H
