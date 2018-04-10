// Descreve a máquina por completa, comseu alfabeto, Estados, forma de processar e tudo mais

#include "State.hpp"
#include <string>
#include <list>
//#include "Load.hpp"
class Load;

using namespace std;

class TuringMachine
{
    //Estado inicial
    State *_start;

    //Lista de estados
    list<State> _states;

    //alfabeto extendido
    list<char> _syms;

    //Simbolos terminais
    list<char> _terminalSyms;

    private:
        //Só a função load pode carregar a TuringMachine
        TuringMachine();

    public:

        //Dado um arquivo de entrada, carrega a máquina e suas cadeias
        static Load load(string path);

        //Retorna se foi aceito ou não
        bool execute(string input);

};

//Uma classe só para guardar um conjunto de Máquina + cadeias à serem executadas
class Load
{
    public:
    TuringMachine machine;
    list<Input> inputs;
};
