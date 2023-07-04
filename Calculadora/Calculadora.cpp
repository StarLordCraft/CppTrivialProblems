#include <iostream>
#include <math.h>
#include <stdexcept>
#include <stdlib.h>

using namespace std;

int main(){
    double num=0;
    double num1=0;
    char op;

    cout<<"Entre com o numero a expressão desejada: ";
    cin>>num;
    if(!cin){
        cout<<"Digite um numero por favor";
        return 0;
    }

   while(cin>>op){
    cin>>num1;

    switch(op){
case '+':
    num+=num1;
    break;
case '-':
    num-=num1;
    break;
case '*':
    num*=num1;
    break;
case '/':
    num/=num1;
    break;
default:
    "Digite uma operacao conhecida(+,-,*,/)";
    }
    cout<<num;
   }


return 0;
}

