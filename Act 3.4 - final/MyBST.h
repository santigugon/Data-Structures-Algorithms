//SANTIAGO GUTIERREZ GONZALEZ
//MATRICULA:A00572499
//ACT 3.1-Operaciones avanzadas en un BST
//Descripcion- Programa que implementa la estructura de datos de una arbol binario de busqueda haciendo uso del struct MyNodeBST e implementando su metodos
//Fecha: 18/10/2023
#include "NodoIP.h"

#ifndef MYBST_H_INCLUDED
#define MYBST_H_INCLUDED
struct MyNodeBST{
    int data;
    string ip;
    MyNodeBST *left,
              *right;
    MyNodeBST(int data, string ip){
        this->data=data;
        this->ip=ip;
        this->left=this->right=nullptr;
    }
    void increaseData(){
        this->data++;
    }
};


class MyBST{
    private:
        int nLineas=0;
        MyNodeBST* replace(MyNodeBST *actual);
        MyNodeBST* removeRecursive(MyNodeBST* act, int data, bool& removed);
        int height(MyNodeBST*);
        bool searchRec(int data,MyNodeBST*);
    public:
        int size;
        MyNodeBST* root;
        bool search(int data,MyNodeBST* current);
        void preorder(MyNodeBST* current);
        void inorder(MyNodeBST* current);
        void postorder(MyNodeBST* current);
        void revInorder(MyNodeBST* current, int &contador, int& cont2);
    //public:
        MyBST();
        int length();
        bool isEmpty();
        bool search(int data);
        bool searchRec(int data);
        bool insert(int data, string ip);
        bool remove(int data);
        void preorder();
        void inorder();
        void postorder();
        void level();
        void visit(int type);
        void revInorder(int &contador);
        int height();
        void ancestors(int data);
        int whatLevelAmI(int data);
};

#endif // MYBST_H_INCLUDED
