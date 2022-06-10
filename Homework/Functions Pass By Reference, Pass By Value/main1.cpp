#include "cmpslib19.h" // all the special functions provided for use in this class



#include "easylogging++.h"
INITIALIZE_EASYLOGGINGPP



#include "functions.h"

int main()
{
    InitializeLogger("main1.log");


    int iResult;
    double dResult;

    std::cout << "\nTesting Function1PBV\n";
    iResult = Function1PBV(0,-10,10);// does it work when param1 is the middle value
    if (0 == iResult) // always put the constant value on the left hand side of == operator, best practice

        std::cout << "Pass" << endl;
    else 
        std::cout << "Fail" << endl;

    // the library ( in cmpslib.h ) function PF has a bool parmmeter and returns the c string "Pass" or "Fail" 
    // so this is the same code but shorter using the funtion PF

    iResult = Function1PBV(-50,10,50);// does it work when param2 is the middle value
    std::cout <<  PF(10 ==  iResult ) << endl;      // consant value on left of == NOT (iResult == -10)
    
    // test this function 2 more times
    // does it work when param3 is the middle value
    // what if 2 are the same

    iResult = Function1PBV(3, 1, 2);
    cout << PF(2 == iResult) << endl; 

    iResult = Function1PBV(4, 5, 6);
    cout << PF(5 == iResult) << endl; 

    std::cout << "\nTesting Function1PBR\n";
    Function1PBR(iResult,-10,10,3);
    std::cout << PF(3 == iResult ) << endl;// 3 is the ONLY correct answer

    // test this function 3 more times

    Function1PBR(iResult,0,-1,1);
    std::cout << PF(0 == iResult ) << endl;

    Function1PBR(iResult,0,105,205);
    std::cout << PF(105 == iResult ) << endl;

    Function1PBR(iResult,4,0,2);
    std::cout << PF(2 == iResult ) << endl;

    // Function2 has double parmeters instead of integers
    // comparing doubles can be problematic so there is a helper function in the cmpslib19.h 
    // that you should use

    std::cout << "\nTesting Function2PBV\n";
    dResult = Function2PBV(10.1,100.1,10.1,-1.10,100.1);
    std::cout << "NOTE: the function should return 219.3 and it appears to return " <<  dResult <<  endl;	
    std::cout <<  PF(219.3 == dResult)  << " ,this is why we dont want to use == to compare doubles here" <<  endl; // this will say fail even if the functtion returns 219.3
    std::cout <<  PF(VeryClose(219.3,dResult))  << " ,this is using the VeryClose function" <<  endl; // so to compare doubles use the function   "bool VeryClose(double, double)"

    // test this function 3 more times using VeryClose

    dResult = Function2PBV(1.1,1.2,1.3,1.4,1.5);
    cout << PF(VeryClose(6.5,dResult)) << endl;

    dResult = Function2PBV(0.2,0.4,0.6,0.8,1.0);
    cout << PF(VeryClose(3.0,dResult)) << endl;
    
    dResult = Function2PBV(-1.0,0.2,0.3,0.4,5.5);
    cout << PF(VeryClose(5.4,dResult)) << endl;
    
       std::cout << "\nTesting Function2PBR \n";
       Function2PBR(dResult,100.1,100.1,100.1,100.1,100.1);
       std::cout <<  PF(VeryClose(500.5,dResult) ) << endl;
    // test function 3 more times
    
    Function2PBR(dResult,200.1,200.2,200.3,200.4,200.5);
    cout << PF(VeryClose(1001.5,dResult)) << endl;

    Function2PBR(dResult,1.1,2.1,3.1,4.1,5.1);
    cout << PF(VeryClose(15.5,dResult)) << endl;
    
    Function2PBR(dResult,10.1,10.1,10.1,10.1,10.1);
    cout << PF(VeryClose(50.5,dResult)) << endl;
    
    double c =100.1;
    double b =200.2;
    double a =300.3;
    std::cout << "\nTesting Function3PBR \n";
    Function3PBR(a,b,c);
    // test them to make sure they are sorted now
    
    std::cout << PF( VeryClose(100.1,a)  && VeryClose( 200.2 ,b)  && VeryClose(300.3,c)  ) << endl; 
    
    //test function 2 more times
    b = 6.9;
    c = 4.2;
    a = 6.6;
    Function3PBR(a,b,c);
    cout << PF(VeryClose(4.2,a) && VeryClose(6.6,b) && VeryClose(6.9,c)) << endl;

    a = 1.01;
    b = 1.02;
    c = 1.03;
    Function3PBR(a,b,c);
    cout << PF(VeryClose(1.01,a) && VeryClose(1.02,b) && VeryClose(1.03,c)) << endl;

    return 0;
}







