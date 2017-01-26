#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <fstream>
#include <string>
#include <string.h>
#include <sys/stat.h>

using namespace std;

/**
 * Reads in a word and the name of a file from the command line. For our purposes * a word is any sequence of non-whitespace characters.
 *
 * <p>Bugs: None known
 *
 * @author Cory Jonet
 */

/**
 * Main method, takes in the parameters
 *
 * @param argv[] The arguments
 * @param argc The num of arguments
 * @return 0 if completed or 1 if failed
 */
int main(int argc, char *argv[]) 
{

  //If the arguments aren't correct
  if(argc != 3)
    {
      cout << "Proper usage: findWord <word> <file>" << endl;
      cout << "where" << endl;
      cout << "\t<word> is a sequence of non-whitespace characters" << endl;
      cout << "\t<file> is the file in which to search for the word" << endl;
      cout << "example: findWord the test.txt" << endl;

      return 1;
    }

  string word = argv[1]; //Word we're searching for
  char* inFile = argv[2]; //File to open

  FILE* fp = fopen(inFile, "r"); //Open the file

  int length = sizeof(*fp); //Length of the file

  //If the file pointer isn't NULL
  if(fp != NULL)
    {
      cout << "Searching for '" << word << "' in the file '" << inFile << "'" <<endl;
     
      int lineNum = 1; //Line numbers
      int count = 0; //Number of occurences of the word

      char textChar[length]; //The buffer being read into
      string text; //Converts from char*[] to string so we can use string functions
      int start; //Start of the first occurence (used in calculations to find multiple word occurences)
      string subString; //Substring used in finding multiple word occurences

      //Obtain line by line of text from the file and put it into textChar
      while(fgets(textChar, length, fp))
	{
	  text = textChar;

	  start = text.find(word, 0);

	  //If there's an occurence of the word in this line  
	  if(start != -1)
	    {

	      //Search for multiple occurences of the word in this line
	      while(start != -1)
		{
		  start = text.find(word, (start + word.length()));
		  count++;
		}
	  
	      cout << lineNum << " : " << text;
	      lineNum++;
            }
	  
	  //If there's no occurence of the word in this line
	  else
	    {
	      lineNum++;
	    }
	}

      cout << "# occurences of '" << word << "' = " << count << endl;

    }

  //If file couldn't be opened
  else
    {
      cerr << "File '" << inFile << "' could not be opened" << endl;
      return -1;
    }

  fclose(fp); //Close the file

  return 0;
      
}
