// Act 1.3 - Actividad Integral de Conceptos B�sicos y Algoritmos Fundamentales
// Santiago Gutierrez Gonzales A00572499, Cesar Mecinas Estrada A01281202, Fernanda Jazmin Narvaez Andrade A00572827
// 8 Septiembre 2023, 19 Septiembre 2023


// El programa lee y almacena los registros de un archivo de bit�cora en un vector.
// Luego los ordena por fechas utlizando mergesort, guardadandolos en un archivo.
// A continuaci�n, el programa permite al usuario especificar un rango de fechas para buscar registros.
// Estos se almacenan en un archivo txt dentro de una carpeta creada por el mismo codigo.
// El programa permite realizar nuevas b�squedas y guardando los resultados en archivos separados.
// Si el programa se vuelve a utilizar la carpeta borra los archivos.

//Librerias
#include <iostream>
#include <fstream> //Libreria para leer, escribir y modificar archivos
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <windows.h>
#include <cstdlib>
using namespace std;


//Mezcla-complejidad de orden Lineal O(n)
int mezcla(vector<int>& numeros, int ini, int fin) {
    int numComparaciones = 0;
    int centro = (ini + fin) / 2;
    int j = ini;
    int k = centro + 1;
    int tamanio = fin - ini;
    int temp[tamanio + 1];
    int posicion = 0;

    while (j <= centro || k <= fin) {
        if (j <= centro && k <= fin) {
            if (numeros[j] < numeros[k]) {
                numComparaciones++;
                temp[posicion++] = numeros[j++];
            }
            else {
                numComparaciones++;
                temp[posicion++] = numeros[k++];
            }
        }
        else if (j > centro) {
            temp[posicion++] = numeros[k++];
        }
        else {
            temp[posicion++] = numeros[j++];
        }
    }

    for (int a = 0; a < tamanio + 1; a++) {
        numeros[ini + a] = temp[a];
    }

    return numComparaciones;
}

//OrdenaMerge-complejidad de orden Logaritmica y lineal O(n*log(n))
int ordenaMerge(vector<int>& numeros, int ini, int fin) {
    int numComparaciones = 0;
    if (ini < fin) {
        int centro = (ini + fin) / 2;
        numComparaciones += ordenaMerge(numeros, ini, centro);
        numComparaciones += ordenaMerge(numeros, centro + 1, fin);
        numComparaciones += mezcla(numeros, ini, fin);
    }

    return numComparaciones;
}

//busqBinaria-complejidad de orden logaritmica O(log(n))
int busqBinaria(vector<int>& numeros, int n, int& numComp) {
    int tamanio = numeros.size();
    int max = tamanio - 1;
    int min = 0;
    int average;
    while (min <= max) {
        average = (max + min) / 2;
        numComp++;
        if (n == numeros[average] / 1000000 * 1000000) {
            return average;
        }
        if (n > numeros[average]) {
            min = average + 1;
            numComp++;
        }
        else if (n < numeros[average]) {
            max = average - 1;
            numComp++;
        }
    }

    return -1;
}

//BusqSecuencial-complejidad de orden Lineal O(n)
int busqSecuencial(vector<int>& numeros, int n, int ini, int& numComp) {
    int tamanio = numeros.size();
    for (ini; ini < tamanio - 1; ini++) {
        numComp++;
        if (n / 1000000 == numeros[ini] / 1000000) {
            return ini;
        }
    }

    return -1;
}

