#include <iostream>
#include <string>
#include <bitset>

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

int main()
{
	std::string test = "1234567890";
	std::string testRev = strRev(test);
	std::cout << test << " reversed: " << testRev << std::endl;
	return 0;
}
