#include "Triangle.h"

Triangle::Triangle()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    SetHeight(0);
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
}

Triangle::Triangle(double length, double height)
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    SetLength(length);
    SetHeight(height);
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
}

Triangle::~Triangle()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
}

void Triangle::SetHeight(double val)
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    if(val < 0)
    {
        height = 0;
    }
    else
    {
        height = val;
    }
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
}

double Triangle::Area()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    double area = (0.5 * (length * height));
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    return area;
}

string Triangle::ToString()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    string result;
    result += "Triangle: Length = " + NumberToString(length) + " Height = " + NumberToString(height) + " Area = " + NumberToString(Area()) + "\n";
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    return result;
}
