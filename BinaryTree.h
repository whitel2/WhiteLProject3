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

    //Helper function to insert a number into a tree
    void insertHelper(Node*& node, const int& number);

    //Helper function to delete a number from a tree
    Node* deleteHelper(Node* node, const int& number);

    //Helper function to searching for a number in a tree
    bool searchHelper(Node* node, const int& number) const;

    //Helper function to destroy a tree
    void destroyTree(Node* node);

public:
    //Constructor
    BinaryTree() : root(0) {}

    //Method to get the root node
    Node* getRoot() const { return root; }

    //Method to insert a number into a binary tree
    void insert(int number) { insertHelper(root, number); }

    //Method to delete a number from a binary tree
    void deletenumber(const int& number) { root = deleteHelper(root, number); }

    //Method to search for a number in a binary tree
    bool search(const int& number) const { return searchHelper(root, number); }

    //Destructor
    ~BinaryTree() { destroyTree(root); }
};

#endif