#include <iostream>
#include "MyBST.h"
#include <queue>
#include <vector>

using namespace std;

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
        if(this->size==0){
            actual= new MyNodeBST(data);
            insertado=true;
            this->root=actual;
            this->size++;
            return true;
        }
        else if(actual->data> data){
            if(actual->left==nullptr){
                actual->left= new MyNodeBST(data);
                this->size++;
                insertado=true;
                return true;
            }else{
                actual=actual->left;
            }
        }else if( actual->data<data){
            if(actual->right==nullptr){
                actual->right= new MyNodeBST(data);
                insertado=true;
                this->size++;
                return true;
            }else{
                actual=actual->right;
            }
        }else{
            cout<<"Los elementos son iguales y no se pudo insertar"<<endl;
            return false;
        }

   }

}

bool MyBST::search(int data){
    MyNodeBST* actual= this->root;
    while(actual!=nullptr){
        if(actual->data==data){
            return true;
        }else if(data<actual->data){
            actual=actual->left;
        }else{
            actual=actual->right;
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

void MyBST::preorder(MyNodeBST* current){
    if(current==nullptr){
        return;
    }else{
        cout<<current->data<<", ";
        preorder(current->left);
        preorder(current->right);

    }

}

void MyBST::preorder(){
     if(this->size==0){
        cout<<"El arbol esta vacio no hay nada a imprimir"<<endl;
    }else{
        preorder(this->root);
    }

}

void MyBST::inorder(MyNodeBST* current){
    if(current==nullptr){
        return;
    }else{
        inorder(current->left);
        cout<<current->data<<", ";
        inorder(current->right);

    }

}

void MyBST::inorder(){
     if(this->size==0){
        cout<<"El arbol esta vacio no hay nada a imprimir"<<endl;
    }else{
        inorder(this->root);
    }
}

void MyBST::postorder(MyNodeBST* current){
    if(current==nullptr){
        return;
    }else{
        postorder(current->left);
        postorder(current->right);
        cout<<current->data<<", ";

    }

}

void MyBST::postorder(){
    if(this->size==0){
        cout<<"El arbol esta vacio no hay nada a imprimir"<<endl;
    }else{
        postorder(this->root);
    }
}


void MyBST::level() {
    if (this->root == nullptr) {
        cout << "El arbol esta vacio no hay nada a imprimir" << endl;
        return;
    }

    queue<MyNodeBST*> nodeQueue;
    nodeQueue.push(this->root);

    while (!nodeQueue.empty()) {
        MyNodeBST* current = nodeQueue.front();
        nodeQueue.pop();

        cout << current->data << ", ";

        if (current->left != nullptr) {
            nodeQueue.push(current->left);
        }
        if (current->right != nullptr) {
            nodeQueue.push(current->right);
        }
    }
    cout << endl;
}

void MyBST::visit(int orden){
    if(orden>0 && orden<5){
        if(orden==1){
            this->preorder();
            cout<<endl;
        }else if(orden==2){
            this->inorder();
            cout<<endl;
        }else if(orden==3){
            this->postorder();
            cout<<endl;
        }else if(orden==4){
            this->level();
        }
    }else{
        cout<<"Ese orden no esta disponible debe encontrarse en un rango de 1 a 4"<<endl;
    }

}

void MyBST::ancestors(int data){
    vector<int> ancestros;
    if(this->root->data==data){
        cout<<"El elemento no tiene ancestros por que es la raiz"<<endl;
    }else{
        MyNodeBST* actual= this->root;
        while(actual!=nullptr){
            if(actual->data!=data){
                ancestros.push_back(actual->data);
                if(actual->data<data){
                    actual=actual->right;
                }else{
                    actual=actual->left;
                }
            }else{
                for(int i=ancestros.size()-1;i>=0;i--){
                    cout<<ancestros[i]<<", ";
                }
                return;

            }


        }
        cout<<"No se encontro el dato en el arbol"<<endl;
        return;
    }


}

int MyBST::whatLevelAmI(int data){
    int level =0;
    if(this->root->data==data){
        return level;
    }else{
        MyNodeBST* actual= this->root;
        while(actual!=nullptr){
            if(actual->data!=data){
                if(actual->data<data){
                    actual=actual->right;
                }else{
                    actual=actual->left;
                }
                level++;
            }else{
                return level;
                break;
            }
        }
        return -1;
    }
}

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
/*
bool MyBST::remove(int data) {
    return remove(this->root, data);
}

MyNodeBST* MyBST::remove(MyNodeBST* root, int data) {
    if (root == nullptr) {
        // The value is not in the tree
        return root;
    }

    if (data < root->data) {
        // The value to be removed is in the left subtree
        root->left = remove(root->left, data);
    } else if (data > root->data) {
        // The value to be removed is in the right subtree
        root->right = remove(root->right, data);
    } else {
        // Node with the data to be removed is found

        // Node with only one child or no child
        if (root->left == nullptr) {
            MyNodeBST* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            MyNodeBST* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children, get the in-order successor (smallest in the right subtree)
        MyNodeBST* temp = minValueNode(root->right);

        // Copy the in-order successor's data to this node
        root->data = temp->data;

        // Delete the in-order successor
        root->right = remove(root->right, temp->data);
    }

    return root;
}

MyNodeBST* MyBST::minValueNode(MyNodeBST* node) {
    MyNodeBST* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}
*/
