#include "MyBST.h"
#include <iostream>

using namespace std;

int main()
{
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
    //arbolBin.inorder();
    cout<<"Fin del inorden"<< endl;
    //arbolBin.postorder();
    arbolBin.visit(1);
    arbolBin.level();
    cout << "Hello world!" << endl;
    arbolBin.ancestors(45);
    cout<<"Nivel "<<arbolBin.whatLevelAmI(45)<<endl;
    cout<<"Nivel "<<arbolBin.whatLevelAmI(50)<<endl;
    cout<<"Nivel "<<arbolBin.whatLevelAmI(51)<<endl;
    cout<<"Altura del arbol"<<arbolBin.height();
    return 0;
}
