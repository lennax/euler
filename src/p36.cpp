#include <iostream>
#include <stdio.h>
#include <string>
#include <bitset>
#include <inttypes.h>
#include <stdlib.h>

//#include "itoa.h"

//585 is 1001001001 in binary - palindrome in both
//find all numbers less than 1M palindromic in both
//report sum
//function isPalindrome() string reverse and compare??
//use bitset to treat as binary?

class PalindromeFinder
{
public:
	//PalindromeFinder (const char * test) { // XXX for cmd line
	PalindromeFinder (const char * arg) {
		using namespace std;

		if (arg) {
		// XXX test for command line interface XXX
			cout << "base\tforward\treversed" << endl;
			cout << "10\t" << arg << "\t" << strRev(arg) << endl;
			cout << "\t";
			if(isPalindrome(arg)) cout << "is ";
			else cout << "is not ";
			cout << "a palindrome." << endl;
			string bin = binStr(arg);
			cout << "2\t" << bin << "\t" << strRev(bin) << endl;
			cout << "\t";
			if(isPalindrome(bin)) cout << "is ";
			else cout << "is not ";
			cout << "a palindrome." << endl;	
		}
		else {
			uint32_t total = 0;
			for (uint32_t i=1; i<1000000; i++) {
				if (i%10 > 0) {
					// XXX itoa is nonstandard 
					char test[33];
					itoa(i, test, 10);
					if (isPalindrome(test) && isPalindrome((binStr(test)))) {
						cout << test << "\t" << binStr(test) << endl;
						total += i;
					}
				}	
			}
			cout << "Total: " << total << endl;
		}
		
	}
private:
	/*******************************************************
	* Code contributed by Chris Takahashi,                 *
	* ctakahashi (at) users (dot) sourceforge (dot) net.   *
	* See stdlib.h for licence.                            *
	* $Date: 2005/08/31 11:39:47 $                         *
	*******************************************************/
	char *itoa(int num, char *str, int radix) {
	    char sign = 0;
	    char temp[17];  //an int can only be 16 bits long
	                    //at radix 2 (binary) the string
	                    //is at most 16 + 1 null long.
	    int temp_loc = 0;
	    int digit;
	    int str_loc = 0;

	    //save sign for radix 10 conversion
	    if (radix == 10 && num < 0) {
	        sign = 1;
	        num = -num;
	    }

	    //construct a backward string of the number.
	    do {
	        digit = (unsigned int)num % radix;
	        if (digit < 10) 
	            temp[temp_loc++] = digit + '0';
	        else
	            temp[temp_loc++] = digit - 10 + 'A';
	        num = (((unsigned int)num) / radix);
	    } while ((unsigned int)num > 0);

	    //now add the sign for radix 10
	    if (radix == 10 && sign) {
	        temp[temp_loc] = '-';
	    } else {
	        temp_loc--;
	    }


	    //now reverse the string.
	    while ( temp_loc >=0 ) {// while there are still chars
	        str[str_loc++] = temp[temp_loc--];    
	    }
	    str[str_loc] = 0; // add null termination.

	    return str;
	}
	
	
	
	
	
	// Given string, reverses order of characters
	std::string strRev(std::string str) {
		std::string reversed; 
		for (int i=str.size()-1; i>-1; i--) 
			reversed.append(str.substr(i,1));
		
		return reversed;
	}
	
	// Given string, returns true if palindrome
	bool isPalindrome(std::string test) {
		std::string reverse = strRev(test);
		if (test.compare(reverse) == 0) return true;
		return false;
	}

	// Given test string, converts to integer	
	uint32_t strToInt(std::string str) {
		uint32_t intReturn;
		// FIXME validate str to be integer
		intReturn = atoi(str.c_str());
		return intReturn;
	}

	// Given test string, converts to binary and removes leading zeroes
	std::string binStr(std::string test) {
		using namespace std;
		string binStr = bitset<32>(strToInt(test)).to_string();
		// stop must be set because binStr.size() is changed in loop
		uint32_t stop = binStr.size();
		for (uint32_t i=0; i<stop; i++) {
			if ((binStr.substr(0,1)).compare("0") == 0) {
				binStr.erase(0,1);
			}
		}
		return binStr;
	}
};

int main (int argc, char const* argv[])
{	
	// XXX Command line interface XXX
	using namespace std;
	if (argc==1) {
		argv[1] = 0;
		cerr << "For single number, usage: " 
			<< argv[0] << " number" << endl;
	}
	else if (argc==2)
		cerr << "To find all dual palindromes under 1M, omit argument." 
			<< endl;
	else if (argc!=2) {
		cerr << "usage: " << argv[0] << " number" << endl;
		return 1;
	}
	// FIXME validate argv[1] to be integer
	PalindromeFinder testInstance(argv[1]);

	// PalindromeFinder palindromeInstance(0);

	return 0;
}
