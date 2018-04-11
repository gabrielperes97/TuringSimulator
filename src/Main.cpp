#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "TuringMachine.hpp"

using namespace std;

const string APP_NAME("TuringSimulator");
void menu();

int main (int argc, char const *argv[])
{
    bool hasInput = false;
    string input;

    bool hasOutput = false;
    string output;

	bool showInstantDescription = false;

    for (int i=0; i<argc; i++)
    {
        if (strcmp(argv[i], "-in")==0)
        {
            hasInput = true;
            i++;
            if (argv[i][0] != '-')
				input = string(argv[i]);
			else
			{
				cout << "Error: Input file not found" << endl;
				menu();
				return 4;
			}
        }
        else if (strcmp(argv[i], "-out")==0)
        {
            hasOutput = true;
            i++;
            if (argv[i][0] != '-')
				output = string(argv[i]);
			else
			{
				cout << "Error: Output file not found" << endl;
				menu();
				return 4;
			}
        }
		else if (strcmp(argv[i], "-show") == 0)
		{
			showInstantDescription = true;
		}
    }

    if (hasInput == false)
	{
		cout << "Error: input file not found" << endl;
				menu();
		return 1;
	}

	Load loaded = TuringMachine::load(input);
	ofstream out;

	//cout << loaded._machine->toString() << endl;


	if (hasOutput)
		out = ofstream(output);

	while (!loaded._inputs.empty())
	{
		if (loaded._machine.execute(loaded._inputs.front(), showInstantDescription))
		{
			cout << "aceita" << endl;
			if (hasOutput)
				out << "aceita" << endl;
		}
		else
		{
			cout << "rejeita" << endl;
			if (hasOutput)
				out << "rejeita" << endl;
		}
		loaded._inputs.pop();
	}
	return 0;
}


void menu()
{
	cout << "USAGE ./" << APP_NAME << " [REQUIRED PARAMETERS] [OPTIONAL PARAMETERS]" << endl;

	cout << endl;
	cout << "  " << "[REQUIRED PARAMETERS]" << endl;
	cout << "  " << "-in $inputFile" <<  "	" << "Load the input with the patterns to be recognized" << endl;

	cout << endl;
	cout << "  " << "[OPTIONAL PARAMETERS]" << endl;
	cout << "  " << "-out $outputFile" << "    " << "Save the output to the file" << endl; 
	cout << "  " << "-show" << "	" << "Shows the instant description" << endl;
}