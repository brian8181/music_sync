#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

list<string> get_lines(string path);

int parse_options(int argc, char* argv[])
{

    list<string> updates = get_lines(argv[1]);
    list<string> master = get_lines(argv[2]);
 
    list<string>::iterator end = updates.end();
    //list<string>::iterator beg = updates.begin();
    for(list<string>::iterator iter; iter != end; ++iter)
    {
        //list<string> find_iter = std::find(master.begin(), master.end(), *iter);
    }

    return 0;
}

list<string> get_lines(string path)
{
    list<string> lines;
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
    return lines;
}