#include <iostream>
#include <limits>
#include "cmpslib19.h"
#include "easylogging++.h"

using namespace std;

#define MAX_CAPACITY   1013    // MAX_CAPACITY is a prime number
#define EMPTY_VALUE      -1    // invalid value, represents empty slot
#define DELETED_VALUE    -2    // invalid value, represents deleted slot



class HashTable
{
    private:
        int count;                         // count of values currently stored
        int hashtable[MAX_CAPACITY];

    public:
        int colisions;

        /*
           initialize all slots in the array to EMPTY_VALUE
           set count to 0
           */
        HashTable( )
        {
            for(int loop=0;loop<MAX_CAPACITY;loop++)
                hashtable[loop] = EMPTY_VALUE;
            count = 0;
        }


        // return true if hash table is empty
        bool empty()
        {
            for(int loop=0;loop<MAX_CAPACITY;loop++)
            {
                if(hashtable[loop] != -1)
                    return false;
            }
            return true;
        }

        // return true if hash table is full
         bool full()
         {
             for(int loop=0;loop<MAX_CAPACITY;loop++)
             {
                 if(hashtable[loop] == -1)
                     return false;
             }
             return true;
         }

        /*
           primary hash function: a modulo function
           it will return (value mod MAX_CAPACITY)
           */
        int hash1(int value);

        /*
           secondary hash function.
           it will return  MAX_CAPACITY - hash1(value) 
        */
        int hash2(int value);


        /*
           Searches for the value in the table, returning true if found, false if not
           search in the order
           1st position   hash1
           2nd position	 hash2
           3rd position	 hash2 +5
           4th position	 hash2 +10
           5th position	 hash2 +15
           and so on



           If the position contains the value you are looking for return true
           If the position contains EMPTY_VALUE return false
           otherwise keep searching the next position 
           do NOT stop  when a DELETED_VALUE is reached
           */
        bool search(int value)
        {
            int hash = hash1(value);
            int check = hash;
            do
            {
                if(hashtable[hash] == value)
                    return true;
                if(hash < MAX_CAPACITY)
                    hash++;
                else
                    hash = 0;
            }
            while (hashtable[hash] != EMPTY_VALUE && hash != check);
            return true;
        }




        /*
           if the hash is full return false

           insert the value into the table
		   try to insert into the positions
           1st position   hash1
           2nd position	 hash2
           3rd position	 hash2 +5
           4th position	 hash2 +10
           5th position	 hash2 +15
           and so on

           insert at the first postition you find  EMPTY_VALUE or DELETED_VALUE 
           return true;
           */
        bool insert(int value)
        {
            int hash = hash1(value);
            if(value == EMPTY_VALUE || value == DELETED_VALUE)
                //throw exception;
            while (hashtable[hash] != EMPTY_VALUE && hashtable[hash] != DELETED_VALUE && ! full())
            {
                if(hash < MAX_CAPACITY)
                    hash++;
                else
                    hash = 0;
            }
            hashtable[hash] = value;
            count++;
            return true;
        }




        /*
           search in the order
           1st position   hash1
           2nd position	 hash2
           3rd position	 hash2 +5
           4th position	 hash2 +10
           5th position	 hash2 +15
           and so on

           if you find it replace it with DELETED_VALUE and return true
           if you find EMPTY_VALUE stope and return false
           */
        bool remove(int value)
        {
            int hash = hash1(value);
            int check = hash;
            if(value == EMPTY_VALUE || value == DELETED_VALUE)
                throw value;
            do
            {
                if(hashtable[hash] == value)
                {
                    hashtable[hash] = DELETED_VALUE;
                    count--;
                }
                if(hash < MAX_CAPACITY)
                    hash++;
                else
                    hash = 0;
            }
            while(hashtable[hash] != EMPTY_VALUE && hash != check);
            return true;
        }

        /*
           returns a string representation of the hashtable
           */
        string ToString();



};


