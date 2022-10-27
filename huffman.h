#ifndef HUFFMAN_H
#define HUFFMAN_H

class Huffman
{
    private:
    void constructTree();
    void encodeTree();

    public:
    Huffman(ifstream file);
    void compress();
}
#endif