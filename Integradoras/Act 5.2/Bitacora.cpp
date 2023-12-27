//A00572499 Santiago Gutierrez Gonzalez y A01281202 Cesar Mecinas Estrada
//Act 5.2 - Actividad Integral de BST
//26/11/2023

//Descripcion- Este programa almacena las direcciones Ip tomandolas como llaves dentro de un Hash table para posteriormente insertarla en una LL de BSTs donde podremos acceder a las fechas donde hubo un registro de esta Ip en forma creciente


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
        int i = 0;
        string ip;
        int fechaNum = 0;
        string ipSinPuerto="";
        string fechaTexto;
        while (archivo.good()) {
            archivo >> palabra; //Saca string por string del documento
            //Si la palabra actual en un mapa es mayor a uno, quiere decir que estamos en un mes
            if (meses[palabra] > 1) {
                //Reinicimaos todas las variables iniciales que necesita nuestra estructura
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
        }
    }

//Complejidad O(log u) U= numero de registros en cada Ip
void Bitacora::busquedaBitacora(){
    string ipInicial;
    int respuesta=1;
    //Ciclo para la busqueda de mi informacion
    while(respuesta==1){
        cout<<"Ingresa tu ip a buscar"<<endl;
        cin>>ipInicial;
        MyBST* resultado=this->tablaRegistros->get(ipInicial);
        if(resultado->isEmpty()){
            cout<<"Ip no encontrada"<<endl;
            //Se libera mi memoria si la ip no existe con el elemento encontrado
            delete resultado;
        }else{
            resultado->inorder();
        }
        cout<<endl;
        cout<<"Deseas realizar otra busqueda?"<<endl;
        cout<<"1 para si/ 0 para no"<<endl;
        cin>>respuesta;
        cout<<endl;
    }
    cout<<"La busqueda ha finalizado"<<endl;
}



