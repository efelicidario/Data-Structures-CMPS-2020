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


    SListNode* Search(T val)
    {
        LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
        SListNode* newNode = head;
        SListNode* result = nullptr;
        while(newNode != result)
        {
            if(newNode->data == val)
                result = newNode;
            else
            newNode = newNode->next;
        }
        LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
        return result;
    }


    public:
    SLinkedList()
    {
        LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
        // set head to the nullptr 
        LOG(INFO) << "seting head to nullptr" << endl;
        head = nullptr;
        LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    }

    ~SLinkedList()
    {
        LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
        SListNode* nodePtr = head;
        SListNode* nodePtr2 = head;
        LOG(INFO) << "p1: " << nodePtr << endl;
        LOG(INFO) << "p2: 0" << endl;
        while(nodePtr != nullptr)
        {
            LOG(INFO) << "start of loop" << endl;
            LOG(INFO) << "p1: " << nodePtr->next << endl;
            nodePtr2 = nodePtr2->next;
            LOG(INFO) << "p1: " << nodePtr << endl;
            LOG(INFO) << "incrementing both pointers" << endl;
            LOG(INFO) << "Deleting node with address " << nodePtr << " and value " << nodePtr->data  << endl;
            delete nodePtr;
            nodePtr = nodePtr2;
        }
        LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    }


    bool Insert(T val)
    {
        LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
        // insert a new node to store val 
        // at the head of the list
        if (head == NULL)
        {
            head = new SListNode(val);
            return true;
        }
        else
        {
            // create a new node to store the value to be added
            SListNode* newNode = new SListNode(val);
            // set the next pointer of the new node to point to the current first node in the list
            newNode->next = head;
            // make this node the new front by setting the head pointer to it
            head = newNode;
            //newNode = nullptr;
            return true;
        }
        LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
        LOG(INFO) << "Returning " << "true" << endl;
    }

    bool InsertAfter(T val, T prev_val)
    {
        LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
        SListNode* nodePtr = Search(val);
        bool result;
        if(nodePtr == NULL)
        {
            result = false;
        }
        else
        {
            SListNode* nodePtr2 = new SListNode(prev_val);
            nodePtr2->next = nodePtr->next;
            nodePtr->next = nodePtr2;
            result = true;
        }
        LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
        return result;
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





