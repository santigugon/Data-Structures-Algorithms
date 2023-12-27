//A00572499 Santiago Gutierrez Gonzalez y A01281202 Cesar Mecinas Estrada
//Act 5.2 - Actividad Integral de BST
//26/11/2023

//Descripcion- Este programa almacena las direcciones Ip tomandolas como llaves dentro de un Hash table para posteriormente insertarla en una LL de BSTs donde podremos acceder a las fechas donde hubo un registro de esta Ip en forma creciente
#include <iostream>
#include <string>

#ifndef MYBST_H_INCLUDED
#define MYBST_H_INCLUDED

struct MyNodeBST{
    int data;
    std::string fecha;
    MyNodeBST *left,
              *right;
    MyNodeBST(int data, std::string fecha){
        this->data=data;
        this->fecha=fecha;
        this->left=this->right=nullptr;
    }
    MyNodeBST(int data){
        this->data=data;

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
        std::string ip;
    public:
        int size;
        MyNodeBST* root;
        bool search(int data,MyNodeBST* current);
        void preorder(MyNodeBST* current);
        void inorder(MyNodeBST* current, int &nIps);
        void postorder(MyNodeBST* current);
        void revInorder(MyNodeBST* current, int &contador);
    //public:
        MyBST();
        MyBST(std::string ip);
        int length();
        bool isEmpty();
        bool search(int data);
        bool searchRec(int data);
        bool insert(int data, std::string fecha);
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
