#include <iostream>

using namespace std;

int D;

int main(){
	cin>>D;
	if(D%8==0){
		cout<<"3";
	}else if(D%8==6){
		cout<<"1";
	}else if (D%8==7){
		cout<<"2";
	}else{
		cout<<"erro";
	}
	if(D<6){
		cout<<"erro";
		return 0;
	}else if(D>800008){
		cout<<"erro";
		return 0;
	}
	return 0;
}