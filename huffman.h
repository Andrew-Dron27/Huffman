#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <fstream>
#include <queue>
#include <unordered_map>
#include "Node.h"
using namespace std;

class Huffman
{
    private:

    vector<unsigned char> Huffman::readFile(ifstream& inFile);

    Node* constructTree();

    void encodeTree();

    Node* root;
    priority_queue<Node*, vector<Node*>, NodeCompare>* heap;

    void compressData(ofstream& outFile, unordered_map<string, Node*> symbols, vector<string>* symbolList );

    void decompressData( Node* root, vector<char> bits, ifstream& inFile);

    unordered_map<string, Node*> readFileHeader (vector<unsigned char> fileBytes);

    vector<char> read_file(ifstream& inFile);

    unordered_map<string, Node*>* computeMostCommonWords( vector<unsigned char> buffer, int count );

    unordered_map<string, Node*>*
	computeRemainingSymbols( vector<unsigned char> buffer, 
	                                            unordered_map<string, Node*>* wordSymbols,
	                                            vector<string> *symbolList);

    vector<string> convertBitstreamToSymbol( vector<unsigned char> bitStream, Node* root );

    unsigned char* buildFileHeader( unordered_map<string, Node*> *symbols);

    void writeData( ofstream& outfile, vector<string> symbolList );

    unsigned char* buildCompressedBitStream( vector<string> *symbolList, unordered_map<string, Node*> *table );

    Node* createTree( unordered_map<string, Node*> *symbolMap);
    
    static vector<int> determineBitPatternSymbol( Node* leaf );

    public:
    string eof = "EOF";
    int wordCount = 500;

    Huffman();
    Huffman(const Huffman& other);
    Huffman& operator=(Huffman other);
    ~Huffman();
    void compress(ifstream& inFile, ofstream& outFile);
    void decompress(string filePath, string outFile);
};


#endif