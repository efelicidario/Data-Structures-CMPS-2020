#include "functions.h"

// put your function bodies here
int TripleInt1(int val)
{
	LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
	val *= 3;
	LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    return val;
}

void TripleInt2(int* val)
{
	LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    *val *= 3;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}

void TripleInt3(int& val)
{
	LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    val *= 3;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}

void SwapInt1(int* val, int*val2)
{
	LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    int temp;
    temp = *val;
    *val = *val2;
    *val2 = temp;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}

void SwapInt2(int& val, int& val2)
{
	LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    int temp;
    temp = val;
    val = val2;
    val2 = temp;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}

int Larger1(int val, int val2)
{
	LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    int larger;
    if (val > val2)
        larger = val;
    else
        larger = val2;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    return larger;
}

void Larger2(int val, int val2, int& larger)
{
	LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
	if (val > val2)
        larger = val;
    else
        larger = val2;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}

void Larger3(int val, int val2, int* larger)
{
	LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
	if (val > val2)
        *larger = val;
    else
        *larger = val2;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}

















