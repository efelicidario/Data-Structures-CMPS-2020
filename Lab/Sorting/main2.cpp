#include "cmpslib19.h"

#include "easylogging++.h"
INITIALIZE_EASYLOGGINGPP

#include "functions.h"

void PrintArray(int*v,int size)
  {
  std::cout << "Array: ";
  for (int loop =0; loop<size; loop++)
    {
    std::cout << v[loop] << ",";
    }
  std::cout << endl;
  }


int main()
  {
  InitializeLogger("main2.log");


  int testarray1[]= { 5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,100,95};
  int testarray2[]= { 5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,100,95};
  int testarray3[]= { 5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,100,95};


  int Sort1_comparisons=0;
  int Sort2_comparisons=0;
  int Sort3_comparisons=0;


  Sort1_comparisons = Sort1(testarray1,20);
  Sort2_comparisons = Sort2(testarray2,20);
  Sort3_comparisons = Sort3(testarray3,20);

  cout << "Is testarray1 sorted:" << IsSortedAscending(testarray1,20) << endl;
  PrintArray(testarray1,20);
  cout << "Is testarray2 sorted:" << IsSortedAscending(testarray2,20) << endl;
  PrintArray(testarray2,20);
  cout << "Is testarray3 sorted:" << IsSortedAscending(testarray3,20) << endl;
  PrintArray(testarray3,20);


  cout << "Sort1 required " << Sort1_comparisons << " comparisons to complete the sort"<< endl;
  cout << "Sort2 required " << Sort2_comparisons << " comparisons to complete the sort"<< endl;
  cout << "Sort3 required " << Sort3_comparisons << " comparisons to complete the sort"<< endl;


  return 0;
  }




