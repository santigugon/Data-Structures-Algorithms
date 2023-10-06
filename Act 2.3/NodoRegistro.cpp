#include "NodoRegistro.h"
using namespace std;


NodoRegistro::NodoRegistro(string mensaje, string ip){
   this->mensaje=mensaje;
   this->ip=ip;
   this->createJerarquias();
}

NodoRegistro::NodoRegistro(){
    this->mensaje="";
}


void NodoRegistro::createJerarquias(){
    std::vector<int> jerarquias;
    std::string jerarquiaPalabra;
    std::string ip = this->ip;
    int jerarquiaNum;
    for (int i = 0; i < ip.size(); i++) {

        if ((ip[i] == '.') || (ip[i] == ':')||i==ip.size()-1) {

            jerarquiaNum = 0;
            if(i==ip.size()-1) jerarquiaPalabra.push_back(ip[i]);
            if (jerarquiaPalabra.size() == 3) {
                jerarquiaNum += (jerarquiaPalabra[0] - '0') * 100;
                jerarquiaNum += (jerarquiaPalabra[1] - '0') * 10;
                jerarquiaNum += (jerarquiaPalabra[2] - '0');
            }
            else if (jerarquiaPalabra.size() == 2) {
                jerarquiaNum += (jerarquiaPalabra[0] - '0') * 10;
                jerarquiaNum += (jerarquiaPalabra[1] - '0');
            }
            else if (jerarquiaPalabra.size() == 1) {
                jerarquiaNum += (jerarquiaPalabra[0] - '0');
            }
            else if (jerarquiaPalabra.size() == 4) {
                jerarquiaNum += (jerarquiaPalabra[0] - '0') * 1000;
                jerarquiaNum += (jerarquiaPalabra[1] - '0') * 100;
                jerarquiaNum += (jerarquiaPalabra[2] - '0') * 10;
                jerarquiaNum += (jerarquiaPalabra[3] - '0');
            }
            jerarquias.push_back(jerarquiaNum);
            jerarquiaPalabra = "";

        }else{
        jerarquiaPalabra.push_back(ip[i]);
        }
    }
    if(jerarquias.size()==5){

        this->jerarquia1=jerarquias[0];
        this->jerarquia2=jerarquias[1];
        this->jerarquia3=jerarquias[2];
        this->jerarquia4=jerarquias[3];
        this->puerto=jerarquias[4];
    }else{
        throw std::invalid_argument("No hay 5 jerarquias");
    }

}

     // Getters
    string NodoRegistro::getIp()const{
        return this->ip;
    }
    string NodoRegistro::getMensaje()const{
          return this->mensaje;
    }
    int NodoRegistro::getJerarquia1()const{
        return this->jerarquia1;
    }
    int NodoRegistro::getJerarquia2()const{
        return this->jerarquia2;
    }
    int NodoRegistro::getJerarquia3()const{
        return this->jerarquia3;
    }

    int NodoRegistro::getJerarquia4()const{
        return this->jerarquia4;
    }
    int NodoRegistro::getPuerto()const{
        return this->puerto;
    }

    // Setter
    void NodoRegistro::setIp(const string& newIp){
        this->ip=newIp;
    }
    void NodoRegistro::setMensaje(const string& newMensaje){
        this->mensaje=newMensaje;
    }
    void NodoRegistro::setJerarquia1(int newJerarquia1){
        this->jerarquia1=newJerarquia1;
    }
    void NodoRegistro::setJerarquia2(int newJerarquia2){
        this->jerarquia2=newJerarquia2;
    }
    void NodoRegistro::setJerarquia3(int newJerarquia3){
    {
        this->jerarquia3=newJerarquia3;
    }
    }
    void NodoRegistro::setJerarquia4(int newJerarquia4){
        this->jerarquia4=newJerarquia4;
    }
    void NodoRegistro::setPuerto(int newPuerto){
        this->puerto= newPuerto;
    }

    bool NodoRegistro::compareTwoNodos(NodoRegistro &nodo2){

            if(this->getJerarquia1()>nodo2.getJerarquia1()){
                return true;
            }else if(this->getJerarquia1()<nodo2.getJerarquia1()){
                return false;
            }else if(this->getJerarquia2()>nodo2.getJerarquia2()){
                return true;
            }else if(this->getJerarquia2()<nodo2.getJerarquia2()){
                return false;
            }else if(this->getJerarquia3()>nodo2.getJerarquia3()){
                return true;
            }else if(this->getJerarquia3()<nodo2.getJerarquia3()){
                return false;
            }else if(this->getJerarquia4()>nodo2.getJerarquia4()){
                return true;
            }else if(this->getJerarquia4()<nodo2.getJerarquia4()){
                return false;
            }
            else if(this->getPuerto()>nodo2.getPuerto()){
                return true;
            }else if(this->getPuerto()<nodo2.getPuerto()){
                return false;
            }else if(this->getPuerto()==nodo2.getPuerto()){
                return true;
            }


    }
