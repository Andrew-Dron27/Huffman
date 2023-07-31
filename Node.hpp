#ifndef NODE_H
#define NODE_H
using namespace std;

class Node {
 
    public:
    // One of the input characters
    string symbol;
 
    // Frequency of the character
    int frequency;
 
    // Left and right child of this node
    struct Node *left, *right, *parent;

    bool isleaf()
    {
        return left == nullptr && right == nullptr;
    }

    string getSymbol( string code );

    Node* getLeftMostChild();

    string creatDOT();

    string dotHelper();

    Node(string symbol, int frequency)
    {
 
        left = right = nullptr;
        this->symbol = symbol;
        this->frequency = frequency;
    }

    Node(string symbol, Node* _right, Node* _left)
    {
 
        left = right = nullptr;
        this->symbol = symbol;
        this->frequency = frequency;
        this->right = _right;
        this->left = _left;
        left->parent = this;
        right->parent = this;
    }
};

class NodeCompare {
    public:
    bool operator()(const Node& o1, const Node& o2)
    {
        return o1.frequency < o2.frequency;
    }
};

#endif