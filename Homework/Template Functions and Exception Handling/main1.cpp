#include "cmpslib19.h"


#include "easylogging++.h"
INITIALIZE_EASYLOGGINGPP



#include "functions.h"

int main()
{
    InitializeLogger("main1.log");

    // test that your functions work properly
    // make sure that they all work and do what they are supposed to do

    int a;
    double b;
    bool result;

    cout << "\n\nTesting function1 with int\n";
    try
    {
        cout << "Difference(25,20): ";
        a = Difference(25,20);
        cout << a  << endl;
    }
    catch (const char * val)
    {   cout << "\nException: " << val << endl;}

    try
    {
        cout << "Difference(25,30): ";
        a = Difference(25,30);
        cout << a  << endl;
    }
    catch (const char * val)
    {   cout << "\nException: " << val << endl;}


    cout << "\n\nTesting function1 with double\n";
    try
    {
        cout << "Difference(2.5,2.0): ";
        b = Difference(2.5,2.0);
        cout << b  << endl;
    }
    catch (const char * val)
    {   cout << "\nException: " << val << endl;}

    try
    {
        cout << "Difference(2.5,3.0): ";
        b = Difference(2.5,3.0);
        cout << b  << endl;
    }
    catch (const char * val)
    {   cout << "\nException: " << val << endl;}


    cout << "\n\nTesting function2 with int\n";
    try
    {
        cout << "Difference(9, 6): ";
        a = Difference(9, 6);
        cout << a << endl;
    }
    catch (const char * val)
    {   cout << "\nException: " << val << endl;}

    try
    {
        cout << "Difference(6, 9): ";
        a = Difference(6, 9);
        cout << a << endl;
    }
    catch (const char * val)
    {   cout << "\nException: " << val << endl;}


    cout << "\n\nTesting function2 with double\n";
    try
    {
        cout << "Difference(4.2, 2.4): ";
        a = Difference(4.2, 2.4);
        cout << a << endl;
    }
    catch (const char* val)
    {
        cout << "\nException: " << val << endl;
    }

    try
    {
        cout << "Difference(2.4, 4.2): ";
        a = Difference(2.4, 4.2);
        cout << a << endl;
    }
    catch (const char* val)
    {
        cout << "\nException: " << val << endl;
    }


    cout << "\n\nTesting function3 with int\n";
    try
    {
        cout << "IsBetween(5, 1, 10): ";
        a = IsBetween(5, 1, 10);
        if (a == true)
            cout << "true" << endl;
    }
    catch (const char* val)
    {
        cout << "\nException: " << val << endl;
    }

    try
    {
        cout << "IsBetween(37, 1, 10): ";
        a = IsBetween(1, 10, 37);
        if (true == result)
            cout << "true" << endl;
        else if (false == result)
            cout << "false"<< endl;
    }
    catch (const char* val)
    {
        cout << "\nException: " << val << endl;
    }

    try
    {
        cout << "\nIsBetween(5, 10, 1): ";
        a = IsBetween(5, 10, 1);
        if (a == true)
            cout << "true" << endl;
    }
    catch (const char* val)
    {
        cout << "\nException: " << val << endl;
    }


    cout << "\n\nTesting function3 with double\n";
    try
    {
        cout << "IsBetween(3.1, 2.1, 4.1): ";
        a = IsBetween(3.1, 2.1, 4.1);
        if (a == true)
            cout << "true" << endl;
    }
    catch (const char* val)
    {
        cout << "\nException: " << val << endl;
    }

    try
    {
        cout << "IsBetween(55.0, 10.0, 1.0): ";
        a = IsBetween(55.0, 10.0, 1.0);
        if (a == true)
            cout << "true" << endl;
    }
    catch (const char* val)
    {
        cout << "\nException: " << val << endl;
    }


    cout << "\n\nTesting function4 with int\n";
    try
    {
        cout << "IsBetween(2, 0, 4, result): ";
        IsBetween(2, 0, 4, result);
        if (true == result)
            cout << "true" << endl;
        else if (false == result)
            cout << "false" << endl;
    }
    catch (const char* val)
    {
        cout << "\nException: " << val << endl;
    }

    try
    {
        cout << "IsBetween(5, 10, 1, result): ";
        IsBetween(5, 10, 1, result);
        if (true == result)
            cout << "true" << endl;
        else if (false == result)
            cout << "false" << endl;
    }
    catch (const char* val)
    {
        cout << "\nException: " << val << endl;
    }


    cout << "\n\nTesting function4 with double\n";
    try
    {
        cout << "IsBetween(2.4, 3.4, 4.4, result): ";
        IsBetween(3.4, 2.4, 4.4, result);
        if (true == result)
            cout << "true" << endl;
    }
    catch (const char* val)
    {
        cout << "\nException: " << val << endl;
    }

    try
    {
        cout << "IsBetween(5.0, 10.0, 1.0, result): ";
        IsBetween(5.0, 10.0, 1.0, result);
        if (true == result)
            cout << "true" << endl;
    }
    catch (const char* val)
    {
        cout << "\nException: " << val << endl;
    }

    try
    {
        cout << "IsBetween(5.0, 10.0, 100.0, result): ";
        IsBetween(5.0, 10.0, 100.0, result);
        if (true == result)
            cout << "true" << endl;
        else if (false == result)
            cout << "false" << endl;
            
    }
    catch (const char* val)
    {
        cout << "\nException: " << val << endl;
    }




    return 0;
}









