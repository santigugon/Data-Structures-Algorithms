#include "MyBST.h"
#include <iostream>

using namespace std;

int main()
{

    MyBST arbolBin;
    arbolBin.remove(25);
    arbolBin.visit(4);
    arbolBin.insert(21);
    arbolBin.visit(4);
     arbolBin.remove(21);
    arbolBin.visit(4);

    arbolBin.insert(13);
    arbolBin.insert(33);
    arbolBin.insert(10);
    arbolBin.insert(18);
    arbolBin.insert(25);
    arbolBin.insert(40);
    //arbolBin.insert(29);
    //arbolBin.insert(27);
    //arbolBin.insert(30);
    //arbolBin.ancestors(29);
    cout<<endl;
    arbolBin.remove(21);
    arbolBin.visit(4);
    arbolBin.ancestors(29);
    /*
    //ARBOL VACIO
    cout<<endl<<"ARBOL VACIO"<<endl;
    cout<<"Visita arbol vacio"<<endl;
    /*
    arbolBin.visit(1);
    arbolBin.visit(2);
    arbolBin.visit(3);
    arbolBin.visit(4);

    cout<<"Fin visita arbol vacio"<<endl;
    cout<<"Altura arbol vacio "<<arbolBin.height()<<endl;
    cout<<"Posicion arbol vacio "<<arbolBin.whatLevelAmI(45)<<endl;
    cout<<"Ancestros del numero "<<45<<endl;
    arbolBin.ancestors(45);
    cout<<endl;

    if(arbolBin.remove(15)){
        cout<<"elemento removido"<<endl;
    }else{
        cout<<"No se encontro el elemento"<<endl;
    }


    cout<<endl<<"ARBOL UN ELEMENTO"<<endl;
    arbolBin.insert(45);
    cout<<"Visita arbol un elemento"<<endl;
    cout<<"Posicion arbol un elemento "<<arbolBin.whatLevelAmI(45)<<endl;
    arbolBin.visit(1);
    arbolBin.visit(2);
    arbolBin.visit(3);
    arbolBin.visit(4);
    cout<<"Fin visita arbol un elemento"<<endl;
    cout<<"Altura arbol un elemento "<<arbolBin.height()<<endl;
     cout<<"Ancestros del numero "<<45<<endl;
    arbolBin.ancestors(45);
     cout<<"Ancestros del numero "<<50<<endl;
    arbolBin.ancestors(50);

    if(arbolBin.remove(45)){
        cout<<"elemento removido"<<endl;
    }else{
        cout<<"No se encontro el elemento"<<endl;
    }
    cout<<"Altura arbol un elemento removido "<<arbolBin.height()<<endl;

    cout<<endl;

    cout<<endl<<"ARBOL COMPLETO"<<endl;
    arbolBin.insert(15);
    arbolBin.insert(79);
    arbolBin.insert(90);
    arbolBin.insert(10);
    arbolBin.insert(55);
    arbolBin.insert(12);
    arbolBin.insert(20);
    arbolBin.insert(50);

    arbolBin.visit(4);
    cout<<"RAIZ "<<arbolBin.root->data<<endl;
    cout<<"Tamaño "<<arbolBin.size<<endl;
       if(arbolBin.remove(15)){
        cout<<"elemento removido"<<endl;
    }else{
        cout<<"No se encontro el elemento"<<endl;
    }
    cout<<"RAIZ "<<arbolBin.root->data<<endl;
    cout<<"Tamaño "<<arbolBin.size<<endl;
   if(arbolBin.remove(15)){
        cout<<"elemento removido"<<endl;
    }else{
        cout<<"No se encontro el elemento"<<endl;
    }
    cout<<"Tamaño "<<arbolBin.size<<endl;

    /*
    arbolBin.visit(1);
    arbolBin.visit(2);
    arbolBin.visit(3);
    cout<<"Fin visita arbol completo"<<endl;
    cout<<"Altura arbol completo "<<arbolBin.height()<<endl;
    cout<<"Posicion arbol completo raiz "<<arbolBin.whatLevelAmI(45)<<endl;
    cout<<"Posicion arbol completo intermedio "<<arbolBin.whatLevelAmI(15)<<endl;
    cout<<"Posicion arbol completo hoja final "<<arbolBin.whatLevelAmI(50)<<endl;
    cout<<"Posicion arbol completo hoja inexistente "<<arbolBin.whatLevelAmI(51)<<endl;

    cout<<"Visita arbol completo"<<endl;
    cout<<"Ancestros del numero "<<45<<endl;
    arbolBin.ancestors(45);
     cout<<"Ancestros del numero "<<50<<endl;
    arbolBin.ancestors(50);
    cout<<endl;
    /*
    cout<<"FIN DEL PREORDEN"<< endl;

    cout<<"Fin del inorden"<< endl;
    arbolBin.visit(1);
    arbolBin.visit(2);
    arbolBin.visit(3);
    arbolBin.visit(4);

    cout << "Hello world!" << endl;
    arbolBin.whatLevelAmI(45);
    arbolBin.whatLevelAmI(51);
    arbolBin.whatLevelAmI(50);
    arbolBin.whatLevelAmI(45);
    arbolBin.whatLevelAmI(45);
    arbolBin.ancestors(45);
    cout<<"Nivel "<<arbolBin.whatLevelAmI(45)<<endl;
    cout<<"Nivel "<<arbolBin.whatLevelAmI(50)<<endl;
    cout<<"Nivel "<<arbolBin.whatLevelAmI(51)<<endl;
    cout<<"Altura del arbol "<<arbolBin.height()<<endl;
    arbolBin.insert(27);
    arbolBin.insert(48);
    cout<<"Altura del arbol "<<arbolBin.height()<<endl;
    arbolBin.height();

    MyBST arbolBin2;
    arbolBin2.remove(710);
    cout<<"Altura del arbol 2: "<<arbolBin2.height()<<endl;
    arbolBin2.visit(1);
    arbolBin2.visit(2);
    arbolBin2.visit(3);
    arbolBin2.visit(4);

    arbolBin2.insert(710);
    arbolBin2.insert(2000);
    arbolBin2.insert(689);
    arbolBin2.insert(1040);
    arbolBin2.insert(702);
    arbolBin2.insert(143);
    arbolBin2.insert(2099);
    arbolBin2.insert(3300);
    arbolBin2.insert(70);
    arbolBin2.insert(1500);
    arbolBin2.insert(178);
    arbolBin2.insert(3600);
    arbolBin2.preorder();
    cout<<endl<<"remove"<<endl;
    if(arbolBin2.remove(710)){
        cout<<"El elemento se elimino correctamente"<<endl;
    }
    if(arbolBin2.remove(710)){
        cout<<"El elemento se elimino correctamente"<<endl;
    }else{
              cout<<"El elemento NO se elimino correctamente"<<endl;
    }
    arbolBin2.preorder();
    arbolBin2.insert(3700);
    arbolBin2.insert(3700);


    arbolBin2.preorder();
    arbolBin2.inorder();
    arbolBin2.postorder();


    arbolBin2.ancestors(70);
    arbolBin2.ancestors(3700);
    cout<<"posicion del nodo 3700: "<<arbolBin2.whatLevelAmI(3700)<<endl;
    cout<<"Altura del arbol 2: "<<arbolBin2.height()<<endl;

    cout<<"HOLAA"<<endl;
    cout<<"Altura del arbol 2: "<<arbolBin2.height()<<endl;
    cout<<"Altura del arbol 2: "<<arbolBin2.height()<<endl;
    cout<<"Altura del arbol 2: "<<arbolBin2.height()<<endl;
    */
    return 0;
}
