#include "cmpslib19.h"

// INCLUDE THE LIBRARY FOR THE LOGGING FUNCTIONS AND THE MACRO TO INITIALIZE IT

#include "easylogging++.h"
INITIALIZE_EASYLOGGINGPP



#include "fraction.h"
#include "template_class.h"


int main()
{
    InitializeLogger("main1.log");

    demo<int> a;
    demo<double> b;
    demo<string> c;
    demo<CFraction> d;

    cout << "Testing with type int" << endl;
    cout << "a.setData(99)" << endl;
    a.setData(99);
    cout << "a.getData() returns: " << a.getData() << endl;
    cout << "cout << a" << endl;
    cout << a << endl;

    cout << "Testing with type double" << endl;
    cout << "b.setData(99.99)" << endl;
    b.setData(99.99);
    cout << "b.getData() returns: " << b.getData() << endl;
    cout << "cout << b" << endl;
    cout << b << endl;

    cout << "Testing with type string" << endl;
    cout << "c.setData(\"monkey\")" << endl;
    c.setData("monkey");
    cout << "c.getData() returns: " << c.getData() << endl;
    cout << "cout << c" << endl;
    cout << c << endl;

    cout << "Testing with type fraction" << endl;
    cout << "d.setData(CFraction(1, 3))" << endl;
    d.setData(CFraction(1, 3));
    cout << "d.getData() returns: " << d.getData() << endl;
    cout << "cout << d" << endl;
    cout << d << endl;


    return 0;
}
