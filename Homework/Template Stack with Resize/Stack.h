#pragma once
#include "cmpslib19.h"
#include "easylogging++.h"

template <class T>
class Stack
{
    private:
        T * data;
        int TopIndex;
        int capacity;

        // a private function that will double the capacity of the array and copy the values over ... resize
        void Resize()
        {
            LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
            T * temp = data;
            data = new T [2 * capacity];
            for(int loop=0;loop<capacity;loop++)
            {
                data[loop] = temp[loop];
            }
            delete [] temp;
            capacity *= 2;
            LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
        }
        /*
           void Resize()
           {
            LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
               T * temp = new T [capacity * 2];
               for(int loop=0;loop<capacity;loop++)
                   temp[loop] = data[loop];
               delete [] data;
               data = temp;
               capacity *= 2;
            LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
           }
           */

    public:
        // you will need a constructor it will allow the user to pass in the size/capacity of the container as the only parameter
        // have this default to the value of 4
        Stack(int size = 4)
        {
            LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
            capacity = size;
            data = new T [capacity];
            TopIndex = 0;
            LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
        }


        // destructor , clean up the array data
        ~Stack()
        {
            LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
            if(data != NULL)
            {
                delete [] data;
                data = NULL;
            }
            LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
        }


        // a public function that returns true or false if the container is empty
        bool Empty()
        {
            LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
            bool result;
            if(TopIndex == 0)
                result = true;
            else
                result = false;
            LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
            LOG(INFO) << "Returning: " << result << endl;
            return result;
        }


        // a public function that returns true or false if the container is full
        bool Full()
        {
            LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
            bool result;
            if(TopIndex == capacity)
                result = true;
            else
                result = false;
            LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
            LOG(INFO) << "Returning: " << result << endl;
            return result;
        }


        // a public function that allows a value to be added or  "pushed" into the stack
        bool Push(T val)
        {
            LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
            // if the container is full it calls resize then adds the value
            bool result = true;
            if(Full())
                Resize();
            data[TopIndex] = val;
            TopIndex++;
            // returns true
            LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
            LOG(INFO) << "Returning: " << result << endl;
            return result;
        }


        // a public function that will remove or "popp' a value from the stack
        bool Pop()
        {
            LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
            bool result;
            // true or false if pop operation was successful
            if(Empty())
                result = false;
            else
            {
                TopIndex--;
                result = true;
            }
            LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
            LOG(INFO) << "Returning: " << result << endl;
            return result;
        }


        // a public function that returns the value at the top value on the stack
        T Top()
        {
            LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
            // throws a descriptive message if stack is empty
            if(Empty())
            {
                throw
                    ("Stack::Top could not return top value from empty stack.");
            }
            LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
            LOG(INFO) << "Returning: " << data[TopIndex-1] << endl;
            return data[TopIndex-1];
        }


        // a public function that returns the capacity of the stack
        int Capacity()
        {
            LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
            LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
            LOG(INFO) << "Returning: " << capacity << endl;
            return capacity;
        } 


        // a public function that returns the size of the stack
        int Size()
        {
            LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
            LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
            LOG(INFO) << "Returning: " << TopIndex << endl;
            return TopIndex;
        } 


        // ToString returns a string representation of the container.. see example for format
        string ToString()
        {
            LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
            string result;
            result += "ToString():\nTopIndex: " + NumberToString(Size()) + "\nCapacity(): " + NumberToString(Capacity()) + "\nEmpty(): " + NumberToString(Empty()) + "\nFull(): " + NumberToString(Full()) + "\n";
            for(int loop=0;loop<TopIndex;loop++)
            {
                result += "data[" + NumberToString(loop) + "]: address: " + NumberToString(&data[loop]) + " value: " + NumberToString(data[loop]) + "\n";
            }
            LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
            LOG(INFO) << "Returning: " << result << endl;
            return result;
        }

}; // end Stack class


