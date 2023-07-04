#include <iostream>
#include <vector>

using namespace std;
void print(string s, vector<int>& v);
int fibonacci(int x, int y, vector<int>& v ,int n);

vector<int> v;

int main(){

fibonacci(1,1,v,10);
print("fibonacci gostosa:",v);

return 0;
}

void print(string s, vector<int>& v)
{
    cout<<s<<endl;

    for(int i=0; i<v.size(); ++i){
        cout<<v[i]<<" ";
    }

}

int fibonacci(int x, int y, vector<int>& v ,int n)
{
    int res=0;
    v.push_back(x);
    v.push_back(y);
    for(int i=0;n>0;++i)
    {
    res=v[i]+v[i+1];
    v.push_back(res);
    --n;

    }
}
