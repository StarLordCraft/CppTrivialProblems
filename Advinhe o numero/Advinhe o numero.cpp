#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main(){
    char c='s';
    while(c=='s'||c=='S'){
        srand(time(0));
    int randomNumber=0,tent=0,chances=0,tents=0;
    randomNumber = (rand() % (100-1) + 1);
    chances=7;
    while(chances>0){
    cout<<"Voce tem "<<chances<< " chances para descobrir o numero secreto, Boa sorte!\n\n";
    cout<<"TENTATIVA:\n";
    cin>>tent;
    tents++;
    chances--;
    if(tent<randomNumber){
        cout<<"MUITO BAIXO!\n";
    }else if(tent>randomNumber){
        cout<<"MUITO ALTO!\n";
    }else{
        break;
    }

    }
    system("cls");
    if(chances==0){
        cout<<"Voce perdeu ;-;\n\n";
    }else{
    cout<<"Voce venceu. PARABENS!!!! :-)\n"<<"ganhou com: "<<tents<<"Tentativas\n\n";
    }
    cout<<"quer continuar jogando ?[s/n]";
    cin>>c;
    }
    cout<<"\nMUITO OBRIGADO POR JOGAR!!";
return 0;
}

