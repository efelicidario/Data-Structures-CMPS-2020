/*
   All rights reserved. No part of this document may be reproduced, distributed,   or transmitted in any form or by any means,    including photocopying,             recording, or other electronic or mechanical methods, without the prior         written    permission of the author, Michael Sarr
   */
#pragma once
#include "cmpslib19.h"
#include "Line.h"

class Square:public Line
{
    protected:

    public:
        Square();
        Square(double );
        double Area();
        string ToString();

};

Square::Square(): Line()
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}

Square::Square(double x): Line(x)
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}

double Square::Area()
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    double area = length * length;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning " << area << endl;
    return area;
}

string Square::ToString()
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    string result;
    result += "Square: \nLength: " + NumberToString(length) + "\nArea: " + NumberToString(Area()) + "\nVolume: " + NumberToString(Volume()) + "\n";
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning " << result << endl;
    return result;
}
