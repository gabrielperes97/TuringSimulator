#include "State.hpp"
#include <iostream>


State::State(int index):
_index(index), _events(map<char, Event>()), _start(false), _final(false)
{
    _name = "q"+to_string(index);
}

list<int> State::executeEvent(Input *input)
{
    list<int> states = list <int>();

    if (_events.count(input->getAtualSym()) > 0)
    {
        states.push_back(_events.at(input->getAtualSym()).execute(input));
    }

    return states;
}

string State::toString()
{
    string s = "";
    s += "State " + _name + ": ";
    if (_start)
        s += "start ";
    if (_final)
        s += "final ";
    s += "\n";
    for (map<char,Event>::iterator it=_events.begin(); it!=_events.end(); ++it)
    {
        s += "  " + it->second.toString() + "\n";
    }
    return s;
}