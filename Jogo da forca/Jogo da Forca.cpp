#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

class pal{
public:
    char* n;
    char* m;
    pal();
};
pal::pal(){
n=(char *)malloc(sizeof(char)+1);
m=(char *)malloc(sizeof(char)+1);
}
int acertos=0,chances=0,k=0;
char letra,s;
string palavra,secreta;
bool acerto=false;

void prejogo();
void jogo();

int main (){
	pal *c1=new pal();
	do{
		prejogo();
		if(s=='s'||s=='S')gets(c1->m);
        gets(c1->n);
        palavra=c1->n;
        system("cls");
        for(int i=0;i<palavra.size();i++)if(palavra[i]==' ')k++;
        for(int i=0;i<palavra.size();i++)secreta[i]='-';
		jogo();
		cout<<"\n\n"<<"deseja continuar jogando s/n?(s=sim,n=nao)";
		cin>> s;
	}while(s=='s'||s=='S');
	cout<<"Muito obrigado por jogar!";

	return 0;
}

void prejogo(){
	system("cls");
	acertos=0;
	chances=0;
	k=0;
	cout<<"digite a palavra secreta(nao deixe o segundo jogador ver):";
}

bool istyped(char& a,vector<char>& v)
{
    for(auto i:v)if(i==a)return true;
    return false;
}

void jogo(){
    vector<char> letras;
		cout<<"determine a quantidade de chances que seu oponente tera:";
	cin>>chances;
	system("cls");
	while((chances>0)&&(acertos<palavra.size()-k)){
        acerto=false;
		cout<<"voce tem:"<<chances<<" chances"<<"\n\n";
		cout<<"a palavra secreta eh:";
		for (int i=0;i<palavra.size();i++)cout<<secreta[i];
		cout<<"\n\nTentativas:";for(auto i:letras)cout<<i<<",";
		cout<<"\n\n"<<"sua tentativa eh:";
		cin>>letra;
		for(int i=0;i<palavra.size();i++){
			if((palavra[i]==letra)&&(!(istyped(letra,letras)))){
				acerto=true;
				acertos++;
				secreta[i]=palavra[i];
			}
		}
		if(!(acerto)&&(!(istyped(letra,letras))))chances--;
        letras.push_back(letra);
        system("cls");
}
if(chances==0){
	cout<<"nao foi dessa vez, voce perdeu";
}else{
	cout<<"PARABENS, voce venceu";
}
}