// Busqueda Binaria y Secuencial que se combina para encontrar el valor de un dia antes con binario y luego de buscar secuencialmente el primer dia del registro O(log(n))+ O(n de dias en un registro)
int busqBinSec(vector<int>& numeros, int numBusc, int& numComp, int dia) {
    int indiceMenor;

    //Hacemos esto para que en caso de que no haya un cierto dia,sobre todo cuando busquemos en dias que no estan en el registro, sigamos buscando empezando el prox. mes
    if (dia >= 31) {
        numBusc = (numBusc / 100000000 * 100000000 + 100000000) + 1000000;
        dia = 1;
    }
    //En este if estamos comprobando si el numero que buscamos es menor al primer numero del vector, lo que signfica que el rango de busqueda comienza en el 0
    if (numBusc < numeros[0] / 1000000 * 1000000) {
        return 0;
    }
    //Para esto caso vemos que el numero que buscamos es mayor que el ultimo num del arreglo por lo que nuestro indice sera el tamanio del arreglo menos 1
    else if (numBusc > numeros[numeros.size() - 1] / 1000000 * 1000000) {
        return numeros.size() - 1;
    }
    int numIniMenor = numBusc - 1000000;
    if (numIniMenor < numeros[0] / 1000000 * 1000000) {
        return busqSecuencial(numeros, numBusc, 0, numComp);
    }
    //En caso de que el dia sea el primero quiere decir que buscaremos a partir del mes anterior
    if (dia == 1) {
        int diaAnteriorABuscar = (numBusc / 100000000 * 100000000 - 100000000) + 28000000;//Configuramos para que la busqueda se haga desde el mes anterior, el dia 28 que esta en todos los meses
        indiceMenor = busqBinaria(numeros, diaAnteriorABuscar, numComp);
        if (indiceMenor != 1) {
            return busqSecuencial(numeros, numBusc, indiceMenor, numComp);
        }
    }
    indiceMenor = busqBinaria(numeros, numIniMenor, numComp);
    if (indiceMenor != -1) {
        return busqSecuencial(numeros, numBusc, indiceMenor, numComp);
    }
    else {
        return busqBinSec(numeros, numBusc + 1000000, numComp, dia++);//En caso de no encontrarlo busca un dia despues
    }
}

//Esta funci�n nos permite generar los indices para el acceso combinando pidiendola en primera instancia. Tiene el parametro de la suma de dias para sumarlos en el indice final
int indiceAcceso(int sumaDias, unordered_map<string, int>meses, vector<int> fechasANumeros) {
    string fecha;
    string momento;
    if (sumaDias == 0) {
        momento = "inicial";
    }
    else if (sumaDias == 1) {
        momento = "final";
    }
    cout << "Ingresa la fecha " << momento << endl;
    getline(cin, fecha);
    int numFecha = 0;
    fecha.erase(remove_if(fecha.begin(), fecha.end(), ::isspace), fecha.end());
    numFecha += meses[fecha.substr(0, 3)] * 100000000;
    int dia = 0;
    if (fecha.size() == 4) {
        dia = (int(fecha[3] - '0') + sumaDias);
        numFecha += (int(fecha[3] - '0') + sumaDias) * 1000000;
    }
    else {
        dia = (int(fecha[3] - '0')) * 10 + (int(fecha[4] - '0') + sumaDias);
        numFecha += (int(fecha[3] - '0')) * 1000000 * 10;
        numFecha += (int(fecha[4] - '0') + sumaDias) * 1000000;
    }
    int numComp = 0;
    numComp = 0;
    return busqBinSec(fechasANumeros, numFecha, numComp, dia);
}

