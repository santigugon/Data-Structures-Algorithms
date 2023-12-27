#include "NodoIP.h"

NodoIP::NodoIP(std::string ip){
    this->ip=ip;
}

void NodoIP::aumentarRec(){
    this->recurrencia++;
}
