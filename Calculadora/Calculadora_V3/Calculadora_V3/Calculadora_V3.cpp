//calculadora simples!!

#include <iostream>
#include <vector>
#include <cmath>
#include <cctype>

using namespace std;

double statement();   //função que decide se é uma declaração de variavel, ou uma expressao comum.
double define();     //função que define o valor de uma variavel.
double expression(); // Exp = soma e subtracao
double term();      // Term = divisao multiplicacao e resto
double factorial();  // calcula o fatorial de numeros
double exproot();   // potencias e raizes.
double primary();   // Primary = funcao que serve para parenteses,pochetes e negativar numeros

void operacoes();
//void error(string);  // Throw errors

//error
void error(string st)
{
    throw runtime_error(st);
}

class Token
{
public:
    char kind;
    double value;
    string name;

    Token(char ch)
        :kind(ch) {} //funcao vazia, so le operadores separadamente.

    //construtor para os operadores e operacoes
    Token(char ch, double val)
        :kind(ch), value(val) {}//funcao vazia tbm

    Token(char ch, string n)
        :kind(ch), name(n) {};
};

class Token_stream
{
private:
    bool full;      // Determina se o buffer esta cheio ou nao
    Token buffer;   // buffer armazena apenas um token
public:
    Token_stream() :full(false), buffer(0) {};
    Token get();
    void putback(Token t);
    void ignore(char c);

};

class Variable {
public:
    string name;
    double value;
    Variable(string n, double v)
        :name(n), value(v) {}
};

vector<Variable> var_table;//declaração de algumas variaveis definidas pelo usuario e algumas já padroes tal como pi

bool is_declared(string var)
{
    for (int i = 0; i < var_table.size(); ++i) {
        if (var_table[i].name == var) {
            return true;
        }
    }

    return false;

}

void define_name(string var, double val)//funções que auxiliam a classe variable
{
     for (int i = 0; i < var_table.size(); ++i){
        if (var_table[i].name == var){
               var_table[i].value=val;
                return;
        }
     }
    var_table.push_back(Variable(var, val));
}

double get_value(string s)
{
    for (int i = 0; i < var_table.size(); ++i) {
        if (var_table[i].name == s) return var_table[i].value;
    }
    error("get: undefined variable ");
}


const char number = '8';//definindo um numero aleatorio, para informar o programa que ele esta lendo um numero
const char quit = 'q';//definindo uma forma de fechar a calculadora.
const char print = ';';//definindo um botao para finalizar uma operacao
const string key = "let";
const string prompt = "> ";
const string result = "= ";

// Essa funcao salva caracteres que foram lidos em determinada funcao, para o uso desses caracteres em outra funcao.
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer.");
    buffer = t;         //copiar um token para dentro do buffer
    full = true;        //buffer agora esta cheio
}

void Token_stream::ignore(char c) {
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;
    char ch = 0;
    while (cin >> ch) {
        if (ch == c)
            return;
    }
}

// Ler caracteres
Token Token_stream::get()
{
    if (full) {   // analisar se ja tem um token dentro do buffer
        //usar o token dentro do buffer e removélo do buffer
        full = false;
        return buffer;
    }
    // se buffer estiver vazio é necessario ler um novo operador e adicioná-lo em buffer
    char ch;
    cin >> ch;       // lendo um operador
    switch (ch)
    {//operadores que a calculadora suporta
    case 'q':
    case ';':
    case '{':
    case '}':
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '!':
    case '?':
    case '^':
    case '&':
    {
        return Token(ch);
        break;
    }
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch); // Porque houve comparacao meio que "transformacao" de inteiros em uma char.
        double val;
        cin >> val;
        return Token(number, val);
        break;
    }
    default:
    {
        if (isalpha(ch)) {
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch)) || isdigit(ch))s += ch;
            if (is_declared(s)) {
                if (ch == '=') {
                    return Token('=', s);
                }
                cin.putback(ch);
                return Token('8', get_value(s));
            }
            return Token('=', s);
            break;
        }
        error("Bad token");
        break;
    }
    }
}


bool definev; //ponto de ativacao da função statement essa variavel, caso retorne verdadeira mostrará que se trata de uma definição de variavel
string n;
Token_stream ts;

void clean_up_mess()//função que auxilia a pegar erros e não fechar o programa
{
    ts.ignore(print);//caça o final de uma operacao para printar juntas caso seja inserido mais de uma operacao ao mesmo tempo, exemplo: 1+1; 2*10;
}

// Primary
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '?':
    {
        operacoes();
        return 0;
        break;
    }
    case '{':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != '}') error("'}' expected");
        return d;
        break;

    }
    case '(':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
        break;
    }

    case '-':
    {

        return -1 * primary();
        break;
    }
    case '+':
    {
        return primary();
        break;
    }

    case number:
    {
        return t.value;
        break;
    }
    default:
        error("primary expected");
    }

}

