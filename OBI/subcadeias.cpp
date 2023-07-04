#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int pallong(string X, int i, int j);

int main()
{
    int N,A;
    string C;
    cin>>N>>C;
    cout <<pallong(C, 0, N - 1);

    return 0;
}

int pallong(string P, int i, int j)
{
    if(i>j)return 0;
    if (i == j)return 1;
    if (P[i] == P[j])return pallong(P, i + 1, j - 1)+2;
    return (pallong(P, i, j - 1)>pallong(P, i + 1, j))?pallong(P, i, j - 1):pallong(P, i + 1, j);
}
