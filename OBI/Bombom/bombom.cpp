#include <iostream>
#include <vector>
using namespace std;

class baralho{
public:
    char naipe;
    char carta;

    baralho(char a, char b)
    :carta(a),naipe(b){}
} ;

baralho domin=baralho('a','b');

int main(){
    char n,a;
    cin>>n>>a;
    domin=baralho(n,a);
    int luana=0, edu=0;
    luana=pontos();

return 0;
}

int pontos()
{
    int pontos=0;
    char a,b,c,d,e,f;
    cin>>a>>b;
    baralho i=baralho(a,b);
    switch(i.carta)
    {
    case 'A':
        {
            pontos+=10;
            if(domin.naipe==i.naipe)){
                pontos+=4
                break;
            }
            break;
        }
    case 'J':
        {
        pontos+=11;
        if(domin.naipe==i.naipe)
                {
                pontos+=4
                break;
                }
        break;
        }
    case 'Q'
        {
        pontos+=12;
            if(domin.naipe==i.naipe)
                {
                pontos+=4
                break;
                }
            break;
        }
    case 'K':
        {
        pontos+=13;
        if(domin.naipe==i.naipe)
                {
                pontos+=4
                break;
                }
                break;
        }
    }
    cin>>c>>d;
    baralho j=baralho(c,d);
    switch(j.carta)
    {
    case 'A':
        {
            pontos+=10;
            if(domin.naipe==j.naipe)){
                pontos+=4
                break;
            }
            break;
        }
    case 'J':
        {
        pontos+=11;
        if(domin.naipe==j.naipe)
                {
                pontos+=4
                break;
                }
        break;
        }
    case 'Q'
        {
        pontos+=12;
            if(domin.naipe==j.naipe)
                {
                pontos+=4
                break;
                }
            break;
        }
    case 'K':
        {
        pontos+=13;
        if(domin.naipe==j.naipe)
                {
                pontos+=4
                break;
                }
                break;
        }
    }
    cin>>e>>f;
    baralho k=baralho(e,f);

    switch(k.carta)
    {
    case 'A':
        {
            pontos+=10;
            if(domin.naipe==i.naipe)){
                pontos+=4
                break;
            }
            break;
        }
    case 'J':
        {
        pontos+=11;
        if(domin.naipe==k.naipe)
                {
                pontos+=4
                break;
                }
        break;
        }
    case 'Q'
        {
        pontos+=12;
            if(domin.naipe==k.naipe)
                {
                pontos+=4
                break;
                }
            break;
        }
    case 'K':
        {
        pontos+=13;
        if(domin.naipe==k.naipe)
                {
                pontos+=4
                break;
                }
                break;
        }
    }

return pontos;
}
