#ifndef LIVRARIA_H_INCLUDED
#define LIVRARIA_H_INCLUDED
#include <cctype>
#include <iomanip>
namespace livraria{
class par
{
public:
    int digit;
    char carcter;

    par(char name,int age)
    :carcter(name),digit(age) {}
    void Par();
};

void par::Par()
{
    std::cout<<digit<<"-"<<digit<<"-"<<digit<<"-"<<carcter;
}

class data
{
public:

    data(int dias, int Meses,int anos);
    void Data();
private:
    int ano=2000,dia=1,mes=1;
};

data::data(int dias, int Meses,int anos)
:ano(anos),dia(dias),mes(Meses)
{
if(anos<0||anos>2022)throw std::runtime_error("Ano invalido");;
if(Meses<1||Meses>12)throw std::runtime_error("Mes invalido");
switch(Meses)
{
    case 2:
        {
    if(anos%4==0){
    if(dias<1||dias>29)throw std::runtime_error("Dia invalido");
    }else{if(dias<1||dias>28)throw std::runtime_error("Dia invalido");}
        }
    case 4: case 6: case 9: case 11:
        {
         if(dias<1||dias>30)throw std::runtime_error("Dia invalido");
        }
    Default:
        {
          if(dias<1||dias>31)throw std::runtime_error("Dia invalido");
        }
    }
ano=anos;
dia=dias;
mes=Meses;
}

void data::Data()
{
    std::cout<<std::setw(2)<<std::setfill('0')<<dia<<"/"<<std::setw(2)<<std::setfill('0')<<mes<<"/"<<std::setw(4)<<std::setfill('0')<<ano;
}

class livros
{
public:
bool redefinition=false;
void definebook();
void printbook();
livros();

private:

char *titulo;
char *autor;
par ISBN=par('a',0);
data publicacao=data(11,2,2005);

};
livros::livros()
{
    titulo=(char *)malloc(sizeof(char)+1);
    autor=(char *)malloc(sizeof(char)+1);
}
void livros::definebook()
{
    char carc;
    int dig;
    int d,m,a;
    if(redefinition)throw std::runtime_error("redefinindo o nome");
    std::cout<<"Defina o nome do livro";
    gets(titulo);

    std::cout<<"Defina o nome do autor do livro";
    gets(autor);

    std::cout<<"Digite o dia da publicacao do livro";
    std::cin>>d;
    std::cout<<"Digite o mes da publicacao do livro";
    std::cin>>m;
    std::cout<<"Digite o ano da publicacao do livro";
    std::cin>>a;
    publicacao=data(d,m,a);

    std::cout<<"Digite o digito do ISBN";
    std::cin>>dig;
    if(isdigit(dig))throw std::runtime_error("NAO EH numerico");
    std::cout<<"Digite o caractere do ISBN";
    std::cin>>carc;
    ISBN=par(carc,dig);
}
void livros::printbook()
{
    std::cout<<"\n\nData de Publicacao: ";
    publicacao.Data();
    std::cout<<"\nTitulo............: "<<titulo;
    std::cout<<"\nAutor.............: "<<autor;
    std::cout<<"\nCodigo ISBN.......: ";
    ISBN.Par();
}

};

#endif // LIVRARIA_H_INCLUDED
