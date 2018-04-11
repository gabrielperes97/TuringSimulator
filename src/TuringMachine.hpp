// Descreve a máquina por completa, comseu alfabeto, Estados, forma de processar e tudo mais

#include "State.hpp"
#include <string>
#include <queue>
#include <map>
//#include "Input.hpp"
//#include "Load.hpp"
class Load;

using namespace std;

class TuringMachine
{
    //Estado inicial
    int _start;

    //Lista de estados
    map<int, State> _states;

    //alfabeto extendido
    string _syms;

    //Simbolos terminais
    string _terminalSyms;

    private:
        //Só a função load pode carregar a TuringMachine
        TuringMachine();

    public:

        //Dado um arquivo de entrada, carrega a máquina e suas cadeias
        static Load load(string path);

        //Retorna se foi aceito ou não
        bool execute(Input input, bool enableInstantDescription);

        string toString();

};

//Uma classe só para guardar um conjunto de Máquina + cadeias à serem executadas
class Load
{
    public:
    Load(TuringMachine machine, queue<Input> inputs);
    TuringMachine _machine;
    queue<Input> _inputs;
};
