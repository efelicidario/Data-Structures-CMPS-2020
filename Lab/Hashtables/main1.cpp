// Purpose: HW 7 Hash Tables
//          This implements a static sized array-based hash table that uses
//          double hashing for collision resolution. The double hashing probe
//          sequence is hash1 , hash 2


#include <iostream>
#include <limits>
#include <string.h>
using namespace std;
#include "cmpslib19.h"

#include "easylogging++.h"
INITIALIZE_EASYLOGGINGPP


#include "Hash.h"

char menu();
int main()
{
    InitializeLogger("example1.log");





    HashTable h;  // Declare the table.
    char sel;
    int  num;

    do
    {
        try
        {
            sel = menu();
            switch(sel)
            {
                case 'i':
                    Prompt("Enter an integer: ", num);
                    h.insert(num);
                    cout << "Inserting " << num << " into the hash table." << endl;
                    cout << num << " inserted successfully." << endl;
                    break;

                case 'd':
                    Prompt("Enter an integer: ", num);
                    h.remove(num);
                    break;

                case 's':
                    Prompt("Enter an integer: ", num);
                    h.search(num);
                    break;

                case 'k':
                    Prompt("Enter an integer: ", num);
                    cout << "Primary key for " << num << " is " << h.hash1(num) << "\nSecondary key for " << num << " is " << h.hash2(num) << endl;
                    break;

                case 'p':
                    cout << h.ToString() << endl;
                    break;

                case 'x':
                    cout << "Good-bye!\n";
                    break;

                default:
                    cout << "Invalid selection!\n";
            }
        }
        catch(string val)
        {
            cout <<"Exception: " << val << endl;
        }


    }
    while(sel != 'x');

    return 0;
}

char menu()
{
    char sel;

    cout << endl;
    cout << "          Hash Table Menu\n";
    cout << "  ===================================\n";
    cout << "  i. Insert an integer into the table\n";
    cout << "  d. Delete an integer from the table\n";
    cout << "  s. Search the table for an integer \n";
    cout << "  k. Print the primary and secondary \n";
    cout << "     keys for an integer             \n";
    cout << "  p. Print HashTable                 \n";
    cout << "                                     \n";
    cout << "  x. Exit                            \n";
    cout << "  ===================================\n";
    Prompt("  Enter selection: ",sel);
    cout << endl;
    return sel;
}






