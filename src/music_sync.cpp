#include <iostream>
// #include <string>
// #include <regex>
#include <getopt.h>
#include "main.hpp"
#include "music_sync.hpp"

// using namespace std;

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
    const std::filesystem::path sandbox{"~/Music"};
    std::filesystem::create_directories(sandbox/"dir1"/"dir2");
    // std::ofstream{sandbox/"file1.txt"};
    // std::ofstream{sandbox/"file2.txt"};
 
    // std::cout << "directory_iterator:\n";
    // // Iterate over the `std::filesystem::directory_entry` elements
    // for (auto const& dir_entry : std::filesystem::directory_iterator{sandbox}) 
    // {
    //     std::cout << dir_entry << '\n';
    // }

    // std::cout << "\nagain:\n";

    // // Same, but spelling out the type of dir_entry
    for (const std::filesystem::directory_entry& dir_entry : 
        std::filesystem::directory_iterator{sandbox}) 
    {
        std::cout << dir_entry << '\n';
    } 
    std::cout << "\nrecursive_directory_iterator:\n";
    for (auto const& dir_entry : std::filesystem::recursive_directory_iterator{sandbox}) 
    {
        std::cout << dir_entry << '\n';
    }
 
    // delete the sandbox dir and all contents within it, including subdirs
    std::filesystem::remove_all(sandbox);

	return 0;
}
