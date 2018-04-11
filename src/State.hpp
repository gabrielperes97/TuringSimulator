// Descreve um estado, basicamente
#include <list>
#include "Input.hpp"
//#include "Event.hpp"
#include <string>
#include <map>

class Event;

using namespace std;

class State
{
    public:
        //Executa o estado pesquisando entre seus eventos
        //Retorna uma lista de estados para o caso de um máquina não determinística
            //Não foi especificado, mas...
        //Caso a lista for vazia, então morreu lá
        list<int> executeEvent(Input *input);

        //State();
        State(int index);

        string toString();

        //Nome do estado
        string _name;

        //string indice
        int _index;

        //Lista de eventos
        map<char, Event> _events;

        //Estado inicial?
        bool _start;

        //Estado final?
        bool _final;

};




//Descreve um evento realizado possível naquele estado.
//Basicamente uma transição em um estado

//Por que eu não chamei logo de Transition?
//Também não sei...

//Preciso disso por causa da referência cruzada entre um estado ter eventos e um evento ter um estado alvo.
//#include "State.hpp"

using namespace std;

class Event
{
    //Estado alvo
    //Aquele para onde vamos se o evento for disparado
    int _target;

    //Simbolo de aceitação
    //Se o simbolo lido no estado for esse, então dispara o evento
    char _acc;

    //Simbolo de substituição
    //Simbolo o qual o evento substituí na cadeia
    char _sub;

    //Direção da fita após substituíção
    //Apenas 3 opções:
    //L: Esquerda
    //R: Direita
    //S: Parar
    char _dir;

    public:
        Event(int taget, char acc, char sub, char dir);

        //Realiza ação de substituição e movimentação na cadeia para aquela entrada
        int execute(Input *input);

        string toString();
};