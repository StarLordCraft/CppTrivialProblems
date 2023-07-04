#include <iostream>

int soma(int numero);

using namespace std;

int N,M,S;

int main(){
	int I;
	cin>>N;
	cin>>M;
	cin>>S;
	if(N<1||N>M||M>10000||S<1||S>36){
		return 0;
	}
for(I=--M;I>N;I--){

if(S==soma(I)){
cout<<I;
	return 0;
}
}
	cout<<"-1";
	return 0;
}
int soma(int numero){

 int soma = 0;

    while (numero != 0) {
		soma   += numero % 10;
		numero  = numero / 10;

    }

    return soma;
}
