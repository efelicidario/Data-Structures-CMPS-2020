
#include "cmpslib19.h"
// INCLUDE THE LIBRARY FOR THE LOGGING FUNCTIONS AND THE MACRO TO INITIALIZE IT

#include "easylogging++.h"
INITIALIZE_EASYLOGGINGPP


// include the standard template library stack

//#include <stack>
#include "fraction.h"
#include "Stack.h"

// lets define ELEMTYPE  as the type we want our stack to hold

// we want to be sure it is defined defalut to be some known type


#ifndef ELEMTYPE  // only do the following define if its not already defined

#define ELEMTYPE  int
#endif


void ShowMenu()
{

    cout<< "   Stack Menu \n";
    cout << "  ===============================================\n";
    cout << "  i  Push a value into the stack \n";
    cout << "  d  Pop a value from the stack \n";
    cout << "  t  Display the value returned by top() \n";
    cout << "  e  Display the value returned by empty() \n";
    cout << "  f  Display the value returned by full()\n";
    cout << "  s  Display the value returned by size()\n";
    cout << "  c  Display the value returned by capacity()\n";
    cout << "  p  Display the value returned by ToString()\n";
    cout << "  m  Show this menu \n";
    cout << "  x  Exit \n";
    cout << "  ===============================================\n";

}


int main()
{
    InitializeLogger("main1.log");




    // create an stl::mystack

    // this is the only time you should use any stl containers

    Stack<ELEMTYPE> mystack;

    char selection;
    ELEMTYPE elem;

    // Initialize the stack before the menu loop


    ShowMenu();
    do
    {
        // the Prompt function is defined in cmpslib19.h you can use it for any datatype

        // if you need to have the user input a value in one of the menu driven mains use this function instead of

        // using cin
        Prompt("Enter menu option: ",selection);
        cout << "\nOption " << selection << " chosen\n";
        try
        {
            switch(selection)
            {
                case 'i':
                    Prompt("Enter element to Push into the stack: ", elem);
                    if (mystack.Push(elem) == true)
                        cout << elem << " was added." << endl;
                    else
                        cout << elem << " was NOT added." << endl;
                    break;

                case 'd':
                    if(mystack.Pop() == true)
                        cout << "a value was popped from the stack." << endl;
                    else
                        cout << "could not pop a value." << endl;
                    break;

                case 't':
                    cout << "the Top function returned " << mystack.Top() << endl;
                    break;

                case 'e':
                    if(mystack.Empty() == true)
                        cout << "true" << endl;
                    else
                        cout << "false" << endl;
                    break;

                case 'f':
                    if(mystack.Full() == true)
                        cout << "true" << endl;
                    else
                        cout << "false" << endl;
                    break;

                case 's':
                    cout << mystack.Size() << endl;
                    break;

                case 'c':
                    cout << mystack.Capacity() << endl;
                    break;

                case 'p':
                    cout << mystack.ToString() << endl;
                    break;

                case 'm':
                    ShowMenu();
                    break;

                case 'x':
                    cout << "Goodbye.\n";
                    break;

                default:
                    cout << "Invalid menu option!\n";
            }
        }
        catch (const char * exc )
        {
            cout <<"Exception:"<< exc << endl;

        }
    }
    while(selection != 'x');

}

