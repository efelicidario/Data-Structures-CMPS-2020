/* 
   cmpslib19.h , contains lots of functions that we use in this class
   easylogging.h, conatins functions for logging 
   INITIALIZE_EASYLOGGINGPP // put above the main function to initialze the logging code, only in the main file

*/

#include "cmpslib19.h" 
#include "easylogging++.h"
INITIALIZE_EASYLOGGINGPP


// put your functions here
/*
   int TripleInt(int val)
   {
// use this line at the start of EVERY function you write in this class  

LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
int result =  val *=3;

// use this line in EVERY function and before EVERY return statement if you have multiple return statements.. t

LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
return result;
}

int SmallerInt(int val, int val2)
{
LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
int result;
if(val < val2)
result = val;
else
result = val2;
LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
return result;
}
*/

void Function1(string elem)
{
    cout << elem << endl;
}

int main()
{
    Function1("Hello World");
    /*
       InitializeLogger("main1.log"); // this is the name of the file the logging output will go to




       cout << endl << endl;
       cout <<"Testing TripleInt" << endl;

       int temp;
       cout << "TripleInt(1): ";
       temp = TripleInt(1);
       if ( 3 == temp )   // test the value returned by the function to ensure it is correct  

       cout << "Pass" << endl; // 3==temp , the correct answer

       else
       cout << "Fail" << endl;
       */
    /* 
       PassFail( bool)  is a function that returns a string either "Pass" or "Fail"
       depending on the expressions value
       put an exprssion that evaluates to TRUE only if your your function actually came back with the correct answer
       you can use it to lessen the amount of code requred for tests
       */

    // 3*3 is 9 does it work properly

    // dont print out the value that it comes back with test it. then print either pass for fail
    /*
       cout << "TripleInt(3): ";
       temp = TripleInt(3);
       cout << PassFail( 9 == temp) << endl; // prints either "Pass" or "Fail"  



    // 3*0 is 0 does it work properly

    cout << "TripleInt(0): ";
    temp = TripleInt(0);
    cout << PassFail( 0 == temp) << endl; 


    // 3*-5 is -15 does it work properly

    cout << "TripleInt(-5): ";
    temp = TripleInt(-5);
    cout << PassFail( -15 == temp) << endl; 




    // continue testing the rest of your functions

    // test LargerInt 4 times with disparate values

    cout <<"\nTesting LargerInt" << endl;

    int larger;

    cout << "LargerInt(1, 2): ";
    larger = LargerInt(1, 2);
    cout << PassFail(2 == larger) << endl;

    cout << "LargerInt(100, 0): ";
    larger = LargerInt(100, 0);
    cout << PassFail(100 == larger) << endl;

    cout << "LargerInt(4, 20): ";
    larger = LargerInt(4, 20);
    cout << PassFail(20 == larger) << endl;

    cout << "LargerInt(60, 3): ";
    larger = LargerInt(60, 3);
    cout << PassFail(60 == larger) << endl; 

    // test SmallerInt 4 times with disparate values

    cout << "\nTesting SmallerInt" << endl;

    int smaller;

    cout << "SmallerInt(-5, 0): ";
    smaller = SmallerInt(-5, 0);
    cout << PassFail(-5 == smaller) << endl;

    cout << "SmallerInt(-9, -6): ";
    smaller = SmallerInt(-9, -6);
    cout << PassFail(-9 == smaller) << endl;

    cout << "SmallerInt(80, 10): ";
    smaller = SmallerInt(80, 10);
    cout << PassFail(10 == smaller) << endl;

    cout << "SmallerInt(19, -42): ";
    smaller = SmallerInt(19, -42);
    cout << PassFail(-42 == smaller) << endl;

    cout << "TEST" << endl;

    int a=6;//the address of a:0x7fff256b5c94
    int arr[]={7,8,4,3,1};// the address of the elements in arr: 0x7fff256b5c98, 0x7fff256b5c9c, 0x7fff256b5ca0, 0x7fff256b5ca4, 0x7fff256b5ca8
    int * b = arr+2;
    int * c = &a;
    int * d = b;
    cout << "*d:" << *d << endl;
    */


    return 0;
}
