#include "DynamicArray.h"


// put all the function bodies for the DynamicArray class here

DynamicArray::DynamicArray()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    capacity = 5;
    LOG(INFO) << "Start Params: " << capacity << endl;
    //LOG(INFO) << "at the beginning of the constructor the pointer data is: " << data << endl;
    data = new string[capacity];
    object_count = 0;
    object_count++;
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End Params: " << capacity << endl;
    //LOG(INFO) << "at the end of the constructor the pointer data is: " << data << ", it should be different than what it was" << endl;
}

DynamicArray::DynamicArray(int capacity)
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Start Params: " << capacity << endl;
    this->capacity = capacity;
    //LOG(INFO) << "at the beginning of the constructor the pointer data is: " << data << endl;
    data = new string[capacity];
    object_count++;
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End Params: " << capacity << endl;
    //LOG(INFO) << "at the end of the constructor the pointer data is: " << data << ", it should be different than what it was" << endl;
}

DynamicArray::DynamicArray(DynamicArray& Darr)
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    //LOG(INFO) << "at the beginning of the constructor the pointer data is: " << data << endl;
    capacity = Darr.getCap();
    //LOG(INFO) << "setting the pointer 'data' to a new array of size " << capacity << endl;
    data = new string[capacity];
    string* temp = new string[capacity];
    temp = Darr.getData();
    //LOG(INFO) << "copying the values in the array over" << endl;
    object_count++;
    for(int loop=0;loop<capacity;loop++)
    {
        LOG(INFO) << "copying value at position " << loop << " from object passed in to my array" << endl;
        data[loop] = temp[loop];
    }
    //LOG(INFO) << "at the end of the constructor the pointer data is " << data << ", it should be different than what it was" << endl;
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

int DynamicArray::GetObjectCount()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning: " << object_count << endl;
    return object_count;
}

DynamicArray::~DynamicArray()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "in destructor object_count=" << object_count <<", data=" << data << endl;
    object_count--;
    delete[] data;
    data = NULL;
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
}

string DynamicArray::ToString()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    string result = "";
    cout << "capacity: " << getCap() << endl;
    cout << "object_count: " << object_count << endl;
    for(int loop=0;loop<capacity;loop++)
    {
        result += "data[" + NumberToString(loop) + "] value: " + NumberToString(data[loop]) + "\n";
    }
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning: capacity: " << capacity << "\nobject_count: " << object_count << "\n" << result << endl;
    return result;
}

string CreateXML(DynamicArray& Darr)
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    string result;
    result += "<DynamicArray>\n<capacity>" + NumberToString(Darr.capacity) + "</capacity>\n";
    result += "<object_count>" + NumberToString(Darr.object_count) + "</object_count>\n";
    result += "<data>\n";
    string* data = Darr.getData();
    for(int loop=0;loop<Darr.getCap();loop++)
    {
        result += "  <value>" + data[loop] + "</value>\n";
    }
    result += "</data>\n</DynamicArray>\n";
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning: " << result << endl;
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
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning: " << result << endl;
    return result;
}

int DynamicArray::object_count = 0;
