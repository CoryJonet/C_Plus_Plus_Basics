#include <iostream>
#include "ComplexNumber.h"

/**
 * Creates and manipulates two complex numbers
 *
 * <p>Bugs: istream doesn't take in the second complex number
 *
 * @author Cory Jonet
 */

using namespace std;

/**
 * Main function that runs ComplexNumber
 *
 * @return 0 if it worked, 1 otherwise
 */

int main() 
{

  cout << "Enter a complex number C1:" << endl;

  //Create first complex number
  ComplexNumber C1;
  cin >> C1;

  cout << "Enter a complex number C2:" << endl;

  //Create second complex number
  ComplexNumber C2;
  cin >> C2;

  cout << "For C1 = " << C1 << " and C2 = " << C2 << "i" << " : C1 + C2 = " << (C1 + C2) << "i" << endl;

  cout << "C1 - C2 = " << (C1 - C2) << "i" << endl;

  cout << "C1 * C2 = " << (C1 * C2) << "i" << endl;

  cout << "C1 == C2 is : " << (C1 == C2) << endl;

  cout << "C1 != C2 is : " << (C1 != C2) << endl;

  cout << "After C1 += C2, C1 = " << (C1 += C2) << "i" << endl;

  cout << "After C1 -= C2, C1 = " << (C1 -= C2) << "i" << endl;

  cout << "After C1 *= C2, C1 = " << (C1 *= C2) << "i" << endl;

  return 0;
}
