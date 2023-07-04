#include <iostream>

using namespace std;


int main(){
    int o=0,r=1;
    cout<<"Valor que voce deseja alcancar\n";
    cin>>o;
for(int i=0;i<=64;i++){
    if(o<=r){
        cout<<"numero de casas: "<<i<<" numero de graos: "<<r;
        return 0;
    }
r*=2;
}

cout<<"\no inventor do xadrez nao conseguiu essa quantidade de graos";
return 0;

}
