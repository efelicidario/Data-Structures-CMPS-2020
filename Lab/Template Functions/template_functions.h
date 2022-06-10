#include <iostream>
#include "cmpslib19.h"
#include "easylogging++.h"




// here are copies of GetLarger and GetSmaller for datatype char*

// you do NOT want to use the operators <,>,== because you will be comparing the pointers

const char * GetLarger (const char* a, const char* b)
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    const char *temp = (strcmp(a,b) <= 0) ? b:a;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning " << temp << endl;
    return temp;
}

const char * GetSmaller (const char* a, const char* b)
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    const char *temp = (strcmp(a,b) >= 0) ? b: a;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning " << temp << endl;
    return temp;
}


// T GetLarger (T a, T b)
// return the larger value a or b
// use the > operator to compare a & b
    template <class T>
T GetLarger(T a, T b)
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    T larger;
    if (a > b)
        larger = a;
    else
        larger = b;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning " << larger << endl;
    return larger;
}

// T GetSmaller (T a, T b)
// return the smaller value a or b
// use the < operator to compare a & b
// log the value you will return like the examples 
    template <class T>
T GetSmaller (T a, T b)
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    T smaller;
    if (a < b)
        smaller = a;
    else
        smaller = b;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning " << smaller << endl;
    return smaller;
}

// T GetLarger (T a, T b, T c)
// return the larger value a,b or c
// log the value you will return like the examples 
// you only need to call the GetLarger for 2 parameters twice , first with a & b then use that result to compare with c
// DO NOT USE < or > in this function
// we want to use this function to work for ( char * ) or constant c strings too you cant use < or > on them
    template <class T>
T GetLarger(T a, T b, T c)
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    T temp, larger;
    temp = GetLarger(a, b);
    larger = GetLarger(temp, c);
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning " << larger << endl;
    return larger;
}

// T GetSmaller (T a, T b, T c)
// return the smaller value a,b or c
// log the value you will return like the examples 
// you only need to call the GetSmaller for 2 parameters twice , first with a & b then use that result to compare with c
// DO NOT USE < or > in this function
template <class T>
T GetSmaller(T a, T b, T c)
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    T temp, smaller;
    temp = GetSmaller(a, b);
    smaller = GetSmaller(temp, c);
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning " << smaller << endl;
    return smaller;
}

// void SwapValues( T & a, T & b)
// swap the values in the two parameters passed in
// DO NOT use the "swap" function
template <class T>
void SwapValues(T& a, T& b)
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    T temp;
    temp = a;
    a = b;
    b = temp;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}

// void PromptForValue ( string message, T & val)
// display the text in message 
// use cin to read a value into val
template <class T>
void PromptForValue(string message, T& val)
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    cout << message << endl;
    cin >> val;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}













