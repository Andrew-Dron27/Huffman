#include "huffman.h"
#include "ctype.h"
#include <iostream>

using namespace std;
Huffman::Huffman()
{
    heap = new priority_queue<Node*, vector<Node*>, NodeCompare>();
}

Huffman::~Huffman()
{
    delete heap;
}

// Huffman::computeMostCommonWords( vector<unsigned char> buffer, int count )
// {
//     unordered_map<string, Node*> frequency = new unordered_map<string, Node*>();
//     string word = "";

//     for(int i = 0; i < buffer.size(); i++)
//     {
//         if(isalpha(buffer[i]))
//         {
//             word += buffer[i];
//         }
//     }
// }

// void printCodes(Node* root, string str)
// {
 
//     if (!root)
//         return;
 
//     if (root->symbol != '$')
//         cout << root->symbol << ": " << str << "\n";
 
//     printCodes(root->left, str + "0");
//     printCodes(root->right, str + "1");
// }

Node* Huffman::constructTree()
{
    // unordered_map<char, int>::iterator it = freq.begin();

    // while(it != freq.end())
    // {
    //     Node* node = new Node(it->first, it->second);
    //     heap->push(node);
    //     it++;
    // }

    // Node *left, *right;

    // while(heap->size() != 1)
    // {
    //     left = heap->top();
    //     heap->pop();

    //     right = heap->top();
    //     heap->pop();

    //     heap->push(new Node('\0',left->frequency + right->frequency, right, left))
    // }

    // return heap->top();
    return nullptr;
}

void Huffman::compress(ifstream& inFile, ofstream& outFile)
{
    // unordered_map<char, int> freq;
    // char ch;
    // while (inFile >> noskipws >> ch) 
    // {
    //     if(freq.count(ch))//this is super slow
    //     {
    //         freq[ch] = 0;
    //     }
    //     freq[ch]++;
    // }
    // Node* top = constructTree(unordered_map<char, int> freq);
    // printCodes(heap->top(), "");
}