// Descreve a máquina por completa, comseu alfabeto, Estados, forma de processar e tudo mais

#include "State.hpp"
#include <string>
#include <queue>

using namespace std;

class TuringMachine
{
    //Estado inicial
    State *_start;

    //Lista de estados
    list<State> _states;

    public:
        TuringMachine(list);

        //Dado um arquivo de entrada, carrega a máquina
        static TuringMachine load(string path);

        //Retorna se foi aceito ou não
        bool execute(list<char> input);
}