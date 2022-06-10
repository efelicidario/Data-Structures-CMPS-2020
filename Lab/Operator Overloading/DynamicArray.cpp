#include "DynamicArray.h"


// put all the function bodies for the DynamicArray class here

DynamicArray::DynamicArray()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Start Params: " << capacity << endl;
    capacity = 5;
    LOG(INFO) << "at the beginning of the constructor the pointer data is: " << data << endl;
    data = new string[capacity];
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End Params: " << capacity << endl;
    LOG(INFO) << "at the end of the constructor the pointer data is: " << data << ", it should be different than what it was" << endl;
}

DynamicArray::DynamicArray(int capacity)
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Start Params: " << capacity << endl;
    this->capacity = capacity;
    LOG(INFO) << "at the beginning of the constructor the pointer data is: " << data << endl;
    data = new string[capacity];
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End Params: " << capacity << endl;
    LOG(INFO) << "at the end of the constructor the pointer data is: " << data << ", it should be different than what it was" << endl;
}

DynamicArray::DynamicArray(const DynamicArray& Darr)
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "at the beginning of the constructor the pointer data is: " << data << endl;
    capacity = Darr.getCap();
    LOG(INFO) << "setting the pointer 'data' to a new array of size " << capacity << endl;
    data = new string[capacity];
    string* temp = new string[capacity];
    temp = Darr.getData();
    LOG(INFO) << "copying the values in the array over" << endl;
    for(int loop=0;loop<capacity;loop++)
    {
        data[loop] = temp[loop];
    }
    LOG(INFO) << "at the end of the constructor the pointer data is " << data << ", it should be different than what it was" << endl;
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
}

int DynamicArray::getCap() const
{
    return capacity;
}

string* DynamicArray::getData() const
{
    return data;
}

DynamicArray::~DynamicArray()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "calling delete[] on the pointer 'data'" << endl;
    delete[] data;
    data = NULL;
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
}

string DynamicArray::ToString()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    string result = "";
    cout << "capacity: " << getCap() << endl;
    for(int loop=0;loop<capacity;loop++)
    {
        result += "data[" + NumberToString(loop) + "] value: " + NumberToString(data[loop]) + "\n";
    }
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End Returning: " << result << endl;
    return result;
}

bool DynamicArray::SetValue(string val, int pos)
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Start Params: " << val << ", " << pos << endl;
    bool result;
    if(pos >= 0 && pos <= capacity-1)
    {
        data[pos] = val;
        result = true;
    }
    else
    {
        result = false;
    }
    LOG(INFO) << "End Returning: " << result << endl;
    return result;
}

bool DynamicArray::operator == (const DynamicArray& array)
{
    bool confirm = true;
    if(array.getCap() != this->getCap())
    {
        confirm = false;
    }
    else if((array.getData() != NULL) && (this->getData() != NULL))
    {
        string* temp;
        string* temp2;
        temp = new string[this->getCap()];
        temp = array.getData();
        temp2 = new string[this->getCap()];
        temp2 = this->getData();
        if((temp[0].empty()) && (temp2[0].empty()))
        {
            for(int loop=0;loop<array.getCap();loop++)
            {
                if(temp[loop] != temp2[loop])
                {
                    confirm = false;
                }
            }
            delete[] temp;
            temp = NULL;
        }
    }
    return confirm;
}

DynamicArray & DynamicArray::operator = (const DynamicArray& array2)
{
    this->setCap(array2.getCap());
    this->setData(array2.getData(), array2.getCap(), 0);
    return* this;
}

DynamicArray DynamicArray::operator + (const DynamicArray& array3)
{
    DynamicArray temp(this->getCap() + array3.getCap());
    temp.setData(this->getData(), this->getCap(), 0);
    temp.setData(array3.getData(), array3.getCap(), this->getCap());
    return temp;
}

void DynamicArray::setCap(int cap)
{
    capacity = cap;
}

void DynamicArray::setData(string * array, int size,int index)
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    string * temp;
    temp = new string[size];
    temp = array;
    for(int i=0;i<size;i++)
    {
        //if index = 5, then data should start at 5th position
        data[i + index] = temp[i];
    }
    delete [] temp;
    temp = NULL;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}
//to check if the class is empty
/*bool DynamicArray::empty()
{
    bool confirm;
    if(capacity == 0)
        confirm = true;
    else if()

    return confirm;
}
*/






















