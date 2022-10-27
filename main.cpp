#include <iostream>
#include <fstream>
#include <filesystem>
#include "huffman.h"
using namespace std;


int main(int argc, char** argv)
{
    if(argc == 1)
    {
        cerr << "Please enter in a file as second argument";
        exit(1);
    }
    else if(argc > 2)
    {
        cerr << "Too many arguments";
        exit(1);
    }
    string fileName = std::filesystem::current_path().string() + "/Test_Files/" +  argv[1];
    ifstream inFile;
    inFile.open(fileName);
    if (!inFile)
    {
        cerr << "Unable to open file textfile";
        exit(1);   // call system to stop
    }
}
