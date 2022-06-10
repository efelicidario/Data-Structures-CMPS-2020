#include <vector> // include the vector libraray 
#include <iostream> // include the library for input/output streams   (cout, endl and such)
#include <algorithm> // for the random_shuffle and sort
#include <ctime> // to seed the random number generator


using namespace std;

int main()
{

    // create a vector to store Integers
    cout  << "creating an integer vector" << endl;
    vector<int> vector1;

    // add values to the vector using the push_back function
    int vec = 10;
    cout  << "adding values to the vector" << endl;
    for(int loop=0;loop<5;loop++)
    {
        vector1.push_back(vec);
        cout << "adding value " << vec << endl;
        vec = vec + 10;
    }

    // test the size function
    cout << "calling size function" << endl;
    cout << "size returns "  << vector1.size() << endl;
    cout << "\n";
    cout << "\n";

    // create and iterator
    cout << "creating a standard vector::iterator" << endl;
    vector<int> iterator;
    cout << "setting the iterator = to vector.begin()" << endl;
    vector<int>::iterator it = vector1.begin();
    cout << "our iterator points to the value " << *it << endl;
    cout << "incrementing the iterator" << endl;
    it++;
    cout << "our iterator now points to the value " << *it << endl;
    cout << "\n";
    cout << "\n";

    // print out the value
    cout << "printing the items in the vector front to back" << endl;
    cout << "set our iterator to vector.begin()  and use a while loop ( != vector.end() )" << endl;
    vector<int>::iterator it2 = vector1.begin();
    while(it2 != vector1.end())
    {
        cout << "   the iterator now points to " << *it2 << endl;
        cout << "   increment the iterator" << endl;
        it2++;
    }
    cout << "\n";

    // test the [ ] operator
    cout << "Vector also has an overloaded [] operator" << endl; 
    cout << "use a for loop and print out the elements of the vector via the index operator" << endl;
    for(long unsigned int loop =0;loop<vector1.size();loop++)
        cout << "myIntegerVector[" << loop << "] = " << vector1[loop] << endl;

    // shuffle and print
    cout << "use the random_shuffle algorithm to randomize the values in the vector (be sure to seed the random number generator)" << endl;
    srand(time(NULL));
    random_shuffle(vector1.begin(), vector1.end());
    cout << "use a for loop and print out the elements of the vector via the index operator" << endl; 
    for(long unsigned int loop=0;loop<vector1.size();loop++)
        cout << "myIntegerVector[" << loop << "] = " << vector1[loop] << endl;

    // sort and print
    cout << "use the sort algorithm to sort the vector" << endl;
    sort(vector1.begin(), vector1.end());
    cout << "use a for loop and print out the elements of the vector via the index operator" << endl;
    for(long unsigned int loop=0;loop<vector1.size();loop++)
        cout << "myIntegerVector[" << loop << "] = " << vector1[loop] << endl;
    cout << "\n";
    cout << "\n";






}

