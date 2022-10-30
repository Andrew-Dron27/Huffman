#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <fstream>
#include <queue>
#include "Node.h"
using namespace std;

class Huffman
{
    private:
    Node* constructTree();
    void encodeTree();
    Node* root;
    priority_queue<Node*, vector<Node*>, NodeCompare> heap;

    void compress_data(ifstream& inFile, unordered_map<string, Node*> symbols, vector<string> ordered_list_of_symbols );

    void decompress_data( Node* huffman_root, vector<char> bits, ifstream& inFile);

    unordered_map<string, Node*> readFileHeader (vector<unsigned char> file_bytes);

    vector<char> read_file(ifstream& inFile);

    unordered_map<string, Node*> computeMostCommonWords( vector<unsigned char> buffer, int count );
    unordered_map<string, Node*> 

	computeRemainingSymbols( vector<char> buffer, 
	                                            unordered_map<string, Node*> word_symbols,
	                                            vector<string> ordered_list_of_symbols);

    vector<string> convertBitstreamToSymbol( vector<unsigned char> bit_stream, Node* root );

    unsigned char* buildFileHeader( vector<Node*> huffman_nodes );

    void writeData( ofstream& outfile, vector<string> symbol_list );
    unsigned char* buildCompressedBitStream( vector<string> ordered_list_of_symbols, unordered_map<string, Node*> table );

    Node* create_tree( vector<Node*> nodes );
    
    static vector<int> determineBitPatternSymbol( Node* leaf );

    public:
    const string eof = "EOF";
    int wordCount;

    Huffman();
    ~Huffman();
    void compress(ifstream& inFile);
    void decompress(string filePath, string outFile);
};


#endif