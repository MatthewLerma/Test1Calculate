#include "mixed.h"
#include <string>

using namespace std;

void normalizeInput(string input, string &command, string &index, string &expression);
void openInput(string &inName, ifstream &inFile, char *argv[]);
void CommandLine(const char *title, int argc, char *argv[], ifstream &inFile, string &inName);

int main(int argc, char *argv[]) {
    bool again;
    string input, command, index, expression, inName;
    ifstream inFile;



    do
    {
        cout<<"INPUT: ";
        getline(cin, input);
        if (input == "")
        {
            again = false;
        }
        else
        {
            again = true;
            normalizeInput(input, command, index, expression);
            cout << endl << command << endl;
            cout << index << endl;
            cout << expression <<endl;
        }

    } while (again);


    return 0;
}

void normalizeInput(string input, string &command, string &index, string &expression)
{
    unsigned int pos, pos2, pos3;

    cout << input << endl;
    pos = input.find_first_of(' ');
    command = input.substr(0, pos);
    input.erase(0, pos);

    cout << input << endl;
    pos2 = input.find_first_of('=');
    index = input.substr(0, pos2-1);
    input.erase(0, pos);

    cout << input << endl;
    pos = input.find_first_of('=');
    expression = input.substr(pos + 1, string::npos);
}

void CommandLine(const char *title, int argc, char *argv[], ifstream &inFile, string &inName)
{
    if (argc == 1)
    {
        if (argv[0][1] == '/h' || argv[0][1] == '/?')
        {
            cout << "In order to properly utilize the command line, you must put in either "
                 << "1 or 2 arguments" << endl << endl
                 << "If you are inputting 1 argument into the command line, it must contain the "
                 << "filename of the file you wish to load into the program." << endl
                 << "This filename must include the extension of the file as well (e.g. .exp)" << endl << endl
                 << "If you are inputting 2 arguments the first of the two must be either EXECUTE or RECORD" << endl
                 << "followed by the second argument being the previously stated filename in correct format" << endl;
            exit(0);
        }
        else
        {
            openInput(inName, inFile, argv);
        }

    }
    else if (argc == 2)
    {

    }
    else if (argc >= 3)
    {
        cout << "Too many command line arguments, program will now exit.";
        exit(1);
    }

}

void openInput(string &inName, ifstream &inFile, char *argv[])
{
    bool again;
    string temp = inName;
    if (temp.empty())
    {
        cout << "Please enter a filename for input: ";
        cin >> temp;
    }
    inFile.open(temp.c_str());
    if(inFile.fail())
    {
        inFile.close();
        inFile.clear();
        again = true;
        cout<<"That file does not exist for input"<<endl;
    }
    else
    {
        cout << "File opened\n";
    }

}
