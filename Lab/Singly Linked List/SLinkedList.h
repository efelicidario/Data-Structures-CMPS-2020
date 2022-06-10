#pragma once
#include "cmpslib19.h"
#include "easylogging++.h"



template <class T>
class SLinkedList
{
    /* 
       We need a node that is templated to store the same type as our 
       Linked List. The easiest way to do this is make it an "Inner" class
       It contains an element of the template type
       and a pointer to the next node in the list.
       */
    class SListNode
    {
        public:
            T data;
            SListNode *next;
            SListNode(T val)
            {
                data = val;
                next = nullptr;
            }
    };

    SListNode * head;

    public:
    SLinkedList()
    {
        LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
        // set head to the nullptr 
        head = nullptr;
        LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    }


    bool Insert(T val)
    {
        LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
        LOG(INFO) << "Parameter " << val << endl;
        // insert a new node to store val 
        // at the head of the list
        if (head == NULL)
            head = new SListNode(val);
        else
        {
            // create a new node to store the value to be added
            SListNode* newNode = new SListNode(val);
            // set the next pointer of the new node to point to the current first node in the list
            newNode->next = head;
            // make this node the new front by setting the head pointer to it
            head = newNode;
            newNode = NULL;
        }
        LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
        LOG(INFO) << "Returning " << "true" << endl;
        return true;
    }

    string ToString()
    {
        LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
        // return a text representation of the stack
        // IT MUST WORK WITH THE WEBPAGE
        // make sure to test your output
        string stack;
        SListNode* temp = head;
        stack += "SList:\nhead: " + NumberToString(head) + "\n";
        while (temp != NULL)
        {
            stack += "node: " + NumberToString(temp) + " data: " + NumberToString(temp->data) + " next: " + NumberToString(temp->next) + "\n";
            temp = temp->next;
        }
        LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
        LOG(INFO) << "Returning " << stack << endl;
        return stack;
    }
}; // end SLinkedList





