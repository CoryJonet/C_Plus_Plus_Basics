#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>

/**
 * This class creates a student database with each student's statistics
 * (student ID, number of credits, and GPA).
 *
 * <p>Bugs: The I/O is giving many errors and I'm not sure why...
 *
 * @author Cory Jonet
 */

using namespace std;

#define studentDB = 5000; //Size of student database

/**
 * The student struct defines a student with fields studID, numCredit, and gpa.
 */
typedef struct student {
  int studID; //Student ID
  int numCredit; //Number of credits
  double gpa; //GPA
}Student;

Student *database = new Student[5000]; //The database of student info
int studentDBLength = 0; //Number of students in the database


/**
 * addStudent searches the list for an entry with the given student ID. If there
   is no entry found, add the student. If there is a student ID in the list
   already, the list is unchanged.
 *
 * @param studentID The given student's ID
 * @param numCredits The number of credits for the given student
 * @param gPA The GPA of the given student
 */
void addStudent(int studentID, int numCredits, double gPA){

  //Loop through database looking for student
  for(int i = 0; i < studentDBLength; i++) {
    if(database[i].studID == studentID)
      {
	cout << "Error, student already in database.\n";
	return;
      }
  }

  //Create new student with stats and add to list
  student newStudent; //New student to add
  newStudent.studID = studentID;
  newStudent.numCredit = numCredits;
  newStudent.gpa = gPA;

  //Add new student at end of list
  database[studentDBLength - 1] = newStudent;
  studentDBLength++;

  return;
}

/**
 *  deleteStudent removes the given student with student ID. If there is no
 *  entry then the list is unchanged. Otherwise the student is deleted and
 *  another student takes the place from the end of the list.
   *
   * @param studentID The student ID of the given student
   */

void deleteStudent(int studentID){

  //Loop through database looking for student to delete
  for(int i = 0; i < studentDBLength; i++){
    if(database[i].studID == studentID){
      if(studentDBLength == 1)
	{
	  database[i].studID = 0;
	  database[i].numCredit = 0;
	  database[i].gpa = 0.0;
	  return;
	}
      
      //Add the student at the end of the database to the "gap"
      database[i] = database[studentDBLength];
      database[studentDBLength].studID = 0;
      database[studentDBLength].numCredit = 0;
      database[studentDBLength].gpa = 0;
      studentDBLength--; 

     return;
    }
  }
  return;
}

/**
 * updateStudent searches the list for the entry with the given student ID.
 * If the entry is found, the credits and overall GPA are taken into account
 * in the statistics.
   *
   * @param studentID The given student's ID
   * @param letterGrade The letter grade assigned to the student
   * @param courseCred The new course credits
   */

void updateStudent(int studentID, char letterGrade, int courseCred){

  //Loop through the database looking for the student to update
  for(int i = 0; i < studentDBLength; i++){

    //If student is a match, update their statistics
    if(database[i].studID == studentID){
      database[i].numCredit = (database[i].numCredit + courseCred);
      
      //Re-calculate GPA based on new credits and letter grade
      if(letterGrade == 'A'){
	database[i].gpa = ((courseCred / ((courseCred * 4) + database[i].numCredit)) + database[i].gpa);
	}
      else if(letterGrade == 'B'){
	database[i].gpa = ((courseCred / ((courseCred * 3) + database[i].numCredit)) + database[i].gpa);
	}
      else if(letterGrade == 'C'){
	database[i].gpa = ((courseCred / ((courseCred * 2) + database[i].numCredit)) + database[i].gpa);
        }
      else if(letterGrade == 'D'){
	database[i].gpa = ((courseCred / ((courseCred * 1) + database[i].numCredit)) + database[i].gpa);
	}
      else{
	database[i].gpa = ((courseCred / ((courseCred * 0) + database[i].numCredit)) + database[i].gpa);
	  }
    }
  }
}

/**
 * print prints the list in the format studentID, number of credits, and GPA 
 * separated by commas.
   *
   */

void print(){

  //Loop through database to print students and their respective info
  for(int i = 0; i < studentDBLength; i++){
    cout << "%d, ", "%d, ", "%f, \n", database[i].studID, database[i].numCredit,database[i].gpa;
  }
}

/**
 * The main method is the driver for the program. It loops through choices to
 * interact with database such as 'a' for add, 'u' for update, 'd' for delete
 * , 'p' for print, and 'q' for quit.
 *
 */
int main() {
  
  bool done = false; //Main loop
  char choice = NULL; //Main menu choice
  int credits = 0; //Number of credits entered
  double GPA = 0.0; //GPA entered
  int studentID = 0; //Student ID entered
  char grade = NULL; //Grade entered
  int studentDBLength = 0; //Number of students in the database

    cout << "Enter your commands at the > prompt:" << endl;
    while (!done) {
        cout << "> ";
        cin >> choice;

        switch (choice) {

            case 'a':

	        cin >> studentID >> credits >> GPA;
		
		//Input error checking
		if(studentID < 0 || credits < 0 || (GPA > 4.0 || GPA < 0.0)){
		  cout << "Invalid input.\n";
		  break;
		}

		addStudent(studentID, credits, GPA);

		break;

            case 'd': 
 
                cin >> studentID;  // read in the integer ID
	
		//Input error checking
		if(studentID < 0){
		  cout << "Invalid input.\n";
		  break;
		}
		
		deleteStudent(studentID);

                break;

	    case 'u':
	        cin >> studentID >> credits >> grade;
		
		//Input error checking
		if(studentID < 0 || credits < 0 || (grade != 'A' || grade != 'B'                  || grade != 'C' || grade != 'D' || grade != 'F'))
		  {
		    cout << "Invalid input.\n";
		    break;
		  }

		updateStudent(studentID, grade, credits);

	        break;

            case 'q':  

                done = true;
                cout << "quit" << endl;

		break;

            // If the command is not one listed in the specification, for the 
            // purposes of this assignment, we will ignore it.  Note that you 
            // will see multiple ?'s printed out if there is additional 
            // information on the line (in addition to the unknown command 
            // character).  
            default: break;
        } // end switch

    } // end while

    return 0;
}
