#include <algorithm>
#include <iostream>
#include <string>
int main() {
    std::string i, a;
    std::cout << "enter number";
    std::cin >> i;
    a=i;
    std::reverse(i.begin(), i.end());
    if (i==a){
        std::cout<<"number palindorm";
    }else {
        std::cout<<"ne palindrom";
    }
}
