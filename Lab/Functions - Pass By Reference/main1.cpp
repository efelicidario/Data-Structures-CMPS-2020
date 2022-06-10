
#include "cmpslib19.h" // all the special functions provided for this class

#include "easylogging++.h"
INITIALIZE_EASYLOGGINGPP



// put your funtions here

void TripleInt(int & val)
{
	LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
	val *=3;
	LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}

void SmallerInt(const int & x, const int & y, int & result)
{
	LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
	if (x < y)
	result = x;
	else
	result = y;
	LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}

void LargerInt(int x, int y, int & result)
{
	LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
	if (x > y)
        result = x;
    else
        result = y;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}

void SwapInt(int & x, int & y)
{
	LOG(INFO) << "Start " <<  __PRETTY_FUNCTION__ << endl;
    int temp;
    temp = x;
    x = y;
    y = temp;
    LOG(INFO) << "End " <<  __PRETTY_FUNCTION__ << endl;
}


int main()
{
InitializeLogger("main1.log");



	cout <<"Testing TripleInt" << endl;
	int temp=1;
	TripleInt(temp);
	cout << PassFail(3 == temp) << endl; // (3 == temp) will ONLY be true if the function worked properly


	TripleInt(temp);
	cout << PassFail(9 == temp) << endl;// (9 == temp) will ONLY be true if the function worked properly


	temp =0;
	TripleInt(temp);
	cout << PassFail(0 == temp) << endl;// (27 == temp) will ONLY be true if the function worked properly


  temp = -5;
	TripleInt(temp);
	cout << PassFail(-15 == temp) << endl;// (81 == temp) will ONLY be true if the function worked properly


	// continue testing the rest of your functions

	
	cout <<"\nTesting SmallerInt" << endl;
	int smaller;
	SmallerInt(4, 20, smaller);
	cout << PassFail(4 == smaller) << endl;

	SmallerInt(20, 4, smaller);
	cout << PassFail(4 == smaller) << endl;
	
    SmallerInt(-6, -9, smaller);
	cout << PassFail(-9 == smaller) << endl;
    
    SmallerInt(7, 20, smaller);
	cout << PassFail(7 == smaller) << endl;
   
	cout <<"\nTesting LargerInt" << endl;
	int larger;
    LargerInt(0, 100, larger);
    cout << PassFail(100 == larger) << endl;

    LargerInt(20, 19, larger);
    cout << PassFail(20 == larger) << endl;

    LargerInt(-100, 500, larger);
    cout << PassFail(500 == larger) << endl;

    LargerInt(88, 72, larger);
    cout << PassFail(88 == larger) << endl;

    cout <<"\nTesting SwapInt" << endl;
    int a = 9;
    int b = 6;
    SwapInt(a, b);
    cout << PF(6 == a && 9 == b) << endl;

    a = 4;
    b = 20;
    SwapInt(b, a);
    cout << PF(20 == a && 4 == b) << endl;

    a = 60;
    b = 3;
    SwapInt(a, b);
    cout << PF(3 == a && 60 == b) << endl;

    a = 10;
    b = 80;
    SwapInt(b, a);
    cout << PF(80 == a && 10 == b) << endl;




    return 0;
}
