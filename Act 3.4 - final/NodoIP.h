#include <iostream>

using namespace std;

#ifndef NODOIP_H_INCLUDED
#define NODOIP_H_INCLUDED

class NodoIP{
private:
    string ip;
    int recurrencia;
public:
    NodoIP(string ip);

    string getIp();
    int getRecurrencia();

    void aumentarRec();
    void setIp(string ip);
    void setRecurrencia(int recurrencia);
};

#endif // NODOIP_H_INCLUDED
