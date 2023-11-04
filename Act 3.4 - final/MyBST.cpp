//SANTIAGO GUTIERREZ GONZALEZ
//MATRICULA:A00572499
//ACT 3.1-Operaciones avanzadas en un BST
//Descripcion- Programa que implementa la estructura de datos de una arbol binario de busqueda haciendo uso del struct MyNodeBST e implementando su metodos
//Fecha: 18/10/2023

#include <iostream>
#include "MyBST.h"
#include <queue>
#include <vector>

using namespace std;
//Anotacion Complejidades: h= altura de un arbol, en caso de ser un BST balanceado h suele ser igual a O(log n)
//Entonces cuando hablamos de complejidad O(h) quiere decir que en arboles balanceados  ~= O(log n)
//Peor caso: Cuando el arbol esta completamente desbalanceado

//Complejidad de tipo constante O(1)
MyBST::MyBST(){
    this->root=nullptr;
    this->size=0;
}

//Complejidad de tipo constante O(1)
int MyBST::length(){
    return this->size;
}

//Complejidad de tipo constante O(1)
bool MyBST::isEmpty(){
    return this->size==0;
}

//Peor caso: Complejidad de tipo Lineal O(n)
//Caso medio: Complejidad  O(h)|| h= altura de un arbol
bool MyBST::insert(int data, string ip){
   MyNodeBST* actual= this->root;
   bool insertado=false;
   while(!insertado){
        if(this->size==0){
            actual= new MyNodeBST(data, ip);
            insertado=true;
            this->root=actual;
            this->size++;
            return true;
        }
        else if(actual->data>= data){
            if(actual->left==nullptr){
                actual->left= new MyNodeBST(data,ip);
                this->size++;
                insertado=true;
                return true;
            }
            else{
                actual=actual->left;
            }
        }
        else if( actual->data<data){
            if(actual->right==nullptr){
                actual->right= new MyNodeBST(data, ip), ip;
                insertado=true;
                this->size++;
                return true;
            }else{
                actual=actual->right;
            }
        }else{
            return false;
        }

   }
}

//Peor caso: Complejidad de tipo Lineal O(n)
//Caso medio: Complejidad  O(h)|| h= altura de un arbol
bool MyBST::search(int data){
    MyNodeBST* actual= this->root;
    while(actual!=nullptr){
        if(actual->data==data){
            return true;
        }
        else if(data<actual->data){
            actual=actual->left;
        }
        else{
            actual=actual->right;
        }
    }
    return false;
}

//Peor caso: Complejidad de tipo Lineal O(n)
//Caso medio: Complejidad  O(h)|| h= altura de un arbol
bool MyBST::searchRec(int data, MyNodeBST* actual){
    if(actual==nullptr){
        return false; //Caso base no encontrado
    }
    else if(actual->data==data){
        return true; //Caso base encontra
    }
    else if(actual->data>data){
        return searchRec(data, actual->left);
    }
    else if(actual->data<data){
        return searchRec(data, actual->right);
    }
}

//Peor caso: Complejidad de tipo Lineal O(n)
//Caso medio: Complejidad  O(h)|| h= altura de un arbol
bool MyBST::searchRec(int data){
    return searchRec(data, this->root);
}

//Complejidad de tipo Lineal O(n)
void MyBST::preorder(MyNodeBST* current){
    if(current==nullptr){
        return;
    }
    else{
        cout<<current->data<<",";
        preorder(current->left);
        preorder(current->right);

    }

}

//Complejidad de tipo Lineal O(n)
void MyBST::preorder(){
     if(this->size!=0){
        preorder(this->root);
    }

}

//Complejidad de tipo Lineal O(n)
void MyBST::inorder(MyNodeBST* current){
    if(current==nullptr){
        return;
    }
    else{
        this->nLineas+=current->data;
        inorder(current->left);
        cout<<current->data<<" ip "<<current->ip<<endl;
        inorder(current->right);
    }

}

//Complejidad de tipo Lineal O(n)
void MyBST::inorder(){
     if(this->size!=0){
        inorder(this->root);
    }
    cout<<"Numero de lineas"<<this->nLineas<<endl;
}

//Complejidad de tipo Lineal O(n)
void MyBST::postorder(MyNodeBST* current){
    if(current==nullptr){
        return;
    }
    else{
        postorder(current->left);
        postorder(current->right);
        cout<<current->data<<",";
    }
}

void MyBST::revInorder(MyNodeBST* current, int &contador,int &cont2){
        cont2++;
        if(current==nullptr||contador<=0){
            return;
        }
        else{
            revInorder(current->right, contador,cont2);
            if(contador>0)
                cout<<current->ip<<" "<<current->data<<endl;
            contador--;
            revInorder(current->left, contador,cont2);
        }
    }

