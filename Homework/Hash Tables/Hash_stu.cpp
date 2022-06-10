#include "Hash.h"



// Calculates the primary key using modulo arithmetic
// Primary key will be in the range 0 to MAX_CAPACITY - 1
int HashTable::hash1(int value)
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning:  " << (value % MAX_CAPACITY) << __PRETTY_FUNCTION__ << endl;
    return (value % MAX_CAPACITY);
}

// for the 2nd hash we want to have an alternate method of calculating a hash
// MAX_CAPACITY - ( value % MAX_CAPACITY)
int HashTable::hash2(int value)
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning:  " << MAX_CAPACITY - (value % MAX_CAPACITY) << __PRETTY_FUNCTION__ << endl;
    return MAX_CAPACITY - (value % MAX_CAPACITY);
}


// create a string representation of the HashTable class
// make sure your output from the ToString function matches the example
// before AND AFTER you delete some items
string HashTable::ToString()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    string result;
    result += "Hashtable:\nhash size: " + NumberToString(MAX_CAPACITY) + "\ncount: " + NumberToString(count) + "\n";
    for(int loop=0;loop<MAX_CAPACITY;loop++)
    {
        if(hashtable[loop] != EMPTY_VALUE && hashtable[loop] != DELETED_VALUE)
        {
            result += "hashtable[   " + NumberToString(loop) + "]" + " contains:         " + NumberToString(hashtable[loop]) + " hash1=         " + NumberToString(hash1(hashtable[loop])) + "  hash2=      " + NumberToString(hash2(hashtable[loop])) + "\n";
        }
    }
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning:  " << result << __PRETTY_FUNCTION__ << endl;
    return result;
}









