// Lauren White - Lab 7

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "Node.h"

class PriorityQueue 
{
private:
    struct PQNode 
    {
        Node* data;
        PQNode* next;
        PQNode(Node* d) : data(d), next(nullptr) {}
    };

    PQNode* head;

public:

    //Constructor
    PriorityQueue() : head(nullptr) {}

    //Insert a node based on frequency
    void push(Node* newNode);

    //Remove and return the node with the lowest frequency
    Node* pop();

    //Check if the queue is empty
    bool isEmpty() const { return head == nullptr; }

    //Destructor
    ~PriorityQueue();
};

#endif