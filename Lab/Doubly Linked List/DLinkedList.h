#pragma once
#include "cmpslib19.h"
#include "easylogging++.h"



template <class T>
class DLinkedList
{
    /* 
       We need a node that is templated to store the same type as our 
       Linked List. The easiest way to do this is make it an "Inner" class
       It contains an element of the template type
       and a pointer to the next node in the list.
       */
    class DListNode
    {
        public:
            T data;
            DListNode *next;
            DListNode(T val)
            {
                data = val;
                next = nullptr;
            }
            DListNode* prev;
    };

    DListNode * head;
    DListNode * tail;


    DListNode* Search(T val)
    {
        LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
        DListNode* newNode = head;
        DListNode* result = nullptr;
        while(newNode != result)
        {
            if(newNode->data == val)
                result = newNode;
            else
            newNode = newNode->next;
        }
        LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
        LOG(INFO) << "Returning: a pointer to " << newNode << endl;
        //return newNode;
        return result;
    }


    public:
    DLinkedList()
    {
        LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
        // set head to the nullptr 
        head = nullptr;
        tail = nullptr;
        LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    }

    ~DLinkedList()
    {
        LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
        DListNode* nodePtr = head;
        DListNode* nodePtr2 = head;
        LOG(INFO) << "P1: " << nodePtr << endl;
        LOG(INFO) << "P2: 0" << endl;
        LOG(INFO) << "starting loop" << endl;
        while(nodePtr != nullptr)
        {
            LOG(INFO) << "P1: " << nodePtr->next << endl;
            nodePtr2 = nodePtr2->next;
            LOG(INFO) << "P2: " << nodePtr << endl;
            LOG(INFO) << "deleting P2 with a value of " << nodePtr->data << endl;
            delete nodePtr;
            nodePtr = nodePtr2;
        }
        LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    }


    bool Insert(T val)
    {
        LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
        LOG(INFO) << "Parameter " << val << endl;
        // insert a new node to store val 
        // at the head of the list
        LOG(INFO) << "if head is null , this is the first node inserted\nset head and tail to new node and return true" << endl;
        if (head == nullptr)
        {
            head = new DListNode(val);
            tail = head;
            //head->prev = NULL;
            //tail = NULL;
            return true;
        }
        else
        {
            // create a new node to store the value to be added
            LOG(INFO) << "creating new node" << endl;
            DListNode* newNode = new DListNode(val);
            // set the next pointer of the new node to point to the current first node in the list
            // make this node the new front by setting the head pointer to it
            LOG(INFO) << "set the prev pointer of first node (head) to point to the new node" << endl;
            head->prev = newNode;
            LOG(INFO) << "set the next pointer of the new node to point to the first node (head)" << endl;
            newNode->next = head;
            LOG(INFO) << "set the head to the new first node" << endl;
            head = newNode;
            //newNode = NULL;
            //DListNode* newNode2 = head;
            //while(newNode2->next != NULL)
            //    newNode2 = newNode2->next;
            //tail = newNode2;
            return true;
        }
        LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
        LOG(INFO) << "Returning " << "true" << endl;
    }

    bool InsertAfter(T val, T prev_val)
    {
        LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
        LOG(INFO) << "Use Search to find the node to insert after (after)\nIf it returns the nullptr return false and dont do anything more" << endl;
        DListNode* nodePtr = Search(val);
        if(nodePtr == nullptr)
            return false;
        else
        {
            LOG(INFO) << "make a new node" << endl;
            DListNode* nodePtr2 = new DListNode(prev_val);
            LOG(INFO) << "If the node you want to insert after is the last node (after==tail) then set tail to point to the new node" << endl;
            if(nodePtr == tail)
                tail = nodePtr;
            LOG(INFO) << "if after->next is not the nullptr then we need to tell the node (after->next) it has a new prev node\nafter->next->prev = newnode" << endl;
            if(nodePtr->next != nullptr)
                nodePtr->next->prev = nodePtr2;
            LOG(INFO) << "set next of new node to next of the  node (after)" << endl;
            nodePtr2->next = nodePtr->next;
            LOG(INFO) << "set newnode prev  to  (after)" << endl;
            nodePtr2->prev = nodePtr;
            LOG(INFO) << "set after->next to the newnode" << endl;
            nodePtr->next = nodePtr2;
        }
        LOG(INFO) << "(after)->data :" << nodePtr->data << endl;
        LOG(INFO) << "(after)->prev :" << nodePtr->prev << endl;
        LOG(INFO) << "(after)->next :" << nodePtr->next << endl;
        LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
        LOG(INFO) << "Returning: " << "true" << endl;
        return true;
    }


    string ToString()
    {
        LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
        // return a text representation of the stack
        // IT MUST WORK WITH THE WEBPAGE
        // make sure to test your output
        string stack;
        DListNode* temp = head;
        stack += "head: " + NumberToString(head) + "\ntail: " + NumberToString(tail->data) + "\n";
        while (temp != nullptr)
        {
            stack += "node: " + NumberToString(temp) + " data: " + NumberToString(temp->data) + " prev: " + NumberToString(temp->prev) + " next: " + NumberToString(temp->next) + "\n";
            temp = temp->next;
        }
        LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
        LOG(INFO) << "Returning " << "head: " << head << "\ntail: " << tail << endl;
        return stack;
    }
}; // end SLinkedList





