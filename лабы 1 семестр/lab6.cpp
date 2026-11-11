#include <iostream>
#include <vector>
#include <string>
#include <fstream>
bool IsEmptyFile(std::ifstream& fin) {
    return fin.peek() == std::ifstream::traits_type::eof();
}
std::string getText(const std::string& ifname) {
    std::ifstream fin{ ifname };
    if (!fin.is_open()) {
        throw "Error: could no open file \"" + ifname + "\"";
    }
    if (IsEmptyFile(fin)) {
        throw "Error: file \"" + ifname + "\" is empty";
    }
    std::string text;
    char b;
    while (fin.get(b)){
    text += b;
    }
    fin.close();
    return text;    
}
std::string shiv(std::string text) {
    std::string result;
    for (size_t i = 0; i < text.size();i++) {
        int count = 1;
        while (i + 1 < text.size() && text[i] == text[i + 1]) {
            i++;
            count++;
        }
        result += text[i];
        if (count > 1) {
            result += std::to_string(count);
        }
    }
    return result;
}
void out(std::string result, const std::string& ofname) {
    std::ofstream fout{ofname};

    if (!fout.is_open()) {
        throw "Error: could no open file \"" + ofname + "\"";
    }

    fout << result;
    fout.close();
}
int main() {
    const std::string ifname = "input.txt";
    const std::string ofname = "output.txt";
    try {
        std::string text = getText(ifname);
        std::string result = shiv(text);
        out(result, ofname);
        std::cout << "success" << std::endl;
    }
    catch (const std::string& msg) {
        std::cout << msg << std::endl;
        return 1;
    }
    return 0;
}