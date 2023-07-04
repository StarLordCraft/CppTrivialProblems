#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> primos;

int divisores(int d,int p=2);

int main(){
int x=0,y=0;
cout<<"Numeros primos de: ";
cin>>y;
cout<<" a: ";
cin>>x;
cout<<endl;

divisores(x,y);

for(int z=0;z<primos.size();z++){
    cout<<primos[z]<<endl;
}

return 0;
}

int divisores(int d,int p){
    int vezes=0;
    for(p=2;p<=d;p++){
    for(int x=1;x<=d;x++){
        if(p % x != 0){
            vezes++;
        }
    }
     if(vezes+2==d){
            primos.push_back(p);
        }
        vezes=0;
    }
    return 0;
}
