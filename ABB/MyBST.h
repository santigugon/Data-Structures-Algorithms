#ifndef MYBST_H_INCLUDED
#define MYBST_H_INCLUDED
struct MyNodeBST{
    int data;
    MyNodeBST *left,
              *right;
    MyNodeBST(int data){
        this->data=data;
        this->left=this->right=nullptr;
    }
};


class MyBST{
   // private:
    public:
        int size;
        MyNodeBST* root;
        bool search(int data,MyNodeBST* current);
        void preorder(MyNodeBST* current);
        void inorder(MyNodeBST* current);
        void postorder(MyNodeBST* current);
        //En caso de hacer alguno de los m�todos recursivos y necesiten
        //otro m�todo que haga la recursi�n deben de colocarlo como privado
        //s�lo la funci�n de preparaci�n ser�a p�blica
    //public:
        MyBST();
        int length();
        bool isEmpty();
        bool search(int data);
        bool searchRec(int data);
        bool searchRec(int data,MyNodeBST*);
        bool insert(int data);//true si lo inserto o no
        bool remove(int data);//si el valor estaba en el �rbol lo borra
                              //y regresa true, caso contrario s�lo regresa false
        //Estudiar borrado en BST
        //Estudiar AVL
        void preorder();
        void inorder();
        void postorder();
        void level();
        void visit(int type);//Type: 1->preorder,2->inorder.3->postorder,4->level
        int height();//regresa la altura del BST.
        void ancestors(int data);//imprime los ancestros del valor pasado.
                                 //el orden de impresi�n debe ser de la ra�z
                                 //hac�a abajo.
                                //Si valor no se localiza en el �rbol no imprime nada
        int whatLevelAmI(int data);//regresa el nivel en que se encuentra el valor
                                   //dentro del �rbol. Si el valor no est� en �rbol imprime -1
};

#endif // MYBST_H_INCLUDED
