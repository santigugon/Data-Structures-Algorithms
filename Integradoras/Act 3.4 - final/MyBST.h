//A00572499 Santiago Gutierrez Gonzalez y A01281202 Cesar Mecinas Estrada
//Act 3.4 - Actividad Integral de BST
//7/11/2023

//Descripcion- Este programa realiza el ordenamiento de un registro de IPs con su respectivo mensaje, este ordenamiento lo realiza en base a las jerarquias de las IPs y despues nos permite observar cuales son aquellas con mas frecuencias gracias a un inorder al reves
#include <iostream>
#include <string>

#ifndef MYBST_H_INCLUDED
#define MYBST_H_INCLUDED
struct MyNodeBST{
    int data;
    std::string ip;
    MyNodeBST *left,
              *right;
    MyNodeBST(int data, std::string ip){
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
        void revInorder(MyNodeBST* current, int &contador);
    //public:
        MyBST();
        int length();
        bool isEmpty();
        bool search(int data);
        bool searchRec(int data);
        bool insert(int data, std::string ip);
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
