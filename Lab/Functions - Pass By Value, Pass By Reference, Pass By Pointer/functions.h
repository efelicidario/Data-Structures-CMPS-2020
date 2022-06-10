#pragma once

#include "cmpslib19.h" // all the special functions provided for this class

#include "easylogging++.h"

//DO NOT use the same function name for multiple functions
//when you test your functions it must be clear which function you are testing
//overloading a function name will be ambiguous so for this assignment DO NOT do it
//DO NOT return anything other than void unless it is absolutely necessary
//DO NOT use pass by refference or pass by pointer for ANY parameters that do not need to change 
//unlees you make them const
//the pass by value function is the only one that does not return void



//Create 3 functions that will triple an int value
//each of the functions will have one parameter, the integer to triple
//one function will be PBV, one function will be PBP and one function will be PBR 
int TripleInt1(int );
void TripleInt2(int* );
void TripleInt3(int& );

//create two functions that will allow a user to swap two integer values 
//one function will have two PBR parameters and 
//one function will have two PBP parameters
void SwapInt1(int* , int* );
void SwapInt2(int& , int& );

//create 3 functions that can be used to determine the larger of 2 integer values
//one function will be PBV and return the result
//the other two functions will have 3 parameters, the result ( the larger of parameter one and two ) will be stored in the third
//parameter, in one function the third parameter will be PBR and on the other PBP 
int Larger1(int , int );
void Larger2(int , int , int& );
void Larger3(int , int , int* );



