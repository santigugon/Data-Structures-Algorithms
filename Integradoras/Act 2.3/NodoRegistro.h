//A00572499 Santiago Gutierrez Gonzalez y A01281202 Cesar Mecinas Estrada
//Act 2.3 - Algoritmos de Busqueda y Ordenamiento
//10/10/2023

//Descripcion- Este programa realiza el ordenamiento de un registro de IPs con su respectivo mensaje, este ordenamiento lo realiza en base a las jerarquias de las IPs y posteriormente permite la busqueda en un rango de Ips dando la ip inicial y final


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
    void setPuerto(int newPuerto);


    void createJerarquias();
    bool compareTwoNodos(NodoRegistro &nodo2);
    bool isNodoEqual(NodoRegistro &nodo2);
};




#endif // NODOREGISTRO_H_INCLUDED
