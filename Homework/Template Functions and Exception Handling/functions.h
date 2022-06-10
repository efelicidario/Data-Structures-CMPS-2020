#pragma once
#include "cmpslib19.h"
#include "easylogging++.h"

/*
   function1
name: Difference
pass by value 
returns the difference between the parmaters one and two (template type)
the difference should alwasy be positive (template type)
if the 2nd param is larger than the first throw "Invalid result"
like so 
if ( one > two)
throw "Invalid Result";

while this is a template function it will only work with numeriic data types
test with double and int
*/

    template <class T>
T Difference(T val, T val2)
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Start Params: " << val << ", " << val2 << endl; 
    T result;
    if (val2 > val)
        throw "Invalid result.";
    else
        result = val - val2;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End returning: " << result << endl;
    return result;
}

/*
   function2
name: Difference
pass by reference
calculate the difference between the parmaters one   and two, store the result in parameter three
the difference should alwasy be positive (template type)
if the 2nd param is larger than the first throw "Invalid result"

while this is a template function it will only work with numeriic data types
test with double and int
*/

    template <class T>
void Difference(T val, T val2, T& val3)
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Start Params: " << val << ", " << val2 << ", " << val3 << endl; 
    if (val2 > val)
        throw "Invalid result.";
    else
        val3 = val - val2;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End params: " << val << ", " << val2 << ", " << val3 << endl; 
}

/*
   function3
name: IsBetween
pass by value
is parameter one between parameters two (low) and three (high) the parameters are (template type)
if parameter two and three do not make a valid range throw "Invalid range"
return the result (bool)
*/

template <class T>
bool IsBetween(T a, T b, T c)
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Start Params: " << a << ", " << b << ", " << c << endl; 
    bool result = false;
    if (b >= c)
        throw "Invalid range.";
    else if (a > b && a < c)
        result = true;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End Params: " << a << ", " << b << ", " << c << endl; 
    return result;
}

/*
function4
name: IsBetween
pass by reference
is parameter one between parameters two (low) and three (high) (template type)
if parameter two and three do not make a valid range throw "Invalid range"
store the result (bool) in parameter 4

test all 4 of your functions by calling them 4 times each , use two distinct data types , DO NOT call any function more than once with the exact same values
LOG THE START AND END OF ALL FUNCTIONS
*/

template <class T>
void IsBetween(T a, T b, T c, bool& result)
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Start Params: " << a << ", " << b << ", " << c << endl; 
    result = false;
    if (b >= c)
        throw "Invalid range.";
    else if (a > b && a < c)
        result = true;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End Params: " << a << ", " << b << ", " << c << endl; 
}









