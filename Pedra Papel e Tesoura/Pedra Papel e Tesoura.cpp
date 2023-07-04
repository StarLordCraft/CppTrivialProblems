#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>

using namespace std;

int main(){
    char c='s';
    while(c=='s'||c=='S'){
    system("cls");
    int n=0;
    srand(time(0));
    int randomNumber=0;
    randomNumber = (rand() % (4-1) + 1);

    cout<<"Digite sua jogada (pedra-1,papel-2 ou tesoura-3)\n";
    cout<<randomNumber<<"\n";
    cin>>n;
    if(n==1){
        cout<<"pedra\n";
    }else if(n==2){
        cout<<"papel\n";
    }else if(n==3){
        cout<<"tesoura\n";
    }
    switch(n){
        case 1:
        switch(randomNumber){
        case 1:
            cout<<"Empate\n\n";
            break;
        case 2:
            cout<<"Voce perdeu\n\n";
            break;
        case 3:
            cout<<"Voce venceu\n\n";
            break;
    }
    break;
        case 2:
            switch(randomNumber){
        case 1:
            cout<<"Voce venceu\n\n";
            break;
        case 2:
            cout<<"Empate\n\n";
            break;
        case 3:
            cout<<"Voce perdeu\n\n";
            break;
            }
    break;
        case 3:
            switch(randomNumber){
        case 1:
            cout<<"Voce perdeu\n\n";
            break;
        case 2:
            cout<<"Voce venceu\n\n";
            break;
        case 3:
            cout<<"Empate\n\n";

            }
        break;
        default:
            cout<<"ERRO, DIGITE 1 PARA PEDRA,2 PARA PAPEL, 3 PARA TESOURA\n\n";
            break;
    }
    cout<<"Deseja continuar jogando ???[s/n]";
    cin>>c;
    }

    cout<<"MUITO OBRIGADO POR JOGAR!";
return 0;
}
