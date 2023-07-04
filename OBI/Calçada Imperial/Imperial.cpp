#include <iostream>

using namespace std;

int main(){
int N,j=0,v=1,f;
cin>>N;
int n[N];
bool c=true;

for(int i=0;i<N;++i)
{
    cin>>n[i];
}

for(int k=0; k<N; k++)
{
    f=0;
    j=k;
    for(j;j>=0;j--)
    {
    if(n[j]==n[k+1])c=false;
    }
     v++;
    if(!c)break;
}
cout<< v;
return 0;
}

