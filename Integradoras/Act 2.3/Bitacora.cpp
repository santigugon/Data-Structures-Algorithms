//A00572499 Santiago Gutierrez Gonzalez y A01281202 Cesar Mecinas Estrada
//Act 2.3 - Algoritmos de Busqueda y Ordenamiento
//10/10/2023

//Descripcion- Este programa realiza el ordenamiento de un registro de IPs con su respectivo mensaje, este ordenamiento lo realiza en base a las jerarquias de las IPs y posteriormente permite la busqueda en un rango de Ips dando la ip inicial y final


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

    this->nodosIpOrdenada; //Creamos la lista ligada vacia

    archivo.open("bitacora2.txt");

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

                    size_t lastNonSpace = renglon.find_last_not_of(" \t");

                    if (lastNonSpace != std::string::npos) {
                            // Borramos los espacios del final
                            renglon.erase(lastNonSpace + 1);
                    }

                    NodoRegistro nuevoNodoRegistro(renglon,ip);
                    MyNodoLL* nuevoNodo = new MyNodoLL(nuevoNodoRegistro);

                    nodosIpOrdenada.insertFirst(nuevoNodoRegistro);
                    }


                renglon = "";
                renglon.append(palabra);
                renglon.append(" ");
                i = 0; //Reinicializamos para saber en la parte del renglon que vamos
                j++;
            }
            i++;

        }
        NodoRegistro nuevoNodoRegistro(renglon,ip);
        MyNodoLL* nuevoNodo = new MyNodoLL(nuevoNodoRegistro);
        nodosIpOrdenada.insertLast(nuevoNodoRegistro);

    }


   //this->nodosIpOrdenada.print();
}

//mergeSort-complejidad de orden Lineal O(n)
MyNodoLL* Bitacora::mergeSort(MyNodoLL* lista1, MyNodoLL* lista2){
    MyNodoLL* nodoFinal = nullptr;

    if(lista1==nullptr)
        return lista2;
    else if(lista2==nullptr)
        return lista1;

    if(!lista1->data.compareTwoNodos(lista2->data)){
        nodoFinal=lista1;
        nodoFinal->next= mergeSort(lista1->next,lista2);
    }
    else{
        nodoFinal=lista2;
        nodoFinal->next= mergeSort(lista1,lista2->next);
    }
    return nodoFinal;



}
//mezcla-complejidad de orden Lineal O(n)
void Mezcla(MyNodoLL* cabeza, MyNodoLL** ini, MyNodoLL** fin){

    MyNodoLL* ptr=cabeza->next;
    MyNodoLL* medio=cabeza;
    int i=0;
    while(ptr!=nullptr){ //Moviendo el ptr para llegar hasta el final
        ptr=ptr->next;
        i++;
        if(ptr!=nullptr){
            medio=medio->next; //Recorremos el de en medio
            ptr=ptr->next;
        }
    }

    //Ya que sabemos que hemos llegado en medio vamos a proceder a redefinir el inicio y el fin
    *ini= cabeza;
    *fin= medio->next;
    medio->next=nullptr;
    //cout<<medio->data.getMensaje(); //"Rompemos por asi decir la lista o el vinculo de los medio"



}

//mergeSort-complejidad de orden Lineal O(n log(n))
void Bitacora::mergeSort(MyNodoLL** primero){

    MyNodoLL* cabeza = *primero;
    MyNodoLL* ini;
    MyNodoLL* fin;
    //Nuestro caso base cuando solo hay un elemento ya que hacemos llamadas recursivas
        if((*primero==nullptr) || ((*primero)->next == nullptr)){
            return;
        }

    //Aqui dividimos en dos la lista
    Mezcla(cabeza,&ini,&fin);
    mergeSort(&ini); //Hacemos nuestras llamadas recursivas
    mergeSort(&fin);

    (*primero)=mergeSort(ini,fin);

    //this->nodosIpOrdenada.print();

}

//Complejidad de orden constante O(1)
MyNodoLL** Bitacora::getNodosIpOrdenada(){
    return &nodosIpOrdenada.head;

}
//Complejidad de orden lineal O(n)
void Bitacora::imprimirLista(){
    this->nodosIpOrdenada.print();
}

//Complejidad de orden lineal O(n)
void Bitacora::crearBitacoraOrdenada(){
    ofstream Bitacora_Ordenada("bitacoraOrdenada2IP-Eq8.txt");
    MyNodoLL* actual=this->nodosIpOrdenada.head;
    for (int a = 0; a < this->nodosIpOrdenada.length(); a++) {
        if(a<this->nodosIpOrdenada.length()-1){
            Bitacora_Ordenada << actual->data.getMensaje() << endl;
        }else{
            Bitacora_Ordenada << actual->data.getMensaje();
        }
        actual=actual->next;
    }
    Bitacora_Ordenada.close();
}

//Complejidad de orden lineal O(n)
void Bitacora::busquedaBitacora(){
    string nombre, x, y, nom_archiv, respuesta;
    x = "salida";
    y = "-eq8.txt";
    nombre = "archivo";
    string contadorAString;
    this->contador++;
    contadorAString = to_string(this->contador);
    nombre.append(contadorAString);
    nom_archiv = x + contadorAString + y;

    ofstream pov(nom_archiv);

    string ipInicial;
    string ipFinal;

    cout<<"Ingresa tu ip inicial"<<endl;
    cin>>ipInicial;
    ipInicial.append(":0000");
    cout<<endl;
    cout<<"Ingresa tu ip final"<<endl;
    cin>>ipFinal;
    ipFinal.append(":0000");
    cout<<endl;

    MyNodoLL* actual=this->nodosIpOrdenada.head;

    NodoRegistro nodoInicial("",ipInicial);
    NodoRegistro nodoFinal("",ipFinal);

    //Busqueda secuencial
    for (int i=0; i < this->nodosIpOrdenada.length(); i++) {
        if(actual->data.compareTwoNodos(nodoInicial)){
            while(!actual->data.compareTwoNodos(nodoFinal)){
                string mensaje=actual->data.getMensaje();
                if(actual->next!=nullptr){
                    pov << actual->data.getMensaje();
                    if(!actual->next->data.compareTwoNodos(nodoFinal)){
                        pov<<endl;
                    }
                    actual=actual->next;
                }else{
                    break;
                }
            }
            if(actual->data.isNodoEqual(nodoFinal)){
                if(!nodoInicial.isNodoEqual(nodoFinal)){
                    pov <<endl<< actual->data.getMensaje();
                }else{
                    pov<< actual->data.getMensaje();
                }
            }
            else if(!this->nodosIpOrdenada.tail->data.compareTwoNodos(nodoFinal)&&actual->next==nullptr){
                pov<< actual->data.getMensaje();
            }
            return;
        }
        actual=actual->next;

    }
    pov.close();
    return;
}
