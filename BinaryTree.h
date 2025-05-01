// Lauren White - Lab 7

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <vector>
#include "Node.h"

using namespace std;

class BinaryTree
{
private:
    Node* root;

    //Helper function to insert a character into a tree
    void insertHelper(Node*& node, const int& character);

    //Helper function to delete a character from a tree
    Node* deleteHelper(Node* node, const int& character);

    //Helper function to searching for a character in a tree
    bool searchHelper(Node* node, const int& character) const;

    //Helper function to destroy a tree
    void destroyTree(Node* node);

public:
    //Constructor
    BinaryTree() : root(0) {}

    //Method to get the root node
    Node* getRoot() const { return root; }

    //Method to insert a character into a binary tree
    void insert(int character) { insertHelper(root, character); }

    //Method to delete a character from a binary tree
    void deleteCharacter(const int& character) { root = deleteHelper(root, character); }

    //Method to search for a character in a binary tree
    bool search(const int& character) const { return searchHelper(root, character); }

    //Destructor
    ~BinaryTree() { destroyTree(root); }
};

#endif
