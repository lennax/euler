#include <iostream> // for cout, endl
#include <math.h> // for pow()
#include <gmp.h> // for mpf_t, mpf_set_ui()
#include <string> // for string

int main() {
	mpf_t fp;
	mpf_init( fp );
	
	//mpf_set_ui(fp, pow(10,1000));
	mpf_set_d(fp, 10e10);

	//mpf_out_str(stdout, 10, 2, fp);
	std::cout << fp << std::endl;
	return 0;
}
