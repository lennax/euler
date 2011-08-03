#include <iostream>
#include <stdio.h>
#include <string>
#include <bitset>
#include <inttypes.h>
#include <stdlib.h>

extern "C" {
#include "itoa.h"
};

//585 is 1001001001 in binary - palindrome in both
//find all numbers less than 1M palindromic in both
//report sum
//function isPalindrome() string reverse and compare??
//use bitset to treat as binary?

class PalindromeFinder
{
public:
	//PalindromeFinder (const char * test) { // XXX for cmd line
	PalindromeFinder () {

		using namespace std;
		uint32_t total = 0;
		for (uint32_t i=1; i<1000000; i++) {
			if (i%10 > 0) {
				// char test [33];
				// sprintf (test, "%u", i);
				char test[33];
				itoa(i, test, 10);
				if (isPalindrome(test) && isPalindrome((binStr(test)))) {
					cout << test << "\t" << binStr(test) << endl;
					total += i;
				}
				// cout << i << "\t" << isPalindrome(test) << endl;
			}	
		}
		cout << "Total: " << total << endl;

		// int num = 123;
		// char buf[5];
		// itoa(num, buf, 10);
		// printf("%s\n", buf);

		//// XXX test for command line interface XXX
		//cout << test << " reversed: " << strRev(test) << endl;
		//if(isPalindrome(test)) cout << "is ";
		//else cout << "is not ";
		//cout << "a palindrome." << endl;
		//cout <<  binStr(test) << " bin; rev: " 
			//<<  strRev(binStr(test)) << endl;
		//if(isPalindrome(binStr(test))) cout << "is ";
		//else cout << "is not ";
		//cout << "a palindrome." << endl;
		
	}
private:
	
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
	//// XXX Command line interface XXX
	//using namespace std;
	//if (argc!=2) {
		//cerr << "usage: " << argv[0] << " number" << endl;
		//return 1;
	//}
	//// FIXME validate argv[1] to be integer
	//PalindromeFinder testInstance(argv[1]);

	PalindromeFinder palindromeInstance;

	return 0;
}
