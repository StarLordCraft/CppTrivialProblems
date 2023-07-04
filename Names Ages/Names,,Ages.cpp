#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class par
{
public:
    string names;
    double ages;

    par(string name,double age)
    :names(name),ages(age) {}

};

vector<string> names={"Alysson","Alessandro","Aguida","Sarah","Ph"};

int main(){
par a=par("",0);
vector<par> pares;
double age=0;

sort(names.begin(),names.end());

for(int i=0;i<names.size();++i)
{
cout<<"idade de " <<names[i]<<":";
cin>>age;
a=par(names[i],age);
pares.push_back(a);
}

cout<<endl;

for(int i=0; i<pares.size();++i)
{

cout<<pares[i].names<<": "<<pares[i].ages<<endl;

}

return 0;
}

