// Lauren White - Lab 7

#include "BinaryTree.h"

//Helper function to insert a character into a tree
void BinaryTree::insertHelper(Node*& node, const int& character)
{
    //If there is no node for this character, create a new one
    if (!node)
    {
        node = new Node(character);
    }

    //Create a character node to the left
    else if (character < node->character)
    {
        insertHelper(node->left, character);
    }

    //Create a character node to the right
    else if (character > node->character)
    {
        insertHelper(node->right, character);
    }

    //If the character node already exists, increment the count
    else
    {
        node->increment();
    }
}

//Helper function to delete a character from a tree
Node* BinaryTree::deleteHelper(Node* node, const int& character)
{
    //If there are no nodes
    if (!node)
    {
        //Exit the function and return nullptr
        return nullptr;
    }

    //Delete a character node to the left
    if (character < node->character)
    {
        node->left = deleteHelper(node->left, character);
    }

    //Delete a character node to the right
    else if (character > node->character)
    {
        node->right = deleteHelper(node->right, character);
    }

    //If the character is found
    else
    {
        //If the node is a leaf
        if (!node->left && !node->right)
        {
            //Delete the node and return null
            delete node;
            return nullptr;
        }

        //If there is one child
        else if (!node->left || !node->right)
        {
            //Delete the child
            Node* temp = node->left ? node->left : node->right;
            delete node;
            return temp;
        }

        //If there are two children
        else
        {

            Node* child = node->right;

            //Find the next child (in-order)
            while (child->left)
            {
                child = child->left;
            }

            //Delete the child
            node->character = child->character;
            node->right = deleteHelper(node->right, child->character);
        }
    }
    return node;
}

//Method to search for a character in a binary tree
bool BinaryTree::searchHelper(Node* node, const int& character) const
{
    //If there are no nodes
    if (!node)
    {
        //Exit the function
        return false;
    }

    //If the current node's character matches the target character
    if (character == node->character)
    {
        //Return true
        return true;
    }

    //Search the left subtree
    else if (character < node->character)
    {
        return searchHelper(node->left, character);
    }

    //Search the right subtree
    else return searchHelper(node->right, character);
}

//Helper function to destroy a tree
void BinaryTree::destroyTree(Node* node)
{
    //If there are no nodes
    if (!node)
    {
        //Exit the function
        return;
    }

    //Destroy all the right and left subtrees
    destroyTree(node->left);
    destroyTree(node->right);

    //Destroy the given character node
    delete node;
}
