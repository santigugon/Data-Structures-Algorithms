#include "Bitacora.h"
#include <unordered_map>

using namespace std;


Bitacora::Bitacora(ifstream archivo){

      //El mapa para representar los meses con su numero
    unordered_map<string, int>meses;
    meses["Jan"] = 1;
    meses["Feb"] = 2;
    meses["Mar"] = 3;
    meses["Abr"] = 4;
    meses["May"] = 5;
    meses["Jun"] = 6;
    meses["Jul"] = 7;
    meses["Aug"] = 8;
    meses["Sep"] = 9;
    meses["Oct"] = 10;
    meses["Nov"] = 11;
    meses["Dec"] = 12;

    this->nodosIpOrdenada; //Creamos la lista ligada vacia

    archivo.open("bitacora.txt");

    if (archivo.is_open()) { //Siempre se verifica que el archivo este abierto
        string renglon = "";
        string palabra = "";
        int j = 0;
        int i = 0;
        string ip;
        while (archivo.good()) {
            archivo >> palabra; //Saca string por string del documento
            if (meses[palabra] < 1) { //en caso de que la palabra no sea un mes hacemos lo siguiente

                renglon.append(palabra);
                renglon.append(" ");
                if (i == 3) { //En la iteracion donde se encuentra la hora con min y seg usamos substr para obtener el numero
                   ip=palabra;
                }
            }
            else { //Cuando la palabra si es un mes mandamos el renglon al vector de renglones y comenzamos uno nuevo
                if (i != 0 && renglon !="") {
                    //renglones.push_back(renglon);
                    NodoRegistro nuevoNodo(renglon,ip);
                    if( this->nodosIpOrdenada.isEmpty()){
                        this->nodosIpOrdenada.insertFirst(nuevoNodo);
                    }else{
                        MyNodoLL* actual=this->nodosIpOrdenada.head;
                        MyNodoLL* prev;
                        for(int i=0;i<this->nodosIpOrdenada.length();i++){
                            if(i==this->nodosIpOrdenada.length()-1){
                                nodosIpOrdenada.insertLast(nuevoNodo);
                            }
                            else if(actual->data.getJerarquia1()<nuevoNodo.getJerarquia1()){
                                actual=actual->next;
                                prev=actual;
                            }else if(actual->data.getJerarquia1()==nuevoNodo.getJerarquia1()){
                                if(actual->data.getJerarquia2()<nuevoNodo.getJerarquia2()){
                                    actual=actual->next;
                                    prev=actual;
                                }
                                else if(actual->data.getJerarquia2()==nuevoNodo.getJerarquia2()){
                                    if(actual->data.getJerarquia3()<nuevoNodo.getJerarquia3()){
                                        actual=actual->next;
                                        prev=actual;
                                    }
                                    else if(actual->data.getJerarquia3()==nuevoNodo.getJerarquia3()){

                                        if(actual->data.getJerarquia4()<nuevoNodo.getJerarquia4()){
                                            actual=actual->next;
                                            prev=actual;
                                        }
                                        else if(actual->data.getJerarquia4()==nuevoNodo.getJerarquia4()){
                                            if(actual->data.getPuerto()<nuevoNodo.getPuerto()){
                                                actual=actual->next;
                                                prev=actual;
                                            }
                                            else if(actual->data.getPuerto()==nuevoNodo.getPuerto()){
                                                nuevoNodo->next=prev->next;
                                                prev->next=nuevoNodo;
                                                nodosIpOrdenada.size++;

                                            }
                                            else if(actual->data.getPuerto)>nuevoNodo.getPuerto()){
                                                if(i==0){
                                                    nodosIpOrdenada.insertFirst(nuevoNodo);
                                                }
                                                else{
                                                    nodoNuevo->next=prev->next;
                                                    prev->next=nodoNuevo;
                                                    nodosIpOrdenada.size++;
                                                }
                                            }
                                        //*
                                        }
                                        else if(actual->data.getJerarquia4()>nuevoNodo.getJerarquia4()){
                                            if(i==0){
                                            nodosIpOrdenada.insertFirst(nuevoNodo);
                                        }   else{
                                                nodoNuevo->next=prev->next;
                                                prev->next=nodoNuevo;
                                                nodosIpOrdenada.size++;
                                            }
                                        }
                        //***
                                    }
                                    else if(actual->data.getJerarquia3()>nuevoNodo.getJerarquia3()){
                                        if(i==0){
                                            nodosIpOrdenada.insertFirst(nuevoNodo);
                                        }else{
                                            nodoNuevo->next=prev->next;
                                            prev->next=nodoNuevo;
                                            nodosIpOrdenada.size++;
                                        }
                                    }
                                }
                                //*
                                else if(actual->data.getJerarquia2()>nuevoNodo.getJerarquia2()){
                                    if(i==0){
                                        nodosIpOrdenada.insertFirst(nuevoNodo);
                                    }else{
                                        nodoNuevo->next=prev->next;
                                        prev->next=nodoNuevo;
                                        nodosIpOrdenada.size++;
                                    }
                                }

                            }else if(actual->data.getJerarquia1()>nuevoNodo.getJerarquia1()){
                                if(i==0){
                                    nodosIpOrdenada.insertFirst(nuevoNodo);
                                }else{
                                    nodoNuevo->next=prev->next;
                                    prev->next=nodoNuevo;
                                    nodosIpOrdenada.size++;
                                }

                            }
                        }

                    }

                }
                renglon = "";
                renglon.append(palabra);
                renglon.append(" ");
                i = 0; //Reinicializamos para saber en la parte del renglon que vamos
                j++;
            }
            i++;

        }
    }

}

