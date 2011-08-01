#include <iostream>
#include <vector>
#include <inttypes.h>

int main (int argc, char const* argv[])
{
	uint32_t array[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	std::vector<uint32_t> months(&array[0], &array[11]);
	std::cout << months[1] << std::endl;
	return 0;
}

