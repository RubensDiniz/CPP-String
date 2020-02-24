#include <iostream>
#include "String.hpp"

using namespace std;

int main() {

    String* a = new String();
    cout << "Construtor vazio (a): " << *a << endl;

    String* b = new String('b');
    cout << "Construtor com 1 caractere (b = 'b'): " <<  *b << endl;

    String* c = new String("cpp");
    cout << "Construtor com varios caracteres (c): " << *c << endl;

    cout << endl;

    *b = c;
    cout << "Atribuicao de cadeias (b = c): " <<  *b << endl;
    *b = "c#";
    cout << "Atribuicao de cadeias (b = \"c#\"): " <<  *b << endl;
    *b = 'c';
    cout << "Atribuicao de cadeias (b = \'c\'): "  <<  *b << endl;

    b = *b + *c;
    cout << "Concatenacao (b = b + c): " <<  *b << endl;
    b = *b + "kotlin";
    cout << "Concatenacao (b = b + \"kotlin\"): " <<  *b << endl;
    b = *b + 'd';
    cout << "Concatenacao (b = b + 'd'): " <<  *b << endl;

    *c += *b;
    cout << "Atribuicao da concatenacao (c += b): " << *c << endl;
    *c += "swift";
    cout << "Atribuicao da concatenacao (c += \"swift\"): " << *c << endl;
    *c += 'x';
    cout << "Atribuicao da concatenacao (c += \'x\'): " << *c << endl;

    cout << "Comprimento da cadeia (c->length()): " <<  c->length() << endl;

    cout << "Indice de 'p' em c: " << c->index('p') << endl;

    cout << endl;

    c = c->upcase(0, 2);
    cout << "Upcase de c de 0 ate 2: " << *c << endl;

    c = c->lowercase(0, 1);
    cout << "Lowercase de c de 0 ate 1: " <<  *c << endl;

    c = c->toggle_case(0, 2);
    cout << "Toggle_case de c de 0 ate 2: " <<  *c << endl;

    char z = (*c)[1];
    cout << "2o ([1]) caractere de c: " <<   z << endl;
    cout << endl;

    *b = "cpp";
    String *d = new String("cpp");
    cout << "b = " << *b << endl;
    cout << "d = " << *d << endl;

    cout << "Igualdade (b == d): " << (*b == *d) << endl;
    cout << "Igualdade (b == \"cppx\"): " << (*b == "cppx") << endl;
    cout << "Desigualdade (b != d): " << (*b !=*d) << endl;
    cout << "Comparacao (b > d): " << (*b > *d) << endl;
    cout << "Comparacao (b > \"asdf\"): " << (*b > "asdf") << endl;
    cout << "Comparacao (b > \'a\'): " << (*b > 'a') << endl;
    cout << "Comparacao (b < d): " << (*b < *d) << endl;
    cout << "Comparacao (b <  \"asdf\"): " << (*b < "asdf") << endl;
    cout << "Comparacao (b < \'a\'): " << (*b < 'a') << endl;
    cout << "Comparacao (b >= d): " << (*b >= *d) << endl;
    cout << "Comparacao (b >= \"asdf\"): " << (*b >= "asdf") << endl;
    cout << "Comparacao (b >= \'a\'): " << (*b >= 'a') << endl;
    cout << "Comparacao (b <= d): " << (*b <= *d) << endl;
    cout << "Comparacao (b <= \"asdf\"): " << (*b <= "asdf") << endl;
    cout << "Comparacao (b <= \'a\'): " << (*b <= 'a') << endl;
    cout << endl;

    cout << "Digite um novo valor para a: ";
    cin >> *a;
    cout << "a = " << *a << endl;

    return 0;
}
