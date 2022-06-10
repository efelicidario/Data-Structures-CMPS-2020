#include "cmpslib19.h"
#include "easylogging++.h"
INITIALIZE_EASYLOGGINGPP

#include "Square.h"
#include "Triangle.h"



int main()
{
    InitializeLogger("main1.log");

    //------------------------------------------------------------------


    LOG (INFO) << "testing the Square class \n";

    if (true)
    {
        // test Square class
        cout << "create a Square named a, use the default constructor" << endl;
        Square a;
        cout << "a.ToString() returns: " << a.ToString() << endl;
        cout << "use the SetLength function to set a with the value -3.0" << endl;
        a.SetLength(-3.0);
        cout << "a.ToString() returns: " << a.ToString() << endl;
        cout << "use the SetLength function to set a with the value 3.5" << endl;
        a.SetLength(3.5);
        cout << "a.ToString() returns: " << a.ToString() << endl;


        cout << "create a Square named b, use the parameterized constructor to create one with the initial value of 44" << endl;
        Square b(44);
        cout << "b.ToString() returns: " << b.ToString() << endl;


    }

    LOG (INFO) << "finished testing the Square class \n\n\n\n";

    LOG (INFO) << "testing the Triangle class \n";
    if (true)
    {
        //test Triangle class
        cout << "create a Triangle named c, use the default constructor" << endl;
        Triangle c;
        cout << "c.ToString() returns: " << c.ToString() << endl;
        cout << "use the SetLength function to set c with the value -3.0" << endl;
        c.SetLength(-3.0);
        cout << "c.ToString() returns: " << c.ToString() << endl;
        cout << "use the SetLength function to set c with the value 3.5" << endl;
        c.SetLength(3.5);
        cout << "c.ToString() returns: " << c.ToString() << endl;
        cout << "use the SetHeight function to set c with the value -9" << endl;
        c.SetHeight(-9);
        cout << "c.ToString() returns: " << c.ToString() << endl;
        cout << "use the SetHeight function to set c with the value 9.5" << endl;
        c.SetHeight(9.5);
        cout << "c.ToString() returns: " << c.ToString() << endl;


        cout << "create a Triangle named d, use the parametereized constructor to create it with the initial length of 3 and a height of 9" << endl;        Triangle d(3, 9);
        cout << "d.ToString() returns: " << d.ToString() << endl;


    }
    LOG (INFO) << "finished testing the Triangle class \n\n\n\n";



    //------------------------------------------------------------------


    return 0;
}
