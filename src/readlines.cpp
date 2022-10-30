#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int parse_options(int argc, char* argv[])
{
    string FILENAME = argv[1];
    std::ifstream file(FILENAME);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line)) 
        {
            cout << line << endl;
        }
        file.close();
    }
    return 0;
}


