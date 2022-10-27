#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char** argv)
{
    std::cout << argv[1] << std::endl;
    ifstream inFile;
    infile.open(argv[1]);
    if (!inFile)
    {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }
    
}