#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const string APP_NAME("TuringSimulator");
void menu();

int main (int argc, char const *argv[])
{
    bool hasInput = false;
    string input;

    bool hasOutput = false;
    string output;

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
        else if (strcmp(argv[i], "-in")==0)
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
    }

    if (hasInput == false)
	{
		cout << "Error: input file not found" << endl;
				menu();
		return 1;
	}
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
}