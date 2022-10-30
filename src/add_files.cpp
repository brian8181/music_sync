#include <iostream>
#include <string>
#include <getopt.h>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <list>
#include <iostream>
#include <sstream>
#include <array>
#include "add_files.hpp"

using namespace std;

// constants
const int DEFAULT_ARGC = 2;
const string VERSION_STRING = "music_sync 0.1";

// options flags
const unsigned char VERBOSE          = 0x01;
const unsigned char DEFAULTS = 0;
unsigned char OPTION_FLAGS = DEFAULTS;

static struct option long_options[] =
{
	{"verbose", no_argument, 0, 'v'},
	{"help", no_argument, 0, 'h'},
	{"version", no_argument, 0, 'r'}
};

void print_version()
{
	cout << VERSION_STRING << endl;
}

void print_help()
{
	cout << "Usage: "  
	<< endl;
}

void scan_files(string path);

int parse_options(int argc, char* argv[])
{
    // if(argc < 2)
    //     return -1;


    // todo! working on getting lines from ifstream
    list<std::array<char, 256>> add_lines;
    list<string> complied_lines;
    string compiled_file = argv[2];
    
    ifstream add_file;
    add_file.open(argv[1]);
    for(std::array<char, 256> buffer; add_file.getline(&buffer[0], 256, '\n'); )
    {
        add_lines.push_back(buffer);
    }
    // end todo
        
    string music_lib_path = "/home/brian/Music";
    const std::filesystem::path sandbox{music_lib_path};
    for (auto const& dir_entry : std::filesystem::recursive_directory_iterator{sandbox}) 
    {
        std::cout << dir_entry << '\n';
    }


    string sync_file_path = "tmp.txt";
    ofstream file;
    file.open(sync_file_path);
    cout << "writing to file ..." << sync_file_path;

    for(int i = 1; i < argc; i++)
    {
        cout << argv[i] << endl;
        file << argv[i]  << endl;
    }
    
    file.close();

    int opt = 0;
	int option_index = 0;
	optind = 0;
	while ((opt = getopt_long(argc, argv, "hvispPreEo:x:f:", long_options, &option_index)) != -1)
	{
		switch (opt)
		{
		case 'h':
			print_help();
			return 0;
		case 'v':
			OPTION_FLAGS |= VERBOSE;
			break;
        default:
            scan_files(".");
        }
    }

	return 0;
}

void scan_files(string path)
{

}
