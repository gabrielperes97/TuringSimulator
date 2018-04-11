#include "State.hpp"
#include <sstream>
#include <iostream>
Event::Event(int target, char acc, char sub, char dir):
_target(target)
{
    _acc = acc;
    _sub = sub;
    _dir = dir;
}

int Event::execute(Input *input)
{
    input->replace(_sub);
    input->move(_dir);
    return _target;
}

string Event::toString()
{
    stringstream ss;
    ss << _acc << ", " << _target << ", " << _sub << ", " << _dir;
    return ss.str();
}