#include <iostream>
#include <vector>


using namespace std;

string error(string s)
{
    throw runtime_error(s);
}

const int tnull=-7777; //temperatura impossivel/nula
const int mnull=-1;//mes impossivel/nulo

struct leitura{
int dia;
int hora;
double temperatura;

bool valid();

};

bool leitura::valid()
{
    if(dia>31||dia<0)return false;

    if(hora<0||hora>23)return false;

    if(temperatura<-273)return false;

    return true;
}

struct Dia{
    vector<double> horas;
    Dia();//inicia horas com tnull
};
Dia::Dia()
:horas(24)
    {
        for(int i=0;i<horas.size();++i)horas[i]=tnull;
    }

struct Mes{
    int mes;
    vector<Dia>dia;
    Mes()
    :mes(mnull),dia(32){}//32 porque ignora o 0, assim para termos um vector que conte ate 31 é necessario que seu tamanho seja 32
    };

struct Ano{
int ano;

vector<Mes>mes;

Ano():mes(13){}//pela mesma razao dos dias é necessario que esse vector tenha tamanho 13

};

istream& operator>>(istream& is,leitura& l)//pega leituras com "is" e coloca dentro de l
//formato:( dia hora temperatura )
{
char ch1;
if(is>>ch1&&ch1!='('){
    is.unget();
    is.clear(ios_base::failbit);
    return is;
   }
   char ch2;
   int d;
   int h;
   double t;
   is>>d>>h>>t>>ch2;
   if(!is||ch2!=')')error("Erro na leitura");
   l.dia=d;
   l.hora=h;
   l.temperatura=t;
   return is;
}

istream& operator>>(istream& is, Mes& m)
//formato: jan,fev,mar...
{
    char ch=0;
    if(is>>ch&&ch!='{'){
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }
    string mes_nome;
    string mm;
    is>>mes_nome>>mm;
    if(!is||mes_nome!="mes")error("mes iniciado de forma errada");

    leitura r;

    int invalidas=0;

    while(is>>r){
        if(r.valid()){
            m.dia[r.dia].horas[r.hora]=r.temperatura;
        }else{ ++invalidas; }
    }
    if(invalidas)error("Leituras invalidas");
    return is;
}

istream& operator>>(istream& is, Ano a)
{
   char ch;
   is>>ch;
   if(ch!='['){
    is.unget();
    is.clear(ios::failbit);
    return is;
       }
   string year_marker;
   int yy;
   is>>year_marker>>yy;
   if(!is||year_marker!="ano")error("Ano nao inicializado corretamente");

    while(true){
        Mes m=Mes();
        if(!(is>>m))break;
        a.mes[m.mes]=m;

    }
    return is;
   }

   void print_year(ofstream& ofs, vector<Ano> a);

int main(){
cout<<"Abra o arquivo"<<endl;
string name;
cin>> name;
static fstream ifs(name.c_str());
if(!ifs)error("Nao foi possivel abrir o arquivo");

ifs.exceptions(ifs.exceptions()|ios_base::badbit);

cout<<"Por favor entre com o arquivo de saida"<<endl;

cin>>name;

ofstream ofs(name.c_str());

if(!ofs)error("Nao foi possivel abrir o arquivo de saida");

vector<Ano>ys;
while(true){
    Ano y;
    if(!(ifs>>y))break;
    ys.push_back(y);
}

cout<<"Leitura: "<<ys.size()<<" anos lidos\n";

for(auto i:ys)print_year(ofs,ys[i]);

return 0;
}

void print_year(ofstream& ofs, vector<Ano> a)
{
    for(auto i:a){
        ofs<<"Ano"<<a(ifs,a);
    }

}

