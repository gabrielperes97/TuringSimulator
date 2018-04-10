//Especifica a cadeia de entrada e suas ações
#include "string"
using namespace std;
class Input
{
    //Posição atual da cadeia
    //Deve começar na 1
    int _pos;

    //Cadeia propriamente dita
    //Deve ser iniciada com B(branco) nas extremidades
    char _input[];

    public:
        Input();
        Input(string input);
        char getAtualSym();
        char move(char direction);
};