#include <iostream>

using namespace std;

int main(){
int D;
int A;
int N;
int T;
int X;
cin>>D;
cin>>A;
cin>>N;

if(D<1 or D>1000){
	return 0;
}
if(A<1 or A>100){
	return 0;
}
if(N<1 or N>31){
	return 0;
}

X=N;
if(X>14){
	X=14;
}

if (N==1){
	T=31*D;
}else{

T=(31-N+1)*(D+(A*X));
}

cout<<T;
	
	return 0;
}