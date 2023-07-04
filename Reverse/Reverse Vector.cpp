#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void print(string s, vector<int>& v);
void reverse(vector<int>& v, vector<int>& rev);

vector<int> v={1,3,5,7,9};
vector<int> rev;
vector<int>::iterator it;

int main(){

reverse(v,rev);

print("Original:",v);
cout<<endl;
print("Reverse:",rev);

return 0;
}

void print(string s, vector<int>& v)
{
    cout<<s<<endl;

    for(int i=0; i<v.size(); ++i){
        cout<<v[i]<<" ";
    }

}

void reverse(vector<int>& v, vector<int>& rev)
{
    for(int i=0;i<v.size();++i)
    {

        it=rev.begin();
        rev.insert(it,v[i]);
    }
}
