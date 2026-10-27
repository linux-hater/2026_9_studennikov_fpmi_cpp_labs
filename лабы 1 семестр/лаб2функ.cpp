#include <iostream>
#include <cmath>
int n = 0, a = 0, b = 0, c = 0, sum=0;
void quadrat(int a, int b, int c) {
        std::cout << a << " " << b << " " << c << std::endl;
}
void troika(int kray) {
    for (a = 1; a <= kray; a++) {
        for (b = a; b <= kray; b++) {
           sum=a*a+b*b;
            c = std::round(std::sqrt(sum));
            if (c<=kray && c*c==sum) {
                quadrat(a,b,c);
            }
        }
    }
}
int main() {
    std::cout << "vvedite chislo dla troek" << std::endl;
    std::cin >> n;
    if (!n) {
        std::cout << "tolko natural" << std::endl;
        return 0;
    }
    troika(n);
}
