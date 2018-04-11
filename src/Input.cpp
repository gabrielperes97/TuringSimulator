#include "Input.hpp"
#include <iostream>

Input::Input(string input)
{
    _input = "B";
    _input += input;
    _input += "B";
    _pos = 1;
}

char Input::getAtualSym()
{
    return _input[_pos];
}

char Input::move(char direction)
{
    switch (direction)
    {
        case 'L':
            if (_pos > 0)
                _pos--;
            break;
        case 'R':
            if (_pos < _input.length()-1)
                _pos++;
            break;
    }
    return getAtualSym();
}

void Input::replace(char c)
{
    if (_pos > 0 && _pos < _input.length()-1)
    {
        _input[_pos] = c;
    }
}

string Input::toString()
{
    return _input;
}