#include <iostream>
#include <vector>


using namespace std;
class token{
public:
    char n;
    token(char ch)
    :n(ch){};
};
class token_read{
private:
    token buffer;
    bool full;

public:
    token_read()
    :buffer(0),full(false){};
    token get();
    void putback(token t);

};

void error(string st){
throw runtime_error(st);
}

vector<char> num;

token token_read::get(){
if(full){
    full=false;
    return buffer;
}
    char ch;
    cin>>ch;
    switch(ch){
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '0':
    {
        num.push_back(ch);
    }
    }
}
void token_read::putback(token t){
if(full)error("Full Buffer");
buffer=t;
full=false;
}

int main(){
token_read th;
token h=th.get();

token_read tt;
token t=tt.get();

token_read to;
token o=to.get();
if(num.size()>3){
    error("too big number, try something between 100 and 1000");
}


cout<<num[0]<<" hundreads and "<< num[1]<<" tens and "<<num[2]<<" ones";

return 0;
}

