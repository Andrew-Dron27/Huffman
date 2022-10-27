#include "huffman.h";

using namespace std;
Huffman::Huffman(ifstream inFile)
{
    unordered_map<char, int> freq;
    while (inFile >> noskipws >> ch) 
    {
        if(count(freq[ch]) == 0)
        {
            freq[ch] = 0;
        }
        freq[ch]++;
    }
}

Huffman::compress()
{

}