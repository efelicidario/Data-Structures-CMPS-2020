/*
   All rights reserved. No part of this document may be reproduced, distributed,   or transmitted in any form or by any means,    including photocopying,             recording, or other electronic or mechanical methods, without the prior         written    permission of the author, Michael Sarr
   */
#pragma once
#include "cmpslib19.h"
#include "Shape.h"

class Line: public Shape
{
    protected:
        double length;

    public:
        Line();
        ~Line();
        Line(double );
        void SetLength(double );
        string ToString();

};

Line::Line()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    length = 0;
    shape_type = 1;
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
}

Line::~Line()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
}


Line::Line(double val)
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    SetLength(val);
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
}

void Line::SetLength(double val)
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    if(val < 0)
        length = 0;
    else
        length = val;
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
}

string Line::ToString()
{
    LOG(INFO) << "Start " << __PRETTY_FUNCTION__ << endl;
    string result;
    result += "Line: \nLength: " + NumberToString(length) + "\nArea: " + NumberToString(Area()) + "\nVolume: " + NumberToString(Volume()) + "\n";
    LOG(INFO) << "End " << __PRETTY_FUNCTION__ << endl;
    LOG(INFO) << "Returning " << result << endl;
    return result;
}
