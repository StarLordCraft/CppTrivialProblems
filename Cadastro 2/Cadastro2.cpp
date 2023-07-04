#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>

using namespace std;

class Cadastro{
public:
	char *nome;
	char *cidade;
	char *s;
	int idade;
	int dianasc;
	int mesnasc;
	int anonasc;
	Cadastro();

	void mostra(){
		cout<<"\nNome..........: "<<nome<<"\n";
		cout<<"Cidade........: "<<cidade<<"\n";
		cout<<"Data de Nascimento:"<<setw(2)<<setfill('0')<<dianasc<<"/"<<setw(2)<<setfill('0')<<mesnasc<<"/"<<setw(4)<<anonasc;
	}
};
Cadastro::Cadastro(){
    nome=(char *)malloc(sizeof(char)+1);
    cidade=(char *)malloc(sizeof(char)+1);
    s=(char *)malloc(sizeof(char)+1);
}

void banner();

char r;
int main(){
    Cadastro *c1=new Cadastro();
    do{
    if(r=='s'||r=='S'){
        gets(c1->s);
        }
	system("cls");
    banner();
	cout<<"\n\nPor favor, digite seu nome COMPLETO: ";
	gets(c1->nome);
	cout<<"\nDigite sua cidade: ";
	gets(c1->cidade);
	system("cls");
	while(true){
		cout<<"\nDigite sua idade: ";
		cin>>c1->idade;
		if(c1->idade<18){
			cout<<"Voce eh menor de 18 anos, idade invalida";
		}
		else{
			break;
		}
	}

	while(true){
		cout<<"\nDigite o seu dia de nascimento:";
		cin>>c1->dianasc;
		if(((c1->dianasc)<=0)||((c1->dianasc)>31)){
			cout<<"Dia invalido";
		}else{
		break;
		}

	}
	system("cls");
	while(true){
		cout<<"\nDigite o seu mes de nascimento:";
		cin>>c1->mesnasc;
		if(c1->mesnasc<=0||c1->mesnasc>12){
			cout<<"Mes invalido, tente novamente.";
		}else{
			break;
		}
	}
	system("cls");
	while(true){
		cout<<"\nDigite o ano em que voce nasceu:";
		cin>>c1->anonasc;
		if((2022-(c1->anonasc))==c1->idade){
			break;
		}else{
			cout<<"Ano invalido, Confira os dados e tente novamente";
		}

	}
	system ("cls");
	cout<<"Seus dados: "<<"\n\n";
	c1->mostra();
	cout<<"\n\n"<<"deseja alterar o cadastro(S/n)?";
	cin>>r;
}while(r=='s'|| r=='S');

    fstream arquivo;
    arquivo.open("Dados.txt",ios::out|ios::app);
    arquivo<<"======================================="<<endl;
    arquivo<<"                              NOVO USUÁRIO:"<<endl;
    arquivo<<"======================================="<<endl;
    arquivo<<"Nome..............: " <<c1->nome<<endl;
    arquivo<<"Cidade............: "<<c1->cidade<<endl;
    arquivo<<"Idade...............: "<<c1->idade<<endl;
    arquivo<<"Data de Nascimento: "<<setw(2)<<setfill('0')<<c1->dianasc<<"/"<<setw(2)<<setfill('0')<<c1->mesnasc<<"/"<<setw(4)<<c1->anonasc<<"\n\n";
    arquivo.close();
	return 0;
}

void banner(){
	cout<<"======================================="<<"\n";
	cout<<"              CADASTRO:    "<<"\n";
	cout<<"=======================================";
}

