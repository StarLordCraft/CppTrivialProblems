#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Token {
    public:
    char kind;
    double value;
    Token(char ch)
    :kind(ch), value(0){ }
    Token(char ch, double val)
    :kind(ch),value(val){ }
    Token get_token(){
    cin>>kind>>value;
    }
};

vector<Token> tok;

double md=0,ss=0;
char loop='s';
bool restrict=false;
bool b=false;

void operacao();
void restricao();
void cochetes();
void multidiv();
void somsub();

int main(){
    while(loop=='s'||loop=='S'){
            md=0,ss=0;
            loop='s';
            restrict=false;
            b=false;
    cout<<"Insira a operacao que deseja calcular, ao final tecle '=' para realizar o calculo: \n";

    operacao();

    restricao();

    if(restrict){
        cout<<"\n\nIMPOSSIVEL ENTENDER A OPERACAO INFORMADA\n\n";
        return 0;
    }

    multidiv();

    somsub();

    cout<<"Deseja inserir outra expressao?[s/n] ";
    cin>>loop;
    system("cls");
    }
    cout<<"\n\nMuito obrigado por usar a calculadora S2";
    return 0;
    }


     void operacao(){
         ss=0;
         md=0;
     while (true){
    Token t = t.get_token();
    tok.push_back(t);
    if(t.kind=='='){
        break;
    }
    }
    }

     void restricao(){
         for(int i=0;i<tok.size();i++){
         if((tok[i].kind != '*')&&(tok[i].kind!='/')&&(tok[i].kind != '+')&&(tok[i].kind!='-')&&(tok[i].kind!='=')&&(tok[i].kind!='{')&&(tok[i].kind!='}')&&(tok[i].kind!='(')&&(tok[i].kind!=')'))
         restrict=true;
         }

     }

     void cochetes(){


     }

     void parenteses(){
}

     void multidiv(){
        for(int i=0;i<tok.size();i++){
            if(tok[i].kind=='*'){
                md=tok[i].value*tok[i-1].value;
                tok[i].value=md;
                tok[i+1].value=md;
            }else if(tok[i].kind=='/'){
                md=tok[i].value/tok[i-1].value;
                tok[i].value=md;
                tok[i+1].value=md;
    }
    }
        for(int i=0;i<tok.size();i++){
            if(tok[i].kind=='*'||tok[i].kind=='/'){
                tok[i].value=md;
    }
    }
    }

     void somsub(){
     for(int i=0;i<tok.size();i++){
            b=false;
     if(tok[i].kind=='+'){
        ss=tok[i].value+tok[i-1].value;
        for(int z=i+1;z<tok.size();z++){
            if(tok[z].kind=='+'||tok[z].kind=='-'){
                tok[z].value=ss;
                    b=true;
     }
            if(b==true){
                    break;
                }
     }
     }
     if(tok[i].kind=='-'){
        ss=tok[i].value-tok[i-1].value;
        for(int y=i+1;y<tok.size();y++){
            if(tok[y].kind=='+'||tok[y].kind=='-'){
                tok[y].value=ss;
                b=true;
     }
     if(b==true){
                    break;
                }
     }
     }
     }
     if(ss==0){
        ss+=md;
     }

     if(tok.size()==1){
        cout<<"\n\nO resultado da expressao inserida eh: "<<tok[0].value<<"\n\n";
        tok.clear();
    }else{
    cout<<"\n\nO resultado da expressao inserida eh: "<<ss<<"\n\n";
    tok.clear();
     }
     }
