//A00572499 Santiago Gutierrez Gonzalez y A01281202 Cesar Mecinas Estrada
//Act 5.2 - Actividad Integral de BST
//7/11/2023

//Descripcion- Este programa realiza el ordenamiento de un registro de IPs con su respectivo mensaje, este ordenamiento lo realiza en base a las jerarquias de las IPs y despues nos permite observar cuales son aquellas con mas frecuencias gracias a un inorder al reves


#include "Bitacora.h"
#include <unordered_map>


using namespace std;

//Complejidad O(m) m=numero de palabras
Bitacora::Bitacora(){

    ifstream archivo;
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

    archivo.open("bitacora3-1.txt");

    if (archivo.is_open()) { //Siempre se verifica que el archivo este abierto
        this->tablaRegistros= new MyHashTable;
        string renglon;
        string palabra;
        int j = 0;
        int i = 0;
        string ip;
        int fechaNum = 0;
        string ipSinPuerto="";
        int numLineas=0;
        string fechaTexto;
        while (archivo.good()) {
            archivo >> palabra; //Saca string por string del documento
            if (meses[palabra] > 1) {
                i=0;
                fechaNum=0;
                renglon="";

            } //en caso de que la palabra no sea un mes hacemos lo siguiente
            if(i==0){
                renglon.append(palabra);
                renglon.append(" ");
                fechaNum += meses[palabra] * 100000000; //Sumanos al numero con el mes primero que nada
            }
            if (i == 1) {
                renglon.append(palabra);
                renglon.append(" ");
                fechaNum += stoi(palabra) * 1000000; //En la segunda iteracion que encontramos la palabra que representa el dia
            }
            if (i == 2) { //En la iteracion donde se encuentra la hora con min y seg usamos substr para obtener el numero
                    renglon.append(palabra);
                    fechaTexto=renglon;
                    int decenas;
                    palabra.size()==7?decenas=1:decenas=0;
                    if(decenas==0)fechaNum += int(palabra[0] - '0') * 10000 * 10; //Decenas de la hora
                    fechaNum += int(palabra[1-decenas] - '0') * 10000; //Uds de la hora
                    fechaNum += int(palabra[3-decenas] - '0') * 100 * 10; //Decenas de los min
                    fechaNum += int(palabra[4-decenas] - '0') * 100; //Uds de los min
                    fechaNum += int(palabra[6-decenas] - '0') * 10;
                    fechaNum += int(palabra[7-decenas] - '0');
            }
            if (i == 3) { //En la iteracion donde se encuentra la hora con min y seg usamos substr para obtener el numero
                    ip=palabra;

                    ipSinPuerto="";

                    for(int i=0;i<ip.size();i++){
                        if(ip[i]==':')break;
                        ipSinPuerto.push_back(ip[i]);
                    }
                   // cout<<"IP: "<<ipSinPuerto<<" Fecha: "<<fechaNum<<endl;
                    numLineas++;
                    if(this->tablaRegistros->get(ipSinPuerto)->isEmpty()){
                        MyBST* nuevoDato=new MyBST(ipSinPuerto);
                        nuevoDato->insert(fechaNum,fechaTexto);
                        this->tablaRegistros->put(ipSinPuerto,nuevoDato);
                    }
                    else{
                        this->tablaRegistros->get(ipSinPuerto)->insert(fechaNum,fechaTexto);
                    }

                }
            i++;
            }
        cout<<"NumLineas"<<numLineas<<endl;
        }
        this->tablaRegistros->get("10.15.182.253")->inorder();
        //FACTOR DE BALANCEO
        cout<<float(this->tablaRegistros->size)/float(this->tablaRegistros->sizeA)<<endl;

    }


void Bitacora::busquedaBitacora(){
    string ipInicial;
    int respuesta=1;
    while(respuesta==1){
        cout<<endl;
        cout<<"Ingresa tu ip a buscar"<<endl;
        cin>>ipInicial;
        this->tablaRegistros->get(ipInicial)->inorder();
        cout<<endl;
        cout<<"Deseas realizar otra busqueda?"<<endl;
        cout<<"1 para si/ 0 para no"<<endl;
        cin>>respuesta;
        cout<<endl;
        cout<<"TAMANIO"<<this->tablaRegistros->size<<endl;

    }
    cout<<endl;
    cout<<"La busqueda ha finalizado"<<endl;
}
/*
string Bitacora::numAFecha(int fecha){


}
*/
//Complejidad de orden lineal O(n)


