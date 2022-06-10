/*
   All rights reserved. No part of this document may be reproduced, distributed,   or transmitted in any form or by any means,    including photocopying,             recording, or other electronic or mechanical methods, without the prior         written    permission of the author, Michael Sarr
   */
#pragma once
#include "cmpslib19.h"
#include "Line.h"

class Rectangle:public Line
{
    protected:
        double width;

    public:
        Rectangle();
        ~Rectangle();
        Rectangle(double , double );
        void SetWidth(double );
        double Area();
        string ToString();

};

Rectangle::Rectangle():Line()
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    width = 0;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}

Rectangle::~Rectangle()
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}

Rectangle::Rectangle(double x, double y):Line(x)
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    width = y;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}

void Rectangle::SetWidth(double val)
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    if(val < 0)
        width = 0;
    else
        width = val;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}

double Rectangle::Area()
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    double area; 
    area = length * width;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning " << area << endl;
    return area;
}

string Rectangle::ToString()
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    string result;
    result += "Rectangle: \nLength: " + NumberToString(length) + "\nWidth: " + NumberToString(width) + "\nArea: " + NumberToString(Area()) + "\nVolume: 0\n";
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning " << result << endl;
    return result;
}
