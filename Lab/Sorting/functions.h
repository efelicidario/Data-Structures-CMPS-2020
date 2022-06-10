#pragma once
#include "cmpslib19.h"
#include "easylogging++.h"


int Sort1(int *array, int N)
{
    // a basic bubble sort 
    // for loop outer ( 0 to N-1)
    // for loop inner ( 0 to N-2)
    // compare two adjacent items (inner and inner+1) and std::swap if necessary
    //    
    // use an int to count up of how many comparisons occur and return it  
    // 
    // basically requires N squared iterations, always the same 
    // log the start , end and the value returned ( look at the example log)
    // comparing position 17 with position 18
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    int comparisons = 0;
    for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<N-1;j++)
        {
            LOG(INFO) << "comparing position " << j << " with position " << j + 1 << endl;
            if(array[i] > array[i+1])
            {
                int temp = array[i];;
                array[i] = array[i+1];
                array[i+1] = temp;
                //LOG(INFO) << "swapping " << i+1 << " with " << i << endl;
            }
            comparisons++;
        }
        comparisons++;
    }
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning " << comparisons << endl;
    return comparisons;
}


int Sort2(int *array, int N)
{
    // for loop outer( 0 to N-1 )
    // for loop inner( 0 to (N-1 - outer) )     
    // compare two adjacent items (inner and inner+1) and std::swap if necessary
    //
    // use an int to count up how many comparisons occur and return it  
    // basically requires (n(n+1))/2 iterations, always the same
    // log the start , end and the value returned ( look at the example log)
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    int comparisons = 0;
    for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<(N-i-1);j++)
        {
            LOG(INFO) << "comparing position " << j << " with position " << j + 1 << endl;
            comparisons++;
            if(array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning " << comparisons << endl;
    return comparisons;
} 


int Sort3(int *array, int N)
{
    // same basic logic as Sort2
    // except the outer loop will not be a for..loop  it will now be a do..while loop so we can stop as soon as it is sorted
    // how do we know if its sorted .. if we traverse the array all the way from front to back  and we dont
    // need to swap any it must be sorted
    // there is a bool flag "IsSorted" set to false
    // we set it true before each pass through the array (inner loop)  
    // if during the pass through the array we need to swap two values it is not sorted
    // so set storted to false so we will repeat the do.. while loop one more time at least
    //
    // use an int to keep track of how many comparisons occur and return it  
    // basically <= (n(n+1) / 2  iterations, can vary greatly depending on how unsorted the target is
    // log the start , end and the value returned ( look at the example log)
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    bool sorted=false;
    int outer=0;
    int comparisons=0;
    do 
    {
        sorted=true;
        // copy your inner loop and sort from Sort2
        // if you do have to swap a value then also set sorted=false;
        for(int j=0;j<(N-outer-1);j++)
        {
            LOG(INFO) << "comparing position " << j << " with position " << j + 1 << endl;
            if(array[j] > array[j+1])
            {
                int temp;
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                sorted=false;
            }
            comparisons++;
        }
        // after the inner loop and traversing the array
        // sorted == true if we didnt need to swap 
        // sorted == false if we did need to swap  

        outer++;
    }
    while( ! sorted ); // if sorted is false repeat the process

    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning " << comparisons << endl;
    return comparisons;

}














