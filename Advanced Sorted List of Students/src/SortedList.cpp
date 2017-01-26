
/*******************************************************************************
Author:        Cory Jonet
CS Login:      jonet

Course:         CS 368, Fall 2013
Assignment:     Programming Assignment 3
*******************************************************************************/

#include "SortedList.h"
#include <iostream>
#include <stdlib.h>
#include <assert.h>

using namespace std;

int numStudents; //Number of students in list

/**
 * This class constructs a student database and allows to add, delete, find, and * print a student.
 *
 * <p>Bugs: None known
 *
 * @author Cory Jonet
 */


/**
 * Constructs an empty list
 */

SortedList::SortedList() : 
  head(new Listnode)
{

  numStudents = 0;

}

/**
 * Copy Constructor: Copies S SortedList to this SortedList using an auilixary f * unction called copyList
 *
 * @param S The SortedList to copy from to this SortedList
 */

SortedList::SortedList(const SortedList &S) :
  head(S.head)
{

  copyList(head);

}

/**
 * Destructor: Destructs this SortedList using an auxiliary function called free * List
 */

SortedList::~SortedList()
{

  freeList(head);

}

/**
 * Assignment Operator: The assignment operator is used by <SortedList1> = <Sort * edList2> where <SortedList1> will get the info from <SortedList2>. The assign * ment operators use auxiliary functions freeList and copyList
 *
 * @param L The SortedList to be copied from
 * @return This SortedList with info from L SortedList
 */

SortedList & SortedList::operator=(const SortedList &L)
{
  //If both SortedLists are already equal
  if(this == &L)
    {

      return *this;

    }

  //If both SortedLists aren't equal
  else
    {

      freeList(head);
      copyList(head);

      return *this;

    }
}

/**
 * freeList: The freeList auxiliary function deallocates the memory from every L * istnode in L
 *
 * @param L The pointer to the Linked List
 */

void SortedList::freeList(Listnode *L)
{

  //While the pointer to the list isn't NULL
  while(L != NULL)
    {

      struct Listnode *curr = L; //Temporary pointer

      L = L->next;

      delete(curr);

    }
}

/**
 * copyList: The copyList auxiliary function that copies all nodes from L into a * new SortedList and returns the new SortedList
 *
 * @param L The pointer from the SortedList to be copied from
 * @return The new SortedList will nodes from L
 */

SortedList::Listnode* SortedList::copyList(Listnode *L)
{

  //If the list to copy is NULL
  if(L == NULL)
    {

      return NULL;

    }

  SortedList *newList = new SortedList(); //The new SortedList

  newList->head->student = L->student;
  newList->head->next = NULL;
  
  struct Listnode *curr = newList->head; //Temporary pointer

  //While the pointer to the list isn't NULL
  while(L != NULL)
    {

      curr->next = (Listnode*) malloc(sizeof(Listnode));
      curr = curr->next;
      curr->student = L->student;

      L = L->next;
      
    }

  return newList->head;
}

/**
 * If a student with the same ID is not already in the list, inserts
 * the given student into the list in the appropriate place and returns
 * true.  If there is already a student in the list with the same ID
 * then the list is not changed and false is returned.
 
 *
 * @param s The Student to be inserted into the list
 * @return True if student successfully added, false otherwise
 */

bool SortedList::insert(Student *s)
{

  struct Listnode *newestNode = (Listnode*) malloc(sizeof(Listnode)); //Temporary node that holds the student info or to be free later
  struct Listnode *curr = head; //Temporary node pointer

  //Assign the node's fields with the student's info
  newestNode->student = s;
  newestNode->next = NULL;

  //While head's next value isn't NULL (i.e. this node isn't the end of the list)
  while(curr->next != NULL)
    {
      
      //If this node has the same student
      if(curr->student->getID() == s->getID())
        {

          free(newestNode);
	  free(curr);

          return false;
        }
      
      //Else if the next node's student name is greater than the one we're looking for, place the new student between the current and next node
      else if(curr->next->student->getID() > s->getID())
	{
	  newestNode->next = curr->next;
	  curr->next = newestNode;

	  free(curr);

	  numStudents++;

	  return true;
	}
	 
      curr = curr->next;

    }

  //If the node is the only one in the list and it isn't the same student
  if(curr->next == NULL && (curr->student->getID() != s->getID()))
    {
      curr->next = newestNode;
      head = curr;
      
      free(curr);

      numStudents++;

      return true;
    }
 
  return false;
}


