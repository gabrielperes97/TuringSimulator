// Descreve a máquina por completa, comseu alfabeto, Estados, forma de processar e tudo mais

#include "State.hpp"
#include <string>
#include <queue>

class TuringMachine
{
    //Estado inicial
    State *_start;

    //Lista de estados
    list<State> _states;

    public:
        TuringMachine(list);
        //Retorna se foi aceito ou não
        virtual bool execute(list<char> input);
}