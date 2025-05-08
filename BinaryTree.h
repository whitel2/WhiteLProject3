// Lauren White - Lab 7

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"
#include "PriorityQueue.h"

struct HuffmanCode 
{
    char character;
    string code;

    //Default constructor
    HuffmanCode() : character('\0'), code("") {}
};

class BinaryTree 
{
private:
    Node* root;
    HuffmanCode codes[256];

    //Helper to generate the Huffman code for a character
    void generateCodesHelper(Node* node, string code);

public:

    //Constructor
    BinaryTree() : root(nullptr) {}

    //Method to build a Huffman tree
    void buildTree(PriorityQueue& pq);

    //Method to generate the Huffman code for a character
    void generateCodes() { generateCodesHelper(root, ""); }

    //Method to get the ASCII code for a character
    string getCharacterCode(char c) const { return codes[c].code; }

    //Method to decode a Huffman coded string
    string decodeMessage(const string& encodedMessage);

    //Method to get the root of a Huffman tree
    Node* getRoot() const { return root; }

    //Destructor
    ~BinaryTree() { root; }
};

#endif
