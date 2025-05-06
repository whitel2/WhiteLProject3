// Lauren White - Lab 7

#include "Node.h"
#include "PriorityQueue.h"

//Insert a node based on frequency
void PriorityQueue::push(Node* newNode)
{
    PQNode* newPQNode = new PQNode(newNode);
    PQNode* temp;

    // If the queue is empty or the new node has a lower frequency than head
    if (!head || newNode->frequency < head->data->frequency) 
    {
        //Add the new node to the front of the priority queue
        newPQNode->next = head;
        head = newPQNode;
    }

    //Otherwise, find the correct position for the new node
    else 
    {
        temp = head;

        //While the new node has a higher frequency than the current node
        while (temp->next && temp->next->data->frequency <= newNode->frequency) 
        {
            //Move to the next node
            temp = temp->next;
        }

        //Put the new node in the correct position
        newPQNode->next = temp->next;
        temp->next = newPQNode;
    }
}

//Remove and return the node with the lowest frequency
Node* PriorityQueue::pop()
{
    if (!head) return nullptr;
    PQNode* temp = head;
    head = head->next;
    Node* nodeData = temp->data;
    delete temp;
    return nodeData;
}

//Destructor
PriorityQueue::~PriorityQueue()
{
    while (!isEmpty())
    {
        pop();
    }
}