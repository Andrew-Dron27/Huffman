#include "huffman.h"
#include "ctype.h"
#include <iostream>
#include <algorithm>
#include <bitset>
#include <memory>

using namespace std;
Huffman::Huffman()
{
    heap = new priority_queue<Node*, vector<Node*>, NodeCompare>();
}

Huffman::~Huffman()
{
    delete heap;
}

void Huffman::compress(ifstream& inFile, ofstream& outFile)
{
    vector<string>* orderedSymbols = new vector<string>();

    vector<unsigned char> buffer = readFile(inFile);

    unordered_map<string, Node*>* mostCommonWords = computeMostCommonWords(buffer, wordCount);

    unordered_map<string, Node*>* symbolMap = computeRemainingSymbols(buffer, mostCommonWords, orderedSymbols);

    // Makes the huffman tree from the ordered symbols
    createTree(symbolMap);

    // Compresses the data and outputs the compressed data into a binary file
    compressData( outFile, all_symbols, orderedSymbols );

    delete orderedSymbols;
    delete symbolMap;
}

vector<unsigned char> Huffman::readFile(ifstream& inFile)
{
    unsigned char ch;
    vector<unsigned char> characters;
    while(inFile >> noskipws >> ch)
    {
        characters.push_back(ch);
    }
    return characters;
}

bool cmp(const Node &a, const Node &b)
{
    //sort in descending order
    return a.frequency > b.frequency;
}

void increment(unordered_map<string, Node*>* symbols, string symbol)
{
    if(symbols->count(symbol) == 1)
    {
        symbols->at(symbol)->frequency++;
    }
    else
    {
        (*symbols)[symbol] = new Node(symbol,1);
    }
}

unordered_map<string, Node*>* Huffman::computeMostCommonWords( vector<unsigned char> buffer, int count )
{   
    //count how many times each 'word' appears in the file
    unordered_map<string, Node*> *wordsMap = new unordered_map<string, Node*>();
    string word = "";

    if(wordCount >= 1)
    {
        for(int i = 0; i < buffer.size(); i++)
        {
            if(isalpha(buffer[i]))
            {
                word += buffer[i];
            }
            else {
                increment(wordsMap, word);
            }
        }
    }

    vector<std::pair<string, Node*>> elems(wordsMap->begin(), wordsMap->end());
    sort(elems.begin(), elems.end(), cmp);

    wordsMap->clear();

    for(int i = 0; i < wordCount; i++)
    {
        (*wordsMap)[elems[i].first] = elems[i].second;
    }
    
    return wordsMap;
}

unordered_map<string, Node*>* Huffman::computeRemainingSymbols( vector<unsigned char> buffer, 
	                                            unordered_map<string, Node*> *wordSymbols,
	                                            vector<string>* symbolList)
{
    //unordered_map<string, Node*>* allSymbols = new unordered_map<string, Node*>();
    string symbol = "";
    for(int i = 0; i < buffer.size(); i++)
    {
        if(isalpha(buffer[i]))
        {
            symbol += buffer[i];
        }
        else {
            if(symbol.length() > 0)
            {
                //check if already a top word
                if(wordSymbols->count(symbol) != 1)
                {
                    //add indiviudal chars to map
                    for(char c : symbol)
                    {
                        increment(wordSymbols, "" + c);
                        symbolList->push_back("" + c);
                    }
                }
                else
                {
                    symbolList->push_back(symbol);
                }
                
            }
            symbol = "";
        }
    }

    (*wordSymbols)[eof] = new Node(eof,1);
    symbolList->push_back(eof);
    return wordSymbols;
}

Node* Huffman::createTree(unordered_map<string, Node*> *symbolMap)
{
    
    unordered_map<string, Node*>::iterator it = symbolMap->begin();

    while(it != symbolMap->end())
    {
        heap->push(it->second);
        it++;
    }

    Node *left, *right;

    int nodeId = 1;

    while(heap->size() > 1)
    {
        left = heap->top();
        heap->pop();

        right = heap->top();
        heap->pop();

        heap->push(new Node("NODE_" + nodeId, left, right));
    }

    return heap->top();
}

void Huffman::compressData(ofstream& outFile, unordered_map<string, Node*> *symbols, vector<string>* symbolList )
{
    try
    {
        unique_ptr<vector<bool>>  fileHeader = buildFileHeader(symbols);
        unique_ptr<vector<bool>>  bitStream = buildCompressedBitStream(symbolList, symbols);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

unique_ptr<vector<bool>>  Huffman::buildFileHeader( unordered_map<string, Node*> *huffmanNodes )
{
    unordered_map<string, Node*>::iterator it = huffmanNodes->begin();
    Node* currNode;
    vector<bool> lengthBytes, charBytes, freqBytes;
    while(it != huffmanNodes->end())
    {
        currNode = it->second;

        lengthBytes = Bit_Operations.convert_integer_to_bytes(currNode->symbol.size());
			
        for(char character : currNode->symbol)
        {
            out.write(character);
        }

        out.write(Bit_Operations.convert_integer_to_bytes(currNode->freq));
        
        it++;
    }
}

unique_ptr<vector<bool>> buildCompressedBitStream( vector<string> *symbolList, unordered_map<string, Node*> *table )
{
    string word;
    Node* node;
    vector<bool> bitPattern;
    unique_ptr<vector<bool>> bitStream(new vector<bool>());

    for(string symbol : *symbolList)
    {
        node = (*table)[symbol];
        bitPattern = getSymbolBitPattern(node);
        bitStream->insert(bitStream->end(), bitPattern.begin(), bitPattern.end());
    }

    return bitStream;
}

vector<bool> getSymbolBitPattern( Node* leaf )
{
    vector<bool> bitPattern;
    while(leaf->parent != nullptr)
    {
			// Left we add zero
			if(leaf->parent->left == leaf)
				bitPattern.push_back(0);
			// Right we add 1
			else
				bitPattern.push_back(1);
			// Moving up
			leaf = leaf->parent;
		}
		// The linkedlist of pattern
		return bitPattern;
    }
}