#include "Square.h"
#include <string>

Square::Square()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    length = 0;
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
}

Square::Square(double val)
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    SetLength(val);
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
}

Square::~Square()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
}

void Square::SetLength(double val)
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    if(val < 0)
    {
        length = 0;
    }
    else
    {
        length = val;
    }
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
}

double Square::Area()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    double area = length * length;
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    return area;
}

string Square::ToString()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    string result;
    result += "Sqaure: Length = " + NumberToString(length) + " Area = " + NumberToString(Area()) + "\n";
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    return result;
}




