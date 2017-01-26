#include "Student.h"
#include <iostream>

using namespace std;

/**
 * This class constructs a student object with fields studentID, GPA, and credit * s
 *
 * <p>Bugs: None known
 *
 * @author Cory Jonet
 */


/**
 * Constructs a default student with an ID of 0, 0 credits, and 0.0 GPA.
 *
 */

Student::Student() :
  studentID(0), credits(0), GPA(0.0)
{

}


/**
 * Constructs a student with the given ID, 0 credits, and 0.0 GPA
 *
 * @param ID The ID of the student
 */

Student::Student(int ID) :
  studentID(ID), credits(0), GPA(0.0)
{

}


/**
 * Constructs a student with the given ID, number of credits, and GPA
 *
 * @param ID The ID of the student
 * @param cr The number of credits the student has earned
 * @param grPtAv The grade point average the student has earned
 */

Student::Student(int ID, int cr, double grPtAv) :
  studentID(ID), credits(cr), GPA(grPtAv)
{
  
}


// Accessors

/**
 * Accessor method that obtains the ID of the current student being looked at
 *
 * @return The ID of the current student being looked at
 */

int Student::getID() const
{
  return this->studentID;
}

/**
 * Accessor method that obtains the credits of the current student being looked  * at
 *
 * @return The credits of the student being looked at
 */

int Student::getCredits() const
{
  return this->credits;
}
// returns the number of credits

/**
 * Accessor method that obtain the GPA of the current student being looked at
 *
 * @return The GPA of the current student being looked at 
 */

double Student::getGPA() const
{
  return this->GPA;
}   
// returns the GPA

// Other methods

/**
 * // Updates the total credits and overall GPA to take into account the
// additions of the given letter grade in a course with the given number
// of credits.  The update is done by first converting the letter grade
// into a numeric value (A = 4.0, B = 3.0, etc.).  The new GPA is
// calculated using the formula:
//
//            (oldGPA * old_total_credits) + (numeric_grade * cr)
//   newGPA = ---------------------------------------------------
//                        old_total_credits + cr
//
 * Finally, the total credits is updated (to old_total_credits + cr)
 *
 * @param grade The letter grade of the course in char form
 * @param cr The number of credits of the course
 */

void Student::update(char grade, int cr)
{
  
  double gradeInt = 0.0; //The double form letter grade
  double newGPA = 0.0; //The new GPA

  //Converting the grade from char to double
  switch(grade)
    {
    case 'A':
      gradeInt = 4.0;
      break;

    case 'B':
      gradeInt = 3.0;
      break;

    case 'C':
      gradeInt = 2.0;
      break;

    case 'D':
      gradeInt = 1.0;
      break;

    case 'F':
      gradeInt = 0.0;
      break;
    }
  
  //The new GPA calculation
  newGPA = (((getGPA() * getCredits()) + (gradeInt * cr)) / (getCredits() + cr));

}

/**
*    Prints out the student to standard output in the format:
*    ID,credits,GPA
*    Note: the end-of-line is NOT printed after the student information
*
*/

void Student::print() const
{
  cout << studentID << "," << credits << "," << GPA;
}
  
// Prints out the student to standard output in the format:
//   ID,credits,GPA
// Note: the end-of-line is NOT printed after the student information 



