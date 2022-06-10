/*
   All rights reserved. No part of this document may be reproduced, distributed,   or transmitted in any form or by any means,    including photocopying,             recording, or other electronic or mechanical methods, without the prior         written    permission of the author, Michael Sarr
 */
#pragma once
#include "cmpslib19.h"
#include "Square.h"

class Cube:public Square
{
    protected:

    public:
        Cube();
        ~Cube();
        Cube(double );
        double Area();
        double Volume();
        string ToString();

};

Cube::Cube():Square()
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}

Cube::~Cube()
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}


Cube::Cube(double x):Square(x)
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}

double Cube::Area()
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    double are = Square::Area() * 6;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning " << are << endl;
    return are;
}

double Cube::Volume()
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    double vol = (length * length * length);
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning " << vol << endl;
    return vol;
}

string Cube::ToString()
{
    LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    string result;
    result += "Cube: \nLength: " + NumberToString(length) + "\nArea: " + NumberToString(Area()) + "\nVolume: " + NumberToString(Volume()) + "\n";
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning " << result << endl;
    return result;
}
