#include "MyBST.h"
#include <iostream>

using namespace std;

int main()
{
/*
    MyBST arbolBin;
    arbolBin.preorder();
    arbolBin.inorder();
    arbolBin.postorder();
    arbolBin.insert(45);
    arbolBin.insert(15);
    arbolBin.insert(79);
    arbolBin.insert(90);
    arbolBin.insert(10);
    arbolBin.insert(55);
    arbolBin.insert(12);
    arbolBin.insert(20);
    arbolBin.insert(50);

    cout<<"FIN DEL PREORDEN"<< endl;

    cout<<"Fin del inorden"<< endl;
    arbolBin.visit(1);
    arbolBin.visit(2);
    arbolBin.visit(3);
    arbolBin.visit(4);

    cout << "Hello world!" << endl;
    arbolBin.ancestors(45);
    cout<<"Nivel "<<arbolBin.whatLevelAmI(45)<<endl;
    cout<<"Nivel "<<arbolBin.whatLevelAmI(50)<<endl;
    cout<<"Nivel "<<arbolBin.whatLevelAmI(51)<<endl;
    cout<<"Altura del arbol "<<arbolBin.height()<<endl;
    cout<<arbolBin.insert(27);
    cout<<arbolBin.insert(48);
    cout<<"Altura del arbol "<<arbolBin.height()<<endl;
*/
    MyBST arbolBin2;
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
    arbolBin2.insert(3600);
    arbolBin2.insert(3700);
    arbolBin2.insert(3700);
    /*


    */

    arbolBin2.preorder();
    arbolBin2.inorder();
    arbolBin2.postorder();
    arbolBin2.level();


    arbolBin2.ancestors(70);
    arbolBin2.ancestors(3700);
    cout<<"posicion del nodo 3700: "<<arbolBin2.whatLevelAmI(3700)<<endl;
    cout<<"Altura del arbol 2: "<<arbolBin2.height()<<endl;
    /*
    */
    cout<<"HOLAA"<<endl;
    cout<<"Altura del arbol 2: "<<arbolBin2.height()<<endl;
    cout<<"Altura del arbol 2: "<<arbolBin2.height()<<endl;
    cout<<"Altura del arbol 2: "<<arbolBin2.height()<<endl;
    return 0;
}
