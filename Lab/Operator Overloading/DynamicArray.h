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
        bool operator == (const DynamicArray& );
        DynamicArray & operator = (const DynamicArray& );
        DynamicArray operator + (const DynamicArray& );
        void setCap(int cap);
        void setData(string* array, int size, int index);
        bool empty();

};
