#include "cmpslib19.h"
// INCLUDE THE LIBRARY FOR THE LOGGING FUNCTIONS AND THE MACRO TO INITIALIZE IT
#include "easylogging++.h"
INITIALIZE_EASYLOGGINGPP


#ifndef ELEMTYPE
#define ELEMTYPE int
#endif


#include "fraction.h"
#include "AVL.h"

void ShowMenu()
  {
  cout << "             Binary Search Tree\n";
  cout << "  ===============================================\n";
  cout << "  i  Insert a value into the tree                \n";
  cout << "  c  Does the tree contain a specific value      \n";
  cout << "  d  Delete a value from the tree                \n";
  cout << "  y  Print the values of the tree in pre order   \n";
  cout << "  p  Print the values of the tree in sorted order\n";
  cout << "  z  Print the values of the tree in post order  \n";
  cout << "  m  Show this menu                              \n";
  cout << "  x  Exit                                        \n";
  cout << "  ===============================================\n";
  }



int main()
  {

  // set up the logger
  InitializeLogger("main1.log"); // this is the name of the file the logging output will go to




  if (true)
    {
    AVL<ELEMTYPE> tree;
    ELEMTYPE elem;
    char  selection;

    // Initialize the tree before the menu loop
    ShowMenu();
    do
      {
      try
        {
        Prompt("  Enter selection: ",selection);
        cout << "\nOption " << selection << " chosen\n";
        LOG (INFO ) << "Option " << selection <<" chosen\n";


        switch(selection)
          {
          case 'x':
            cout << "Goodbye.\n";
            break;

          case 'm':
            ShowMenu();
            break;

          case 'i':
            Prompt("Enter element to insert into the tree: ",elem);
            if(tree.insert(elem))
              {
              cout << elem << " was added.\n";
              }
            else
              {
              cout << elem << " was NOT added.\n";
              }
            break;

          case 'c':
            Prompt("Enter element to look for: ", elem);
            if (tree.remove(elem) == true)
                cout << elem << " was found in the tree" << endl;
            else
                cout << elem << " was NOT found in the tree" << endl;
            break;

          case 'd':
            Prompt("Enter element to delete: ",elem);
            if(tree.remove(elem) == true)
              {
              cout << elem << " removed from the tree.\n";
              }
            else
              {
              cout << "Could not remove " << elem << " from the tree.\n";
              }
            break;

          case 'y':
            tree.printPre();
            break;

          case 'p':
            tree.print();
            break;

          case 'z':
            tree.printPost();
            break;

          //_ESR
          default:
            cout << "Invalid menu option!\n";

          }
        }
      catch (const char * msg)
        {
        cout << "Exception Cought: " << msg << endl;
        }

      }
    while(selection != 'x');
    }

  }



