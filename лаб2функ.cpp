#include <iostream>
int n = 0, a = 0, b = 0, c = 0;
void quadrat(int a, int b, int c) {
	if (a * a + b * b == c * c) {
		std::cout << a << " " << b << " " << c << std::endl;

	}

	
}
void troika(int kray) {
	for (a = 1; a <= kray; a++) {
		for (b = a; b <= kray; b++) {
			for (c = b; c <= kray; c++) {
				quadrat(a, b, c);
			
			}
		}
	}
}
int main() {
	std::cout << "vvedite chislo dla troek" << std::endl;
	std::cin >> n;
	if (n <= 0) {
		std::cout << "tolko natural" << std::endl;
		return 0;
	}
	troika(n);
}