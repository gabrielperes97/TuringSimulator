#include <TuringMachine.hpp>
#include <iostream>
#include <fstream>
#include <regex>

string instantDescription(Input input, State state);

TuringMachine::TuringMachine()
{
    _states = map<int, State>();
}

Load TuringMachine::load(string path)
{
    TuringMachine machine = TuringMachine();
    queue<Input> inputs = queue<Input>();

    ifstream file(path);
    string line;
    if (file.is_open())
    {
        //Primeira linha: Numero de estados
        getline(file, line);
        int nStates = stoi(line);
        for (int i=0; i<6; i++)
        {
            machine._states.insert(pair<int, State>(i, State(i)));
        }
        machine._states.at(0)._start = true;
        machine._start = 0;

        //Segunda linha: Conjunto de simbolos terminais
        getline(file, line);
        //regex reAlphabet("^(\\d)( ).*");
        regex reAlphabet("[0-9]* (.) (.) (.)");
        smatch matches;
        regex_search(line, matches, reAlphabet);
        machine._terminalSyms = "";
        machine._terminalSyms += matches[1];
        machine._terminalSyms += matches[2];
        machine._terminalSyms += matches[3];

        //Terceira linha: Alfabeto não terminal
        getline(file, line);
        reAlphabet = regex("[0-9]* (.) (.) (.) (.)");
        regex_search(line, matches, reAlphabet);
        machine._syms = "";
        machine._syms += matches[1];
        machine._syms += matches[2];
        machine._syms += matches[3];
        machine._syms += matches[4];

        //Quarta linha: Estado de aceitação
        getline(file, line);
        int finalState = stoi(line);
        machine._states.at(finalState)._final = true; 

        //Quinta linha: Numero de transições
        getline(file, line);
        int nEvents = stoi(line);
        
        //Proximas nEvents linhas = Transições(events)
        string alphabet = "";
        for (string::iterator it=machine._terminalSyms.begin(); it != machine._terminalSyms.end(); ++it)
        {
            alphabet += "[";
            alphabet += *it;
            alphabet += "]|";
        }
        for (string::iterator it=machine._syms.begin(); it != machine._syms.end(); ++it)
        {
            alphabet += "[";
            alphabet += *it;
            alphabet += "]|";
        }
        alphabet += "-";
        string re = "(\\d) ("+alphabet+") (\\d) (" +alphabet+ ") (R|L|S)" ;
        regex reEvent(re);
        //cout << "RE: " << re << endl;
        for (int i=0; i<nEvents; i++)
        {
            getline(file, line);
            regex_search(line, matches, reEvent);   
            int iState = stoi(matches[1]);
            char trigger = string(matches[2])[0];
            int iTargetState = stoi(matches[3]);
            char subs = string(matches[4])[0];
            char dir = string(matches[5])[0];
            machine._states.at(iState)._events.insert(pair<char, Event>(trigger, Event(iTargetState, trigger, subs, dir)));
        }

        //nLinhas depois = Quantidade de cadeias iniciais
        getline(file, line);
        int nInputs = stoi(line);

        //nInputs proximas linhas = Cadeias para serem testadas
        for (int i=0; i<nInputs; i++)
        {
            getline(file, line);
            inputs.push(Input(line));
        }
    }
    return Load(machine, inputs);
}

bool TuringMachine::execute(Input input, bool enableInstantDescription)
{
    int actualState = _start;
    list<int> states;
    do
    {
        if (enableInstantDescription)
            cout << instantDescription(input, _states.at(actualState)) << endl;
        states = _states.at(actualState).executeEvent(&input);
        if (states.size() == 0)
        {
            if (_states.at(actualState)._final)
                return true;
            else
                return false;
        }
        actualState = states.front();
    }while(states.size() != 0);
}

string instantDescription(Input input, State state)
{
    string s = input.toString();
    s.insert(input._pos, state._name);
    return s;
}

string TuringMachine::toString()
{
    string s = "";
    s += "Simbolos terminais: " + _terminalSyms + "\n";
    s += "Alfabeto estendido: " + _syms + "\n";
    s += "Estado inicial: " + _states.at(_start)._name + "\n";

    for (map<int,State>::iterator it=_states.begin(); it!=_states.end(); ++it)
    {
        s += it->second.toString();
    }
    return s;
}

Load::Load(TuringMachine machine, queue<Input> inputs):
_machine(machine), _inputs(inputs)
{

}