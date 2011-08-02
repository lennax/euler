#include <iostream>
#include <vector>
#include <inttypes.h>

bool isLeap (uint32_t year) {
	// Multiples of 4 are generally leap years
	// Multiples of 100 are generally not leap years
	// Multiples of 400 are always leap years
	if (year%4 == 0 && (year%100 > 0 || year%400 == 0)) return 1;
	return 0;
}

int main (int argc, char const* argv[])
{
	// create array of days of months, make vector
	uint32_t array[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	std::vector<uint32_t> months(&array[0], &array[12]);

	for (uint32_t i=0; i<months.size(); i++) {
		std::cout << months[i] << std::endl;
	}
	
	uint32_t offset = 0;
	uint32_t sundays = 0;

	for (uint32_t year=1900; year<2001; year++) 
		for (uint32_t month=0; month<12; month++) {
			if(month == 1 && isLeap(year)) 
				offset += 29;
			else
				offset += months[month];
			
			if (year > 1900 && offset%7 == 6) 
			   	sundays++;
			
		
	}
	//std::cout << "1000: " << isLeap(1000) << std::endl;
	//std::cout << "2000: " << isLeap(2000) << std::endl;
	//std::cout << "1004: " << isLeap(1004) << std::endl;
	//std::cout << "1005: " << isLeap(1005) << std::endl;

	std::cout << "Sundays on the first of the month: " << sundays << std::endl;

	return 0;
}

