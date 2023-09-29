#include "iostream";
using namespace std;

unsigned long factorial(int n){
  if(n==0){
    return 1;
  }else{
  return n*factorial(n-1);
  }
}


int main(){
int n;
cout<<"Introduce el numero factorial ";
cin>>n;
cout<<"El resultado del factorial es: "<<factorial(n);
return 0;
}
