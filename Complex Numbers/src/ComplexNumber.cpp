#include <iostream>
#include "ComplexNumber.h"

using namespace std;

/**
 * ComplexNumber creates and manipulates complex numbers.
 *
 * <p>Bugs: istream doesn't take in a second complex number
 *
 * @author Cory Jonet
 */

//Constructors

/**
 * Simple no argument constructor
 *
 */

ComplexNumber::ComplexNumber() :
  real(0.0), imag(0.0) 
{

}

/**
 * Complex argument constructor
 *
 * @param real_part Real part of the complex number
 * @param imaginary_part Imaginary part of the complex number
 */

ComplexNumber::ComplexNumber(double real_part, double imaginary_part) :
  real(real_part), imag(imaginary_part)
{

}

/**
 * Copy constructor
 *
 * @param rhs The complex number to copy to this complex number
 */

ComplexNumber::ComplexNumber(const ComplexNumber & rhs) :
  real(rhs.real), imag(rhs.imag)
{
  
}

// named member functions

/**
 * Prints a complex number to console in the form of <real> + <imaginary>i
 *
 * @param out The output
 */

void ComplexNumber::print(ostream & out) const
{
  out << real << " + " << imag;
}

/**
 * Equals determines if this complex number if equal to that complex number
 *
 * @param rhs The complex number to compare to this complex number
 * @return true if equal, otherwise false
 */

bool ComplexNumber::equals(const ComplexNumber & rhs) const
{
  //If both real and imaginary parts are the same, they are equal
  if(real == rhs.real && imag == rhs.imag)
    {
      return true;
    }

  return false;
}

// Assignment operators

/**
 * Overloads assignment =
 *
 * @param rhs The complex number to copy to this complex number
 * @return This complex number with that complex number's fields
 */

const ComplexNumber & ComplexNumber::operator=(const ComplexNumber & rhs)
{
  
  //If the same, return this
  if(this == &rhs)
    {
      
      return *this;

    }

  //Else make this complex number the same as that complex number
  else
    {

      real = rhs.real;
      imag = rhs.imag;

    }

  return *this;
}

/**
 * Overloads assignment +=
 *
 * @param rhs The compled number to add to this complex number
 * @return Addition of this complex number to that complex number
 */

const ComplexNumber & ComplexNumber::operator+=(const ComplexNumber & rhs)
{

  real += rhs.real;
  imag += rhs.imag;

  return *this;
}

/**
 * Overloads assignment -=
 *
 * @param rhs The complex number to subtract from this complex number
 * @return This complex number minus that complex number
 */

const ComplexNumber & ComplexNumber::operator-=(const ComplexNumber & rhs)
{
  
  real -= rhs.real;
  imag -= rhs.imag;

  return *this;
}

/**
 * Overloads assignment *=
 *
 * @param rhs The complex number to multiply by this complex number
 * @return This complex number multiplied by that complex number
 */

const ComplexNumber & ComplexNumber::operator*=(const ComplexNumber & rhs)
{

  real *= rhs.real;
  imag *= rhs.imag;

  return *this;
}


// arithmetic operators

/**
 * Overloads +
 *
 * @param lhs The first complex number to add
 * @param rhs The second complex number to add
 * @return The complex number added to another complex number
 */

ComplexNumber operator+(const ComplexNumber & lhs, const ComplexNumber & rhs)
{

  ComplexNumber answer(lhs);
  
  answer += rhs;

  return answer;
}

/**
 * Overlaods - 
 *
 * @param lhs The complex number to be subtracted
 * @param rhs The complex number that subtracts
 * @return The complex number subtracted from another complex number
 */

ComplexNumber operator-(const ComplexNumber & lhs, const ComplexNumber & rhs)
{

  ComplexNumber answer(lhs);

  answer -= rhs;

  return answer;
}

/**
 * Overloads *
 *
 * @param lhs The first complex number to be multiplied
 * @param rhs The second complex number to be multiplied
 * @return The complex number multiplied by another complex number
 */

ComplexNumber operator*(const ComplexNumber & lhs, const ComplexNumber & rhs)
{

  ComplexNumber answer(lhs);

  answer *= rhs;

  return answer;
}

// relational operators

/**
 * Overloads ==
 *
 * @param lhs The first complex number to compare to the second complex number
 * @param rhs The second complex number to compare to the first complex number
 * @return true if both complex numbers are equal, false otherwise
 */

bool operator==(const ComplexNumber & lhs, const ComplexNumber & rhs)
{
  
  //Use related equals function
  if(lhs.equals(rhs))
    {
      return true;
    }

  return false;
}

/**
 * Overloads !=
 *
 * @param lhs The first complex number to compare to the second complex number
 * @param rhs The second complex number to compare to the first complex number
 * @return true if not equal, false otherwise
 */

bool operator!=(const ComplexNumber & lhs, const ComplexNumber & rhs)
{
  //Return opposite of ==
  return !(lhs == rhs);
}

// I/O operators

/**
 * Overloads <<
 *
 * @param out The output stream
 * @param n The complex number to print
 * @return The ouput
 */

ostream & operator<<(ostream & out, const ComplexNumber & n)
{

  n.print(out);

  return out;
}

/**
 * Overloads >>
 *
 * @param in The input stream
 * @param n The complex number to input into
 * @return The input
 */

istream & operator>>(istream & in, ComplexNumber & n)
{

  char ch; //Input character one at a time
  double realNum; //Real number to be read in
  double imagNum; //Imaginary number to be read in

  in.get(ch);

  while (ch == ' ' || ch == '\n' || ch == '\t')
    {
      in.get(ch);
    }

  in >> realNum;         // read in real value

  in.get(ch);

  while (ch == ' ' || ch == '\n' || ch == '\t')
    {
      in.get(ch);
    }
 
  if(ch != '+')
    {
      return in;
    }

  in >> imagNum;         // read in imaginary value

  while (ch == ' ' || ch == '\n' || ch == '\t')
    { 
      in.get(ch);
    }

  if(ch != 'i')
    {
      return in;
    }

  n = ComplexNumber(realNum, imagNum);

  return in;
}
