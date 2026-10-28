#include <iostream>
#include <vector>
#include <string>
std::string getText() {
    std::string text;
    std::getline(std::cin,text );
    return text;
}
std::string shiv(std::string text) {
    std::string result;
    for (size_t i=0; i<text.size();i++) {
        int count=1;
        while(i+1<text.size()&& text[i]==text[i+1]){
            i++;
            count++;
        }
        result+=text[i];
        if (count>1) {
            result+=std::to_string(count);
        }
    }
    return result;
}
void out(std::string result) {
    std::cout<<result<<std::endl;
}
int main () {
std::string text=getText();
std::string result =shiv(text);
out(result);
    return 0;

}