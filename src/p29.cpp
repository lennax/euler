#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>

int main (int argc, char const* argv[])
{
	std::set<double> uniqueList;
	for(double a=2;a<101;a++) for(int b=2;b<101;b++) {
		uniqueList.insert(pow(a,b));
	}
	std::cout << "length: " << uniqueList.size() << std::endl;
	
	return 0;
}

