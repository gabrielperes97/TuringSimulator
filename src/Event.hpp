//Discreve um evento realizado possível naquele estado.
//Basicamente uma transição em um estado

//Por que eu não chamei logo de Transition?
//Também não sei...

//Preciso disso por causa da referência cruzada entre um estado ter eventos e um evento ter um estado alvo.
#include "Input.hpp"

class State;

using namespace std;

class Event
{
    //Estado alvo
    //Aquele para onde vamos se o evento for disparado
    State *_target;

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
        Event(State *taget, char acc, char sub, char dir);

        //Verifica se o estado pode ser disparado
        State * isValid(char sym);

        //Realiza a substituição e movimentação na cadeia
        void execute(Input input);
};