#include "huffman.h";

using namespace std;
Huffman::Huffman()
{
    heap = new priority_queue<Node*, vector<Node*> NodeCompare>();
}

Huffman::~Huffman()
{
    delete heap;
}

void printCodes(struct MNode* root, string str)
{
 
    if (!root)
        return;
 
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
 
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

Node* Huffman::constructTree()
{
    unordered_map<char, int>::iterator it = freq.begin();

    while(it != freq.end())
    {
        Node* node = new Node(it->first, it->second);
        heap.push(node);
        it++;
    }

    struct Node* left, right;

    while(heap.size() != 1)
    {
        left = heap.top();
        heap.pop();

        right = heap.top();
        heap.pop();

        heap.push(new Node('\0',left->freq + right->freq, right, left))
    }

    return heap.top();
}

Huffman::compress(ifstream& inFile)
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
    Node* top = constructTree(unordered_map<char, int> freq);
    printCodes(heap.top(), "");
}