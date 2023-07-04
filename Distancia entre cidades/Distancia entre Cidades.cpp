#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main(){
    int soma=0,d=0,tam=0;
    char c='s';

    vector <int> dist;

    while(c=='s'||c=='S'){
        cout<<"Digite a distancia analisada: ";
        cin>>d;
        dist.push_back(d);
        system("cls");
        cout<<"deseja adicionar mais distancias?[s/n]\n";
        cin>>c;
        }
        for(int i=0;i<dist.size();i++){
            soma+=dist[i];

        }
        for(int i=0;i<dist.size();i++){
            tam++;

        }
tam--;
        cout<<"A distancia entre as cidades eh: "<<soma<<endl;
        sort(dist.begin(),dist.end());
        cout<<"A menor distancia eh: "<<dist[0]<<endl;
        cout<<"A maior distancia eh: "<<dist.at(tam)<<endl;
        cout<<"Distancias informadas (menor para a maior): ";
        for(int i=0;i<dist.size();i++){
            cout<<dist[i]<<", ";

        }


return 0;
}

