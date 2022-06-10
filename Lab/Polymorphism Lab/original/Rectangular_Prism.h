/*
   All rights reserved. No part of this document may be reproduced, distributed,   or transmitted in any form or by any means,    including photocopying,             recording, or other electronic or mechanical methods, without the prior         written    permission of the author, Michael Sarr
   */
#pragma once
#include "cmpslib19.h"
#include "Rectangle.h"

class Rectangular_Prism: public Rectangle
{
    protected:
        double depth;

    public:
        Rectangular_Prism();
        ~Rectangular_Prism();
        Rectangular_Prism(double , double , double );
        void SetDepth(double );
        double Area();
        double Volume();
        string ToString();
};

Rectangular_Prism::Rectangular_Prism(): Rectangle()
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    depth = 0;
    shape_type = 5;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}

Rectangular_Prism::~Rectangular_Prism()
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}

Rectangular_Prism::Rectangular_Prism(double x, double y, double z): Rectangle(x, y)
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    depth = z;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}

void Rectangular_Prism::SetDepth(double val)
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    depth = val;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}

double Rectangular_Prism::Area()
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    double are; 
    are = 2 * (length * width) + 2 * (length * depth) + 2 * (width * depth);
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning " << are << endl;
    return are;
}

double Rectangular_Prism::Volume()
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    double vol;
    vol = depth * Rectangle::Area();
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning " << vol << endl;
    return vol;
}

string Rectangular_Prism::ToString()
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    string result;
    result += "Rectangular_Prism: \nLength: " + NumberToString(length) + "\nWidth: " + NumberToString(width) + "\nDepth: " + NumberToString(depth) + "\nArea: " + NumberToString(Area()) + "\nVolume: " + NumberToString(Volume()) + "\n";
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning " << result << endl;
    return result;
}
