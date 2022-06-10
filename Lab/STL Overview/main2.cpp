#include <list> // include the listlibraray 
#include <iostream> // include the library for input/output streams   (cout, endl and such)
#include <algorithm>

using namespace std;

void PrintBackwards(string val)
{
    for (int x=val.length();x>=0;x--)
        cout <<val[x];
    cout << endl;
}




int main()
{
    // create a list to store Strings
    cout << "creating a string list" << endl;
    list<string> str;

    // add some Strings to the list we created
    cout << "adding values to the list" << endl;
    str.push_back("one");
    cout << "adding value one" << endl;
    str.push_back("two");
    cout << "adding value two" << endl;
    str.push_back("three");
    cout << "adding value three" << endl;
    str.push_back("four");
    cout << "adding value four" << endl;
    str.push_back("five");
    cout << "adding value five" << endl;

    
    // lets create an Iterator so we can step through the items
    cout << "creating an iterator" << endl;
    list<string> iterator;
    
    // set the iterator to point to the first item in the vector
    cout << "setting the iterator = to string.begin()" << endl;
    list<string>::iterator it = str.begin();
    
    // print out the item the iterator is pointing to
    cout << "our iterator points to the value " << *it << endl;
    
    // lets move our iterator to the next item in the vector
    // incrementing an iterator will make it move to the next item of in the container
    cout << "incrementing the iterator" << endl;
    it++;
    
    // print out the item the iterator is pointing to
    // use the * operator to "dereference" the iterator to get the value the iteratore points to
    cout << "our iterator now points to the value " << *it << endl;
    cout << "\n";
    cout << "\n";
   

    // ok lets try to print out all the items in the vector
    // set the iterator back to the front of the vector
    // print out the value
    // set the iterator back to the front of the vector
    // print out the value
    cout << "printing the items in the list front to back" << endl;
    for(list<string>::iterator it2 = str.begin();it2 != str.end();it2++)
    {
        cout << "   the iterator now points to " << *it2 << endl;
        cout << "   increment the iterator" << endl;
    }
    cout << "\n" << endl;
    
    
    cout << "create a reverse_iterator" << endl;
    cout << "printing the items in the list back to front" << endl;
    cout << "set our iterator to string.rbegin()  and use a while loop ( != string.rend() )" << endl;
    for(list<string>::reverse_iterator r_it = str.rbegin();r_it != str.rend();r_it++)
    {
        cout << "   the iterator now points to " << *r_it << endl;
        cout << "   increment the iterator" << endl;
    }
    
    
    cout << "using the provided function void PrintBackwards(string val)" << endl;
    cout << " use the for_each function to call it with" << endl;
    cout << " all the values in list" << endl;
    cout << "FORMAT: for_each( starting iterator, ending iterator, function name)" << endl;
    cout << "\n";
    //list<string>::iterator b_it = str.begin();
    //list<string>::iterator b_it2 = str.end();
    //for_each(b_it, b_it2, PrintBackwards(*b_it));
    for(list<string>::iterator b_it = str.begin();b_it != str.end();b_it++)
        PrintBackwards(*b_it);
    cout << "\n";

    return 0;

}


