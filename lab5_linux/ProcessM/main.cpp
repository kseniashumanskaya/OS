#include <iostream>
#include <vector>
#include <sstream>

int main() {
    int n;
    std::string str;
    getline(std::cin, str);
    std::stringstream ss(str);
    while (ss >> n){
        std::cout << n * 7 << " ";
    }
    return 0;
}
