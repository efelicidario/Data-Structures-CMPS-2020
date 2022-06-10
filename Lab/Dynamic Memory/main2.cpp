/*
   All rights reserved. No part of this document may be reproduced, distributed,   or transmitted in any form or by any       means, including                     photocopying,             recording, or other electronic or mechanical methods, without the prior         written permission of the author, Michael Sarr
   */

#include "cmpslib19.h"





void PrintArray(int*array,int size)
{
    cout << "Array Address: " << array << endl;
    for(int loop =0; loop<size; loop++)
    {
        if(loop)
        {
            cout << ", ";
        }
        cout << array[loop];
    }
    cout << endl;
}

int main()
{

    char filename[50];
    int choice ;
    Prompt("Enter a value 1-3 to chose the file to open: ",choice,1,3);

    if (choice ==1 )
    {
        strncpy(filename,"test_input9.txt",50);
    }

    if (choice ==2 )
    {
        strncpy(filename,"test_input50.txt",50);
    }

    if (choice ==3 )
    {
        strncpy(filename,"test_input100.txt",50);
    }

    std::ifstream in;// Create an input file stream.

    in.open(filename);

    if (in.fail())
    {
        cout << "Could not open file \""<< filename <<endl;
        return 9;
    }

    cout << "Creating dynamic array named 'data' of size 5." << endl;
    cout << "Creating int index = 0  and int capacity = 5." << endl;
    int capacity = 5;
    int temp2;
    int index = 0;
    int* data = new int[capacity];
    cout << "Adding records and incrementing count each time.\nReading the values into my dynamic array.\nOpening file for the first and ONLY time " << filename << ".\nReading the values in and storing them into the array NOT printing them." << endl;
    while(in >> temp2)
    {
        cout << "Storing " << temp2 << " into data[" << index << "]" << endl;
        if(index == capacity)
        {
            cout << "\tThe array is full, must resize." << endl;
            cout << "\tCurrent address of data is: " << data << endl;
            cout << "\tCapacity = " << capacity << endl;
            cout << "\tIndex = " << index << endl;
            cout << "\tArray[" << capacity << "] is off the end of our array, array[" << capacity -1 << "] is the last element so lets resize." << endl;
            cout << "\tCreate a temp * and set it to a new array of size 10." << endl;
            int* temp = new int [capacity * 2];
            cout << "\tAll the values are copied to the new array." << endl;
            for(int i=0;i<capacity;i++)
            {
                temp[i] = data[i];
                cout << "\t\tcopying data[" << i << "]  (" << data[i] << ") to the new array" << endl;
            }
            cout << "\tDelete the old array." << endl;
            delete[] data;
            cout << "\tSet our array pointer to point to the new array (our temp *)." << endl;
            data = temp;
            cout << "\tSet capacity to be double what it was." << endl;
            capacity *= 2;
            cout << "\tCurrent address of data is: " << data << endl;
            cout << "\tCapcity = " << capacity << endl;
            cout << "\tIndex = " << index << endl;
            cout << "\tWe have room now so continue on." << endl;
        }
        data[index] = temp2;
        index++;
    }
    in.close();
    cout << "Closing file: " << filename << endl;
    cout << "Calling PrintArray() to print out the values in my array." << endl;
    PrintArray(data, index);
    cout << "Deleting dynamic array." << endl;
    delete[] data;
    data = NULL;



    return 0;
}






