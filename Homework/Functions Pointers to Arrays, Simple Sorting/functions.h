/*
   All rights reserved. No part of this document may be reproduced, distributed,   or transmitted in any form or by any       means, including photocopying,             recording, or other electronic or mechanical methods, without the prior         written permission of the author, Michael Sarr
   */
#pragma once
#include "cmpslib19.h"
#include "fraction.h"
#include "easylogging++.h"


// NOTE THAT YOU CANNOT USE THE INDEX OPERATOR IN  BOTH SORTS
// AS DESCRIBED BELOW , READ IT

// SortAscending
// template function
//   use the index operator [] to access and modify the elements DO NOT use the Indirection  (*) operator
//   use the BUBBLE sort logic below and the logging suggested there as well
    template <class T>
bool SortAscending(T* array, int size)
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Starting Params: " << array << ", " << size << endl;
    for(int outer=0;outer<size;outer++)
    {
        for (int inner=0;inner<size-outer;inner++)
        {
            LOG(INFO) << "comparing positions " << inner << " and " << outer << ", values are " << array[inner] << " and " << array[outer] << endl;
            if (array[inner] > array[inner+1])
            {
                LOG(INFO) << "swapping the value at position " << inner << " with the value at position " << outer << ", values are " << array[inner] << " and " << array[outer] << endl;
                T temp = array[inner + 1];
                array[inner + 1] = array[inner];
                array[inner] = temp;
            }
        }
    }
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End Params: " << array << ", " << size << endl;
    return true;
}

// SortDescending
// template function
//   use pointer arithmetic and the Indirection operator (*)   DO NOT use the  index operator ([])
//   use the BUBBLE sort logic below and the logging suggested there as well
    template <class T>
bool SortDescending(T* array, int size)
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Starting Params: " << array << ", " << size << endl;
    for(int outer=0;outer<size;outer++)
    {
        for(int inner=0;inner<size-outer;inner++)
        {
            LOG(INFO) << "comparing positions " << inner << " and " << outer << ", values are " << array[inner] << " and " << array[outer] << endl;
            if(array[inner] < array[inner+1])
            {
                LOG(INFO) << "swapping the value at position " << inner << " with the value at position " << outer << ", values are " << array[inner] << " and " << array[outer] << endl;
                T temp = array[inner+1];
                array[inner+1] = array[inner];
                array[inner] = temp;
            }
        }
    }
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End Params: " << array << ", " << size << endl;
        return true;
}

    // PrintArray
    // template function
    //   the format should be like:
    //   Position:1 value:29
    //   look at the output of the runnable example if you are unsure
template <class T>
void PrintArray(const T* array, int size)
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Start Params: " << array << ", " << size << endl;
    for(int i=0;i<size;i++)
    {
        LOG(INFO) << "Inside loop, couter = " << i << endl;
        cout << "Position: " << i << " Value: " << array[i] << endl;
    }
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End Params: " << array << ", " << size << endl;
}

    // FillArrayWithRandom (pointer to the array of type Cfraction, size of the array)
    // NOT A TEMPLATE function
    //   fill the array pointed to by (target) with (count) elements
    //   you MUST use the CreateRandomNumber function in cmpslib19.h
    //   to change the value of a fraction you will need to call
    //   SetNumerator and SetDenominator functions
    //   make the numerator a random value from 0-100
    //   make the denominatory random value from 1-100
  void FillArrayWithRandom(CFraction* array, int size)
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    for(int i=0;i<size;i++)
    {
        LOG(INFO) << "Inside loop, counter= " << i << endl;
        array[i].SetNumerator(CreateRandomNumber(0, 100));
        array[i].SetDenominator(CreateRandomNumber(0, 100));
    }
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
}



    // FillArrayWithRandom (pointer to the array, size of the array, min val, max val
    // template function
    //   fill the array pointed to by (target) with (count) elements
    //   you MUST use the CreateRandomNumber function in cmpslib19.h
template <class T>
void FillArrayWithRandom(T* array, T size, T min, T max)
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    for(int i=0;i<size;i++)
    {
        LOG(INFO) << "storing " << array[i] << " To position " << i << endl;
        array[i] = CreateRandomNumber(min, max);
    }
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
}


    // LargestInArray
    // template function
    // array parameter is "const T *"
    //   return a copy of the largest value found
    //   do not modify the values in the array
template <class T>
T LargestInArray(const T* array, int size)
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Start Params: " << array << ", " << size << endl;
    T result = array[0];
    for(int i=0;i<size;i++)
    {
       if(array[i] > result)
       {
           result = array[i];
       } 
    }
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning: " << result << endl;
    return result;
}

    // SmallestInArray
    // template function
    // array parameter is "const T *"
    //   return a copy of the smallest value found
    //   do not modify the values in the array
template <class T>
T SmallestInArray(const T* array, int size)
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Start Params: " << array << ", " << size << endl;
    T result = array[0];
    for (int i=0;i<size;i++)
    {
        if(array[i] > result)
            result = array[i];
    }
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning: " << result << endl;
    return result;
}





