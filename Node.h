//Lauren White - Lab 7

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Node
{
public:

    //Node data and pointers
    int frequency;
    int character;
    Node* left;
    Node* right;

    //Constructor
    Node(int val) : frequency(0), character(val), left(nullptr), right(nullptr) {}

    //Get the character
    int getCharacter() const { return character; }

    //Set the character
    void setCharacter(const int& num) { character = num; }

    //Increment the frequency
    void increment() { frequency++; }

    //Destructor
    ~Node() {}
};

#endif
