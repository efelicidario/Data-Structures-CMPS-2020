#include "cmpslib19.h"
// INCLUDE THE LIBRARY FOR THE LOGGING FUNCTIONS AND THE MACRO TO INITIALIZE IT
#include "easylogging++.h"
INITIALIZE_EASYLOGGINGPP


#ifndef ELEMTYPE
#define ELEMTYPE int
#endif


#include "fraction.h"
#include "BST.h"

void ShowMenu()
  {
  cout << "             Binary Search Tree\n";
  cout << "  ===============================================\n";
  cout << "  i Insert a value into the tree                \n";
  cout << "  d Delete a value from the tree                \n";
  cout << "  p Print the values of the tree in sorted order\n";
  cout << "  m Show this menu\n";
  cout << "  x Exit                                        \n";
  cout << "  ===============================================\n";
  }



int main()
  {

  // set up the logger
  InitializeLogger("main1.log"); // this is the name of the file the logging output will go to




  if (true)
    {
    BST<ELEMTYPE> tree;
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


          case 'd':
            Prompt("Enter element to delete: ",elem);
            if(tree.remove(elem))
              {
              cout << elem << " removed from the tree.\n";
              }
            else
              {
              cout << "Could not remove " << elem << " from the tree.\n";
              }
            break;

          case 'p':
            tree.print();
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



