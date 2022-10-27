#include "huffman.h";

using namespace std;
Huffman::Huffman(ifstream inFile)
{
    
    unordered_map<char, int> freq;
    while (inFile >> noskipws >> ch) 
    {
        if(freq.count(ch))//this is super slow
        {
            freq[ch] = 0;
        }
        freq[ch]++;
    }
}

Huffman::compress()
{

}