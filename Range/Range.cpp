#include <iostream>
#include <cctype>
#include <vector>

using namespace std;

string error(string s)
{
    throw runtime_error(s);
}

int get_int();
int get_int(int low, int high);

void skip_toint();

int main(){

int n=get_int(1,10);
cout<<"n: "<<n<<endl;

return 0;
}

void skip_toint()
{
    if(cin.fail()){
        cin.clear();
        char ch;
    while(cin>>ch){
        if(isdigit(ch)){
            cin.unget();
            return;
            }

        }
    }
    error("no input");
}

int get_int()
{
    int n=0;
    while(true){
        if(cin>>n)return n;
        cout<<"Desculpe, mas isso nao eh um numero tente novamente.";
        skip_toint();
    }
}

int get_int(int low,int high)
{
    cout<<"Por favor digite uma inteira no intervalo "<<low<<" a "<<high<<"(Incluindo):\n";

    while (true){
        int n=get_int();
        if((low<=n)&&(n<=high))return n;
        cout<<"Desculpe,mas "<<n<<"Não esta no intervalo ["<<low<<":"<<high<<"] tente novamente\n";
    }
}
