#include <iostream>
#include <string>
#include <vector>
#ifndef NODOREGISTRO_H_INCLUDED
#define NODOREGISTRO_H_INCLUDED

using namespace std;
class NodoRegistro{
private:
    string ip;
    string mensaje;
    int jerarquia1;
    int jerarquia2;
    int jerarquia3;
    int jerarquia4;
    int puerto;
public:
    NodoRegistro(string mensaje, string ip);
    NodoRegistro();

     // Getters
    string getIp() const;
    string getMensaje() const;
    int getJerarquia1() const;
    int getJerarquia2() const;
    int getJerarquia3() const;
    int getJerarquia4() const;
    int getPuerto() const;

    // Setter
    void setIp(const string& newIp);
    void setMensaje(const string& newMensaje);
    void setJerarquia1(int newJerarquia1);
    void setJerarquia2(int newJerarquia2);
    void setJerarquia3(int newJerarquia3);
    void setJerarquia4(int newJerarquia4);
    void createJerarquias();
    void setPuerto(int newPuerto);
};




#endif // NODOREGISTRO_H_INCLUDED
