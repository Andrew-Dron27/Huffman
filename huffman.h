#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <fstream>

class Huffman
{
    private:
    void constructTree();
    void encodeTree();
    class Node 
    {
        public:
        int freq;
        char character;
        Node* left;
        Node* right;
        Node(int _freq = 0, char _character = '\0', Node* _left = nullptr, Node* _right = nullptr)
        {
            freq = freq;
            character = _character;
            left = _left;
            right = _right;
        }
    };

    public:
    Huffman(std::ifstream file);
    void compress();
};
#endif