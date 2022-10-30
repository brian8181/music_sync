#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

void get_lines(string path, list<string>& lines);

int parse_options(int argc, char* argv[])
{

    list<string> updates;
    list<string> master;

    string updates_path = argv[1];
    string master_path = argv[2];

    get_lines(updates_path, updates);
    get_lines(master_path, master);

    list<string>::iterator end = updates.end();
    for(list<string>::iterator iter; iter != end; ++iter)
    {
        
    }

    return 0;
}

void get_lines(string path, list<string>& lines)
{
    std::ifstream file(path);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line)) 
        {
            lines.push_back(line);
        }
        file.close();
    }
}



