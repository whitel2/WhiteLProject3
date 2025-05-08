// Lauren White - Lab 7

#include "BinaryTree.h"

//Method to build a Huffman tree with a priority queue
void BinaryTree::buildTree(PriorityQueue& pq) 
{
    Node* parent;

    //If there is no data in the priority queue
    if (pq.isEmpty())
    {
        root = nullptr;
        return;
    }

    //While there is data in the priority queue
    while (!pq.isEmpty()) 
    {
        Node* left = pq.pop();
        Node* right = pq.pop();

        //If there is no data to the right
        if (!right) 
        {
            //The root is the node to the left
            root = left;
            break;
        }

        //Build the tree from the bottom up by adding the frequencies together
        parent = new Node('$');
        parent->frequency = left->frequency + right->frequency;
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
}

//Helper to generate the Huffman code for a character
void BinaryTree::generateCodesHelper(Node* node, string code) 
{
    //If there are no nodes, exit the function
    if (!node)
    {
        return;
    }

    //If the node is a leaf
    if (!node->left && !node->right) 
    {
        //Add the character and its code
        codes[node->character].character = node->character;
        codes[node->character].code = code;
    }

    //Move to the left or right child
    generateCodesHelper(node->left, code + "0");
    generateCodesHelper(node->right, code + "1");
}

//Decode an encoded message
string BinaryTree::decodeMessage(const string& encodedMessage) 
{
    string decodedMessage = "";
    Node* current = root;

    //For each bit in the encoded message
    for (char bit : encodedMessage) 
    {
        //Suggestesd by Copilot to remove an error
        if (!current)
        {
            return decodedMessage;
        }

        //Move to the next node based on the current bit (suggested by Copilot)
        current = (bit == '0') ? current->left : current->right;

        //Suggestesd by Copilot to remove an error
        if (!current)
        {
            return decodedMessage;
        }

        //If a leaf node is found
        if (!current->left && !current->right) 
        {
            //Add the current character to the decoded string
            decodedMessage += current->character;
            current = root;
        }
    }

    return decodedMessage;
}