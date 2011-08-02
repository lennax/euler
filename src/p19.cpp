#include <iostream>
#include <vector>
#include <inttypes.h>

bool isLeap (uint32_t year) {
	//if (year%4 == 0) {
		//if (year%100 > 0) {
			//if (year%400 > 0) {
			//}
		//}
	//}
		   
	if (year%4 == 0 && (year%100 > 0 || year%400 == 0)) return 1;
	return 0;
}




int main (int argc, char const* argv[])
{
	uint32_t array[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	std::vector<uint32_t> months(&array[0], &array[11]);

	//std::cout << months[1] << std::endl;
	
	for (uint32_t year=1900; year<2001; year++) {
		for (uint32_t month=0; month<12; month++) {
			//need to implement isLeap()
		}
	}
std::cout << "1000: " << isLeap(1000) << std::endl;
std::cout << "2000: " << isLeap(2000) << std::endl;
std::cout << "1004: " << isLeap(1004) << std::endl;
std::cout << "1005: " << isLeap(1005) << std::endl;


	return 0;
}

