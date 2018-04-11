//Especifica a cadeia de entrada e suas ações
#include "string"
using namespace std;
class Input
{

    //Cadeia propriamente dita
    //Deve ser iniciada com B(branco) nas extremidades
    string _input;

    public:
        //Posição atual da cadeia
        //Deve começar na 1
        int _pos;

        Input(string input);
        char getAtualSym();
        char move(char direction);
        void replace(char c);
        string toString();
};