#include "Student.h"
#include "SortedList.h"
#include <iostream>

/**
 * Main function to test Student.cpp and SortedList.cpp. 
 *
 * DEMONSTRATING THE DIFFERENCE: When comparing Student.cpp to SortedList.cpp, i * t was obvious that the benefits of adding a desctructor, copy constructor, an * d copy assignment operator to the SortedList.cpp class. Why? Because an inst  * ance of Student could simply be compared or freed up whereas SortedList has t * o deallocate memory for every node, or copy the information for every node. 
 *
 * <p>Bugs: None known
 *
 * @author Cory Jonet
 */
int main(int argc, char *argv[])
{

  //Test SortedLists
  SortedList *list1 = new SortedList();
  SortedList *list2 = new SortedList();
  SortedList *list3 = new SortedList();
  SortedList *list4 = new SortedList();

  //Test Students
  Student *student1 = new Student();
  Student *student2 = new Student(906);
  Student *student3 = new Student(907, 12, 3.5);
  Student *student4 = new Student(908, 24, 3.2);

  //Test Student destructor
  delete(student1);

  //Test Student copy constructor
  Student *student5 = new Student(*student4);

  //Test Student copy assignment operator
  student3 = student4;



  //Test SortedList destructor
  list1->insert(student2);
  delete(list1);

  //Test SortedList copy constructor
  list2->insert(student3);
  SortedList *list5 = new SortedList(*list2);

  //Test SortedList copy assignment operator
  list4->insert(student4);
  
  list3 = list4;
  
}
