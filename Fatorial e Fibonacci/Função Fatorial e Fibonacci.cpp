#include <iostream>
#include <stdlib.h>

using namespace std;

int x=0,f=0,s=0,i=0;

int fatorial(int n);
int fibonacci(int n);
int main(){
	cout<<"determine o numero do qual voce deseja determinar o fatorial: ";
	cin>>x;
	cout<<"o fatorial de "<<x<<" eh: "<<fatorial(x)<<"\n\n";
	
	cout<<"determine qual ponto da sequencia fibonacci voce deseja saber: ";
	cin>> f;
	cout<<"esse ponto na sequencia fibonacci eh: "<<fibonacci(f)<<"\n\n";
	cout<<"determine ate que ponto da sequencia fibonacci voce deseja ver: ";
	cin >>s;
	for(i=0;i<=s;i++){
		cout<<fibonacci(i)<<" ";
	}
	
	return 0;
}
int fatorial(int n){
	if(n==0){
		return 1;
	}else
	{
	return n*fatorial(n-1);
	}
}

int fibonacci(int n){
	if(n==0||n==1){
		return 1;
	}else{
		return fibonacci(n-1)+fibonacci(n-2);
		}
}