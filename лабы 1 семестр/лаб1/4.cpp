#include <iostream>
#include <string>
int main() {
    std::cout<< "vvedite c 6 zn chislo" << std::endl;
    int i,a,b;
    std::cin >> i;
    a = (i/100000)%10 + (i/10000)%10 + (i/1000)%10;
    b = (i/100)%10 + (i/10)%10 + (i/1)%10;
    if (a == b) {
        std::cout<<"schaste" << std::endl;
    }else std::cout<<"neschaste";

}