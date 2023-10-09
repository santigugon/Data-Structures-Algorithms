#include "MyBST.h"
MyBST::MyBST(){
    this->root=nullptr;
    this->size=0;
}

int MyBST::length(){
    return this->size;
}

bool MyBST::isEmpty(){
    return this->size==0;
}

bool MyBST::insert(int data){
   MyNodeBST* actual= this->root;
   bool insertado=false;
   while(!insertado){
        if(actual->data> data){
            if(actual->left==nullptr){
                actual->left= MyNodeBST*(data);
                insertado=true;
                this->
            }else{
            actual=actual->left;
            }
        }else if( actual->data<data){
            if(actual->right==nullptr){
                actual->right=MyNodeBST(data);
                insertado=true;
            }else{
                actual=actual->right;
            }
        }

   }

}

bool MyBST::search(int data){
    MyNodeBST* actual= this->root;
    while(!actual!=nullptr){
        if(actual->data==data){
            return true;
        }else if(data<actual->data){
            actual=actual->left;
        }else{
            actual=actual->right
        }
    }
    return false;

}



bool MyBST::searchRec(int data, MyNodeBST* actual){
    if(actual==nullptr){
        return false; //Caso base no encontrado
    }else if(actual->data==data){
        return true; //Caso base encontra
    }else if(actual->data>data){
        return searchRec(data, actual->left);
    }else if(actual->data<data){
        return searchRec(data, actual->right);
    }
}

bool MyBST::searchRec(int data){
    return searchRec(data, this->root);

}
