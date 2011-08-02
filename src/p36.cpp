#include <iostream>
#include <string>
#include <bitset>
#include <inttypes.h>
#include <stdlib.h>

//585 is 1001001001 in binary - palindrome in both
//find all numbers less than 1M palindromic in both
//report sum
//function isPalindrome() string reverse and compare??
//use bitset to treat as binary?

bool isPalindrome(std::string number) {
	return false;
}

std::string strRev(std::string str) {
	int len = str.size();
	std::string reversed; 
	for (int i=len-1; i>-1; i--) {
		reversed.append(str.substr(i,1));
	}
	//std::cout << "rev: " << reversed << std::endl;
	//std::cout << "length: " << str.size() << std::endl;
	return reversed;
}

int strToInt(std::string str) {
	int intReturn;
	intReturn = atoi(str.c_str());
	return intReturn;
}

int main (int argc, char const* argv[])
{
	using namespace std;
	if (argc!=2) {
		cerr << "usage: " << argv[0] << " number" << endl;
		return 1;
	}
	string testRev = strRev(argv[1]);
	cout << argv[1] << " reversed: " << testRev << endl;
	cout << "bitset 32: " << bitset<32>(strToInt(argv[1])) << endl;
	return 0;
}
