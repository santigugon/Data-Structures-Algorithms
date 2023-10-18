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
        cout<<current->data<<",";
        preorder(current->left);
        preorder(current->right);

    }

}

void MyBST::preorder(){
     if(this->size!=0){
        preorder(this->root);
    }

}

void MyBST::inorder(MyNodeBST* current){
    if(current==nullptr){
        return;
    }else{
        inorder(current->left);
        cout<<current->data<<",";
        inorder(current->right);

    }

}

void MyBST::inorder(){
     if(this->size!=0){
        inorder(this->root);
    }
}

void MyBST::postorder(MyNodeBST* current){
    if(current==nullptr){
        return;
    }else{
        postorder(current->left);
        postorder(current->right);
        cout<<current->data<<",";

    }

}

void MyBST::postorder(){
    if(this->size!=0){
        postorder(this->root);
    }
}


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
            cout << endl;
        }
    }else{
        cout<<"Ese orden no esta disponible debe encontrarse en un rango de 1 a 4"<<endl;
    }

}

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
                }else{
                    actual=actual->left;
                }
            }else{
                for(int i=0;i<ancestros.size();i++){
                    cout<<ancestros[i]<<",";
                }
                return;

            }


        }
        return;
    }


}

int MyBST::whatLevelAmI(int data){
    int level =0;
    if(this->root==nullptr){
        return -1;
    }
    else if(this->root->data==data){
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

MyNodeBST* MyBST::removeRecursive(MyNodeBST* actual, int data, bool& removed) {
    if (actual == nullptr) {
        removed=false;
        return actual;  // Return null
    } else if (data < actual->data) {
        actual->left = removeRecursive(actual->left, data,removed);
    } else if (data > actual->data) {
        actual->right = removeRecursive(actual->right, data,removed);
    } else {
        MyNodeBST* rNode = actual;
        if (rNode->left == nullptr) {
            actual = rNode->right;
        } else if (rNode->right == nullptr) {
            actual = rNode->left;
        } else {
            rNode = replace(rNode);
        }
        removed=true;
        this->size--;
        delete rNode;
    }
    return actual;  // Return the modified node
}


bool MyBST::remove(int data){
    bool removed=false;
    this->root=removeRecursive(this->root,data,removed);
    return removed;
}