void MyBST::revInorder(int &contador){
    int contador2=0;
    this->revInorder(this->root,contador,contador2);
    cout<<"CONTADOR DE LLAMADAS"<<contador2<<endl;
}

//Complejidad de tipo Lineal O(n)
void MyBST::postorder(){
    if(this->size!=0){
        postorder(this->root);
    }
}

//Complejidad de tipo Lineal O(n)
void MyBST::level() {
    if (this->root == nullptr) {
       return;
    }
    queue<MyNodeBST*> nodeQueue;
    nodeQueue.push(this->root);
    while (!nodeQueue.empty()) {
        MyNodeBST* current = nodeQueue.front();
        nodeQueue.pop();
        cout << current->data << ",";
        if (current->left != nullptr) {
            nodeQueue.push(current->left);
        }
        if (current->right != nullptr) {
            nodeQueue.push(current->right);
        }
    }
}

//Complejidad de tipo Lineal O(n)
void MyBST::visit(int orden){
    if(orden>0 && orden<5){
        if(orden==1){
            this->preorder();
            cout<<endl;
        }
        else if(orden==2){
            this->inorder();
            cout<<endl;
        }
        else if(orden==3){
            this->postorder();
            cout<<endl;
        }
        else if(orden==4){
            this->level();
            cout << endl;
        }
    }
    else{
        cout<<"Ese orden no esta disponible debe encontrarse en un rango de 1 a 4"<<endl;
    }
}

//Peor caso: Complejidad de tipo Lineal O(n)
//Caso medio: Complejidad  O(h)|| h= altura de un arbol
void MyBST::ancestors(int data){
    vector<int> ancestros;
    if(this->root==nullptr){
        return;
    }
    else if(this->root->data!=data){
        MyNodeBST* actual= this->root;
        while(actual!=nullptr){
            if(actual->data!=data){
                ancestros.push_back(actual->data);
                if(actual->data<data){
                    actual=actual->right;
                }
                else{
                    actual=actual->left;
                }
            }
            else{
                for(int i=0;i<ancestros.size();i++){
                    cout<<ancestros[i]<<",";
                }
                return;
            }
        }
        return;
    }
}
//Peor caso: Complejidad de tipo Lineal O(n)
//Caso medio: Complejidad  O(h)|| h= altura de un arbol
int MyBST::whatLevelAmI(int data){
    int level =0;
    if(this->root==nullptr){
        return -1;
    }
    else if(this->root->data==data){
        return level;
    }
    else{
        MyNodeBST* actual= this->root;
        while(actual!=nullptr){
            if(actual->data!=data){
                if(actual->data<data){
                    actual=actual->right;
                }
                else{
                    actual=actual->left;
                }
                level++;
            }
            else{
                return level;
                break;
            }
        }
        return -1;
    }
}
//Complejidad de tipo lineal O(n)
int MyBST::height(MyNodeBST* actual){
    if(actual==nullptr){
        return 0;
    }
    int izq=height(actual->left);
    int der=height(actual->right);

    if(der>izq){
        return der+1;
    }else{
        return izq+1;
    }
}

int MyBST::height(){
    return height(this->root);
}
//Complejidad de tipo logaritmica O(log n)
MyNodeBST* MyBST::replace(MyNodeBST* actual) {
    MyNodeBST* a, * b;
    b = nullptr;
    a = actual->left;
    while (a->right != nullptr) {
        b = a;
        a = a->right;
    }
    actual->data = a->data;
    if (b == nullptr) {
        actual->left = a->left;
    } else {
        b->right = a->left;
    }
    return a;
}

//Peor caso: Complejidad de tipo Lineal O(n)
//Caso medio: Complejidad  O(h)|| h= altura de un arbol
MyNodeBST* MyBST::removeRecursive(MyNodeBST* actual, int data, bool& removed) {
    if (actual == nullptr) {
        removed=false;
        return actual;
    }
    else if (data < actual->data) {
        actual->left = removeRecursive(actual->left, data,removed);
    }
    else if (data > actual->data) {
        actual->right = removeRecursive(actual->right, data,removed);
    }
    else {
        MyNodeBST* rNode = actual;
        if (rNode->left == nullptr) {
            actual = rNode->right;
        }
        else if (rNode->right == nullptr) {
            actual = rNode->left;
        }
        else {
            rNode = replace(rNode);
        }
        removed=true;
        this->size--;
        delete rNode;
    }
    return actual;  // Return the modified node
}

//Peor caso: Complejidad de tipo Lineal O(n)
//Caso medio: Complejidad  O(h)|| h= altura de un arbol
bool MyBST::remove(int data){
    bool removed=false;
    this->root=removeRecursive(this->root,data,removed);
    return removed;
}

