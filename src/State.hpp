// Descreve um estado, basicamente
#include <list>

using namespace std;

class State
{
    //Nome do estado
    string name;

    //Lista de eventos
    list<Event> _events;

    //Estado inicial?
    bool _start;

    //Estado final?
    bool _final;

    public:
        //Executa o estado pesquisando entre seus eventos
        //Retorna uma lista de estados para o caso de um máquina não determinística
            //Não foi especificado, mas...
        list<State *> executeEvent(char sym);

}