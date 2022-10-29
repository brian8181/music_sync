#include <iostream>
#include <string>
#include <fstream>
#include <getopt.h>
#include "main.hpp"
#include "music_sync.hpp"
#include <fstream>
#include <iostream>
#include <filesystem>

using namespace std;

 
int parse_options(int argc, char* argv[])
{
    if(argc < 4)
        return -1;
        
    string music_lib_path = "/home/brian/Music";
    const std::filesystem::path sandbox{music_lib_path};
    for (auto const& dir_entry : std::filesystem::recursive_directory_iterator{sandbox}) 
    {
        std::cout << dir_entry << '\n';
    }
    
    string sync_file_path = "tmp.txt";
    ofstream file;
    file.open(sync_file_path);
    cout << "writing to file \"../" << sync_file_path << "\"";

    for(int i = 1; i < argc; i++)
    {
        cout << argv[i] << endl;
        file << argv[i]  << endl;
    }
    
    file.close();

	return 0;
}
