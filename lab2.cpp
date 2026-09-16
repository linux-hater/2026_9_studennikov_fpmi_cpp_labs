#include <iostream>
int n=0, a = 0, b = 0, c = 0;
int main() {

	std::cout << "vvedite chislo dla troek" << std::endl;
	std::cin >> n;
	if (n <= 0) {
		std::cout << "tolko natural" << std::endl;
		return 0;
	}
	else
		for (a=1; a <= n; a++) {
			for (b = a; b <= n; b++) {
				for (c = b; c <= n; c++) {
		
					if (a * a + b * b == c * c) {
						std::cout << a << " " << b << " " << c << std::endl;

				}

				
				
				
				}
			}
		}









}