double exproot()
{
    double left = primary();
    double res = left;

    Token t = ts.get();
    switch (t.kind)
    {
    case '^':
    {
        double i = primary();

        left = pow(res, i);

        return left;
        break;
    }
    case 'r':
    {
        double i = primary();
        if (i < 0 && fmod(res, 2) == 0) error("negative number in a pair indice");
        if (i < 0) {
            left = pow(-i, 1 / res);
            return -left;
        }
        else {
            left = pow(i, 1 / res);

            return left;
        }
        break;
        break;
    }
    default:
        ts.putback(t);
        return left;

    }

}

double factorial()
{
    double left = exproot();
    Token t = ts.get();
    switch (t.kind) {
    case '!':
    {
        double res = 1;
        if (left < 0) {
            error("Factorial of a negative number.");
        }
        if (left == 0) {
            return 1;
        }
        t = ts.get();

        while (left > 0) {
            if (left == 1) {
                break;
            }
            res *= left * (left - 1);
            left = left - 2;
        }
        ts.putback(t);
        return res;
        break;
    }
    default:
        ts.putback(t);
        return left;
    }

}

// Term
double term()
{
    double left = 0;
    left = factorial();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
        case '*':
            left *= factorial();
            t = ts.get();
            break;
        case '/':
        {
            double d = factorial();
            if (d == 0) error("divided by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            double d = term();
            if (d == 0)error("divided by 0");
            double res = left;
            left = fmod(res, d);
            t = ts.get();
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}

// Expression
double expression()
{
    definev = false;
    double left = 0;
    left = term();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
        case '+':
            left += term();
            t = ts.get();
            break;
        case '-':
            left -= term();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}

double define()
{
    Token t = ts.get();
    double val = expression();
    define_name(t.name, val);
    n = t.name;
    definev = true;
    return val;

}

double statement()
{
    Token t = ts.get();
    switch (t.kind) {
    case '=':
    {
        ts.putback(t);
        return define();
        break;
    }
    default:
        ts.putback(t);
        return expression();
    }
}

void calculate()
{

    while (cin) {
        try {
            cout << endl << prompt;
            Token t = ts.get();
            while (t.kind == print)t = ts.get();
            if (t.kind == quit)return;
            ts.putback(t);
            double r = statement();
            if (definev)
            {
                cout << n << result << r << endl;
            }
            else
            {
                cout << result << r << endl;
            }
        }
        catch (runtime_error& e) {
            cerr << e.what() << endl;
            clean_up_mess();
        }
    }
}

// execution starts from here
int main()
{
    define_name("pi", 3.1415);
    define_name("e", 2.71828);
    define_name("g", 9.80665);
    cout << endl << endl << "INSIRA '?' PARA LER AS INSTRUCOES|OPERACOES|VARIAVEIS DECLARADAS." << endl << endl;
    try {
        calculate();
        cout << endl << endl << "OBRIGADO POR USAR" << endl;
        cout << "CRIADOR:RAFAEL FELIPE VIANA ALVES" << endl << endl;
    }
    catch (runtime_error& e) {
        cerr << e.what() << endl;

    }

}

void operacoes()
{
    cout << "Por favor ao declarar uma variavel utilize apenas letras e numeros. sendo que o primeiro" << endl;
    cout << "caractere de uma variavel deve ser uma letra. A declaracao de variaveis eh sempre variavel=expressao" << endl;
    cout << endl << "OPERACOES" << endl;
    cout << "=======================================================================================================================" << endl;
    cout << " ';' : FINALIZACAO DE UMA OPERACAO." << endl;
    cout << " 'q' : SAIR DO PROGRAMA." << endl;
    cout << " '(' : DAR PRIORIDADE A UMA OPERACAO, utilize ')'para fechar esse termo." << endl;
    cout << " '{' : DAR PRIORIDADE A UMA OPERACAO QUE JA TENHA '(', utilize '}'para fechar esse termo." << endl;
    cout << " '+' : SOMAR VALORES." << endl;
    cout << " '-' : SUBTRAIR VALORES." << endl;
    cout << " '*' : MULTIPLICAR VALORES." << endl;
    cout << " '/' : DIVIDIR VALORES." << endl;
    cout << " '%' : CALCULA O RESTO DA DIVISAO EX: 10%3=1, visto que o resto dessa divisao eh 1" << endl;
    cout << " '!' : CALCULAR FATORIAL DE UM NUMERO." << endl;
    cout << " '^' : CALCULAR X ELEVADO A Y, note que caso voce escreva x^(1+1), o programa fara X^2" << endl << "e se voce inserir x^1+1 ocorrera: (X^1)+1" << endl;
    cout << " 'r' : CALCULAR UMA DETERMINADA RAIZ, ex: XrY, isso significa raiz de y no indice x," << endl << "ex: 2r4 vai ser igual a 2, visto que raiz de 4 no indice 2 =2" << endl;

    cout << "=======================================================================================================================" << endl << endl << "VARIAVEIS DEFINIDAS:" << endl;

    for (int i = 0; i < var_table.size(); ++i) {

        cout << " " << var_table[i].name << "= " << var_table[i].value << endl;
    }

    cout << "\n\nDIGITE ';' PARA FINALIZAR." << endl;
}
