/*
	 All rights reserved. No part of this document may be reproduced, distributed,   or transmitted in any form or by any means,    including photocopying,             recording, or other electronic or mechanical methods, without the prior         written    permission of the author, Michael Sarr
 */
#pragma once
#include "cmpslib19.h"

class Shape
{
    protected:

    public:
        Shape();
        ~Shape();
        double Area();
        double Volume();
        string ToString();
        
        int shape_type;

};

Shape::Shape()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    shape_type = 0;
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
}

Shape::~Shape()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
}

double Shape::Area()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning " << 0 << endl;
    return 0;
}

double Shape::Volume()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning " << 0 << endl;
    return 0;
}

string Shape::ToString()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    string result;
    result += "Shape: \nArea: " + NumberToString(Area()) + "\nVolume: " + NumberToString(Volume()) + "\n";
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning " << result << endl;
    return  result;
}

