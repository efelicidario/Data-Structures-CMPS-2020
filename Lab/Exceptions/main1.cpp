
#include "functions.h"
#include "cmpslib19.h"

int main()
{
    // since we are going to use a switch statement below lets create a few variables to use later 
    // we are not going to use any logging in this assignment so dont bother opening a log

    bool finished = false;
    //double d1;
    string s1;
    int int1,low,high, menu_choice;
    bool result;

    while (! finished)
    {  
        // start your try block here (when you are ready to start catching exceptions
        /* 
           prompt the user to enter a value then using if case statements 
           perform the requested opertions 
           DO THEM ALL WITHIN THHS ONE TRY BLOCK 
           use the functions Prompt function in the cmpslib.h file for user input
           */

        try
        {
            Prompt("\nSelect Option (1-3)\n1. PrintFile\n2. Test StrToInt\n3. Test StrToDbl\n4. PrintFile (repeat till success)\n5. Test IsBetween\n6. Exit\n",menu_choice,1,6);
            switch( menu_choice )
            {
                case 1:
                    // Prompt(string message_to_display, T & value_to_put_user_input); // the 2nd parmeter works for all types   
                    Prompt("Enter Filename: ",s1);
                    PrintFile(s1);
                    break;

                    // string erase

                case 2:
                    Prompt("Enter string to convert to integer: ", s1);
                    StrToInt(s1);
                    cout << "Success: " << StrToInt(s1) << endl;
                    break;

                case 3:
                    Prompt("Enter string to convert to double: ", s1);
                    StrToDbl(s1);
                    cout << "Success: " << StrToDbl(s1) << endl;
                    break;

                case 5:
                    Prompt("Enter value: ", int1);
                    Prompt("Enter low value: ", low);
                    Prompt("Enter high value: ", high);
                    if (true == IsBetween(int1, low, high))
                        cout << "true" << endl;
                    else if (false == IsBetween(int1, low, high))
                        cout << "false" << endl;
                    break;

                case 4:
                    result = false;
                    while (! result)
                    {
                        try
                        {
                            Prompt("Enter Filename: ", s1);
                            PrintFile(s1);
                            result = true;
                        }
                        catch (...)
                        {
                        }
                    }
                    break;

                case 6:
                    finished = true;
                    break;
            }
            cout << "\nAt the end of the try block, there must not have been any exceptions." << endl;
        }
        
        // end try when you add it
        // put all the catch blocks here when you are ready
        
        catch (const char* s1)
        {
            cout << "\nException caught of type string, val = either the file does not exist or you do not have read permissions to it." << endl;
        }
        
        catch (std::runtime_error const&)
        {
            cout << "\nException caught of type string, val = not a valid numeric value." << endl;
        }
        
        catch (int int1)
        {
            cout << "\nException caught of type int, val = 8675309" << endl;
        }
        
        catch (std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)
        {
            cout << "Exception caught of type int, val = the values of parameters 2 and 3 do not define a range." << endl;
        }


    }; // end while

    return 0;
}







