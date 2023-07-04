#include <iostream>
#include <vector>

using namespace std;

int main(){
int V=0,N=0,M=0,X=0,Y=0;
int P[M][4];
cin>>V>>N>>M;
for(int i=0;i<M;i++){
    for(int j=0;j<4;j++){
        cin>>P[i][j];
    }
}
cin>>X>>Y;

for(int i=0;i<M;i++){
    for(int j=0;j<4;j++){
        cout<<P[i][j]<<" ";
    }
    cout<<endl;
}

return 0;
}
