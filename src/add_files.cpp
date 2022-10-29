#include <iostream>
#include <string>
#include <fstream>
// #include <regex>
#include <getopt.h>
#include "main.hpp"
#include "music_sync.hpp"

using namespace std;

// int parse_options(int argc, char* argv[])
// {
// 	cout << "Hello Template!" << endl;
// 	return 0;
// }

#include <fstream>
#include <iostream>
#include <filesystem>
 
int parse_options(int argc, char* argv[])
{
    const std::filesystem::path sandbox{"/home/brian/Music"};
    for (auto const& dir_entry : std::filesystem::recursive_directory_iterator{sandbox}) 
    {
        std::cout << dir_entry << '\n';
    }
    

    if(argc <  2)
        return -1;

    string sync_list;
    
    for(int i = 1; i < argc; i++)
    {
        sync_list + argv[i] + "/n";
    }
    
    ofstream of;
    

	return 0;
}
