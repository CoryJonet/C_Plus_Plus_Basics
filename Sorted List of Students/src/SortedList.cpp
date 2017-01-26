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

	  free(curr);

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