/* Searches the list for a student with the given student ID.  If the
 * student is found, it is returned; if it is not found, NULL is returned.
 *
 * @param studentID The ID of the student
 * @return The student if found, else NULL
 */

Student *SortedList::find(int studentID)
{

  struct Listnode *curr = head; //Temporary node pointer

  //While head's next value isn't NULL (i.e. this node isn't the end of the list)
  while(curr->next != NULL)
    {
      //If this node is the student
      if(curr->student->getID() == studentID)
        {

          return curr->student;

        }

      curr = curr->next;

    }

  free(curr);

  //If the student wasn't found 
  return NULL;
}


/**
 * Searches the list for a student with the given student ID.  If the
 * student is found, the student is removed from the list and returned;
 * if no student is found with the given ID, NULL is returned.
 * Note that the Student is NOT deleted - it is returned - however,
 * the removed list node should be deleted.
 *
 * @param studentID The ID of the student we're looking to remove
 * @return The student with studentID we were looking to remove
 */

Student *SortedList::remove(int studentID)
{

  struct Listnode *tempNode = (Listnode*) malloc(sizeof(Listnode)); //Temporary node used to free the node's memory later

  struct Listnode *curr = head; //Temporary node pointer

  Student *retStudent = (Student*) malloc(sizeof(Student)); //The student we're returning
  

  //While head's next value isn't NULL (i.e. this node isn't the end of the list)
  while(curr->next != NULL)
    {
      //If first node in the list or the only node in the list
      if(curr->student->getID() == studentID)
        {
          tempNode = curr;
	  
	  //If not the only node in the list but is the first node
	  if(curr->next != NULL)
	    {
	      curr = curr->next;
	      head = curr;

	      retStudent = tempNode->student;

	      free(tempNode);
	      free(curr);

	      numStudents--;

	      return retStudent;
	    }

	  //If the only node in the list
	  else
	    {
	      curr = NULL;
	      head = curr;

	      retStudent = tempNode->student;

	      free(tempNode);
	      free(curr);

	      numStudents--;

	      return retStudent;
	    }

        }

      //Else it is in the middle of the list
      else if(curr->next->student->getID() == studentID)
	{
	  //Since the node is is the middle of the list, if the node after
	  //the one to be removed is not NULL...reassign
	  if(curr->next->next != NULL)
	    {
	      tempNode = curr->next;
	      curr->next = curr->next->next;
	      tempNode->next = NULL;

	      retStudent = tempNode->student;

	      free(tempNode);
	      free(curr);

	      numStudents--;

	      return retStudent;
	      
	    }

	  //If it's at the end of the list
	  else
	    {
	      tempNode = curr->next;
	      curr->next = NULL;

	      retStudent = tempNode->student;

	      free(tempNode);
	      free(curr);

	      numStudents--;

	      return retStudent;
	      
	    }
	}

      curr = curr->next;
    }

  free(tempNode);
  free(curr);

    //If all else, the removal failed
    return NULL;
}


// Prints out the student to standard output in the format:
//   ID,credits,GPA
// Note: the end-of-line is NOT printed after the student information

void SortedList::print() const
{
  struct Listnode *curr = head; //Temporary node pointer

  while(curr->next != NULL)
    {

      curr->student->print();
      cout << endl;

      curr = curr->next;
    }
 free(curr);
}


// Prints out the list of students to standard output.  The students are
// printed in order of student ID (from smallest to largest), one per line
