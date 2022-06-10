#pragma once
#include "cmpslib19.h"
#include "easylogging++.h"

class DynamicArray
{
    private:    // private data members
        string* data;
        int capacity;

    public:     //publc functions
        DynamicArray();
        DynamicArray(int );
        DynamicArray(const DynamicArray& Darr);
        ~DynamicArray();
        string ToString();
        bool SetValue(string , int);
        int getCap() const;
        string* getData() const;
};
