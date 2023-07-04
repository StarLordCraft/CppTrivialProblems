#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
vector<int>P;
vector<int>u;
vector<int>o;
int A,B,C,D,E,K=0,L=0;
cin>>A>>B>>C>>D>>E;
P.push_back(A); P.push_back(B); P.push_back(C); P.push_back(D); P.push_back(E);

sort(P.begin(),P.end());
K=P[4];
for(int i=0;i<P.size();i++){
    if(P[i]==K)u.push_back(P[i]);
    L=((P[i]>=P[i-1])&&(P[i]<K))?P[i]:L;
}
for(int i=0;i<P.size();i++){
    if(P[i]==L)o.push_back(P[i]);
}

cout<<u.size()<<" "<<o.size();
return 0;
}