// MAIN
int main()
{
    //Vector para almacenar los renglnes en orden
    vector<string> renglonesOrdenados;
    //Antes de ordenar
    vector<string> renglones;
    //Las fechas como un solo numero
    vector<int> fechasANumeros;


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

    //La tabla que nos sirve para traducir las fechas como un numero a su mensaje ya ordenados
    unordered_map<int, string>fechaMensajes;

    ifstream bitacora; //Tipo de dato Input file stream
    bitacora.open("bitacora.txt");
    if (bitacora.is_open()) { //Siempre se verifica que el archivo este abierto
        string renglon = "";
        string palabra = "";
        int j = 0;
        int i = 0;
        int fechaNum = 0;
        int numIteracion = 0;
        while (bitacora.good()) {
            bitacora >> palabra; //Saca string por string del documento
            if (meses[palabra] < 1) { //en caso de que la palabra no sea un mes hacemos lo siguiente
                if (i == 1) {
                    fechaNum += stoi(palabra) * 1000000; //En la segunda iteracion que encontramos la palabra que representa el dia
                }
                renglon.append(palabra);
                renglon.append(" ");
                if (i == 2) { //En la iteracion donde se encuentra la hora con min y seg usamos substr para obtener el numero
                    fechaNum += int(palabra[0] - '0') * 10000 * 10; //Decenas de la hora
                    fechaNum += int(palabra[1] - '0') * 10000; //Uds de la hora
                    fechaNum += int(palabra[3] - '0') * 100 * 10; //Decenas de los min
                    fechaNum += int(palabra[4] - '0') * 100; //Uds de los min
                    fechaNum += int(palabra[6] - '0') * 10;
                    fechaNum += int(palabra[7] - '0');
                }
            }
            else { //Cuando la palabra si es un mes mandamos el renglon al vector de renglones y comenzamos uno nuevo
                if (numIteracion != 0) {
                    renglones.push_back(renglon);
                    fechaMensajes[fechaNum] = renglon;
                    fechasANumeros.push_back(fechaNum);
                }
                renglon = "";
                renglon.append(palabra);
                renglon.append(" ");
                fechaNum = 0;
                i = 0; //Reinicializamos para saber en la parte del renglon que vamos
                fechaNum += meses[palabra] * 100000000; //Sumanos al numero con el mes primero que nada
                j++;
            }
            i++;
            numIteracion += 1;

        }
    }
    ordenaMerge(fechasANumeros, 0, fechasANumeros.size() - 1);

    //La carpeta se crea
    std::string nombreCarpeta = "salidas";
    std::string comandoPersonalizado = "mkdir " + nombreCarpeta;
    int resultadoPersonalizado = system(comandoPersonalizado.c_str());
    if (resultadoPersonalizado == 0 || resultadoPersonalizado == 256) {
        std::cout << "La carpeta \"" << nombreCarpeta << "\" ha sido creada exitosamente." << std::endl;
    }
    else {
        std::cout << "La carpeta \"" << nombreCarpeta << "\" ya existe." << std::endl;
    }

    //Borrar los archivos de la carpeta
    const char* carp = "Salidas";
    string comando = "del /Q " + string(carp) + "\\*";
    int resultado = system(comando.c_str());

    //Abre La carpeta y almacena lista ordenada
    ofstream Bitacora_Ordenada("Salidas/bitacoraOrdenada1.3-eq8.txt");
    for (int a = 0; a < fechasANumeros.size(); a++) {
        renglonesOrdenados.push_back(fechaMensajes[fechasANumeros[a]]);
        Bitacora_Ordenada << (fechaMensajes[fechasANumeros[a]]) << endl;
    }
    Bitacora_Ordenada.close();

    //BUSQUEDA
    string nombre, x, y, nom_archiv, respuesta;
    x = "salida";
    y = "-eq8.txt";
    int contador = 0;
    nombre = "archivo";
    string contadorAString;

    int indice = indiceAcceso(0, meses, fechasANumeros); //En caso buscar el indice inicial ponemos 0 como parametro para que busque el dia exacto
    int indiceFinal = indiceAcceso(1, meses, fechasANumeros); //Aqui ponemos 1 para poder mostrar todo lo que pase en el ultimo dia hasta justo uno antes del dia siguiente
    contador++;
    contadorAString = to_string(contador);
    nombre.append(contadorAString);
    nom_archiv = x + contadorAString + y;

    ofstream pov("Salidas/" + nom_archiv);
    for (indice; indice < indiceFinal; indice++) {
        pov << renglonesOrdenados[indice] << endl;
    }
    pov.close();

    cout << "Deseas realizar otra busqueda? (S/N)" << endl;
    getline(cin, respuesta);

    if (respuesta == "S") {
        while (true) {
            indice = indiceAcceso(0, meses, fechasANumeros); //En caso buscar el indice inicial ponemos 0 como parametro para que busque el dia exacto
            indiceFinal = indiceAcceso(1, meses, fechasANumeros); //Aqui ponemos 1 para poder mostrar todo lo que pase en el ultimo dia hasta justo uno antes del dia siguiente
            contador++;
            contadorAString = to_string(contador);
            nombre.append(contadorAString);
            nom_archiv = x + contadorAString + y; //El numero del archivo se modifica

            // Se abre la carpeta y el archivo se crea y almacena
            ofstream fov("Salidas/" + nom_archiv);
            for (indice; indice < indiceFinal; indice++) {
                fov << renglonesOrdenados[indice] << endl;
            }
            fov.close();

            respuesta = x;
            cout << "Deseas realizar otra busqueda? (S/N)" << endl;
            getline(cin, respuesta);

            if (respuesta == "N") { false; return 0; }
        }
    }
    return 0;
}

