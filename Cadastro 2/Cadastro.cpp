#include <iostream>
using namespace std;

void Banner();

struct Dados{
	string Nome;
	string Sexo;
	int Idade;
	int ANasc;
	string Cidade;
	
	void Add(string stnome, string stsexo, int stidade, int stANasc, string stcidade){
		Nome = stnome;
		Sexo = stsexo;
		Idade = stidade;
		ANasc = stANasc;
		Cidade = stcidade;
	}
	
	void Show(){
		cout << "\nNome ----------------- " << Nome << endl;
		cout << "Idade ---------------- " << Idade << endl;
		cout << "Sexo ----------------- " << Sexo << endl;
		cout << "Ano de Nascimento ---- " << ANasc << endl;
		cout << "Cidade --------------- " << Cidade << endl;
	}
};



int main(){
	Dados c1;
	
	Banner();
	cout << "Digite seu Primeiro Nome: ";
	cin >> c1.Nome;
	while(true){
		cout << "Digite sua Idade: ";
	    cin >> c1.Idade;
	    if(c1.Idade > 0){
	    	break;
		}else{
			cout << "> Idade Invalida. Tente Novamente..." << endl;
		}
	}
	while(true){
		cout << "Digite seu Sexo [F/M]: ";
	    cin >> c1.Sexo;
		if(c1.Sexo == "F" or c1.Sexo == "M" or c1.Sexo == "f" or c1.Sexo == "m"){
			if(c1.Sexo == "F" or c1.Sexo == "f"){
				c1.Sexo = "Feminino";
				break;
			}else if(c1.Sexo == "M" or c1.Sexo == "m"){
				c1.Sexo = "Masculino";
				break;
			}
		}else{
			cout << "> Sexo Invalido. Tente Novamente... " << endl;
		}
	}
	while(true){
		cout << "Digite o Ano que voce Nasceu: ";
	    cin >> c1.ANasc;
	    if(2022 - c1.Idade == c1.ANasc){
	    	break;
		}else{
			cout << "> Essa data nao condiz com sua Idade. Revise Novamente...\n";
		}
	}
	cout << "Digite o nome da sua Cidade: ";
	cin >> c1.Cidade;
	c1.Show();
	
	return 0;
}



void Banner(){
	cout << "================================\n";
	cout << "                     CADASTRO\n";
	cout << "================================\n";
}