
#include "cmpslib19.h" // all the special functions provided for this class


#include "easylogging++.h"
INITIALIZE_EASYLOGGINGPP



#include "functions.h"


int main()
{
	InitializeLogger("main1.log");

	/*
		 test all your functions here
	 */

	cout <<"\nTesting TripleInt pbv" << endl;
	cout << PassFail(0 == TripleInt1(0)      ) << endl;
	cout << PassFail(5 != TripleInt1(5)      ) << endl;
	cout << PassFail(15 == TripleInt1(5)     ) << endl;
	cout << PassFail(-15 == TripleInt1(-5)   ) << endl;
	cout << PassFail(15 == TripleInt1(5.5)      ) << endl;

    
	cout <<"Testing TripleInt pbp" << endl;
    int temp = 0;
	TripleInt2(&temp);
	cout << PassFail( 0 == temp ) << endl;
	temp = -5;
	TripleInt2(&temp);
	cout << PassFail(-15 == temp  ) << endl;
	temp = 5;
	TripleInt2(&temp);
	cout << PassFail( 15 == temp )  << endl;
	temp=5.5;
	TripleInt2(&temp);
	cout << PassFail( 15 == temp )  << endl;

	// continue testing the rest of your functions

	cout << "Testing TripleInt pbr" << endl;
    temp = 0;
    TripleInt3(temp);
    cout << PF(0 == temp) << endl;
    temp = 5;
    TripleInt3(temp);
    cout << PF(15 == temp) << endl;
    temp = -5;
    TripleInt3(temp);
    cout << PF( -15== temp) << endl;
    temp = 5.5;
    TripleInt3(temp);
    cout << PF(15 == temp) << endl;
	
	cout << "\nTesting SwapInt pbp" << endl;
    int x = 6, y = 9;
    SwapInt1(&x, &y);
    cout << PF(9 == x && 6 == y) << endl;
    x = 20, y = 4;
    SwapInt1(&x, &y);
    cout << PF( 4 == x && 20 == y) << endl;
    x = 3, y = 60;
    SwapInt1(&x, &y);
    cout << PF( 60 == x && 3 == y) << endl;
    x = 80, y = 10;
    SwapInt1(&x, &y);
    cout << PF( 10 == x && 80 == y) << endl;

    cout << "Testing SwapInt pbr" << endl;
    x = -1, y = -2;
    SwapInt2(x, y);
    cout << PF(-2 == x && -1 == y) << endl;
    x = 0, y = 0;
    SwapInt2(y, x);
    cout << PF(0 == x && 0 == y) << endl;
    x = 5, y = -5;
    SwapInt2(x, y);
    cout << PF(-5 == x && 5 == y) << endl;
    x = -10, y = 100;
    SwapInt2(y, x);
    cout << PF(100 == x && -10 == y) << endl;

    cout << "\nTesting Larger pbv" << endl;
    cout << PF(2 == Larger1(1, 2)) << endl;
    cout << PF(4 == Larger1(4, 3)) << endl;
    cout << PF(6 == Larger1(5, 6)) << endl;
    cout << PF(8 == Larger1(8, 7)) << endl;

    cout << "Testing Larger pbr" << endl;
    int larger;
    x = 7, y = 20;
    Larger2(x, y, larger);
    cout << PF(20 == larger) << endl;
    x = 60, y = 3;
    Larger2(x, y, larger);
    cout << PF(60 == larger) << endl;
    x = 0, y = 90;
    Larger2(x, y, larger);
    cout << PF(90 == larger) << endl;
    x = 80, y = 1;
    Larger2(x, y, larger);
    cout << PF(80 == larger) << endl;

    cout << "Testing Larger pbp" << endl;
    x = 0, y = 5;
    Larger3(x, y, &larger);
    cout << PF(5 == larger) << endl;
    x = 15, y = 10;
    Larger3(x, y, &larger);
    cout << PF(15 == larger) << endl;
    x = 20, y = 25;
    Larger3(x, y, &larger);
    cout << PF(25 == larger) << endl;
    x = 35, y = 30;
    Larger3(x, y, &larger);
    cout << PF(35 == larger) << endl;
    cout << "\n";

	return 0;

}














