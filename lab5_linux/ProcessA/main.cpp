#include <iostream>
#include <sstream>

int main() {
    int N = 27;
    int n;
    std::string str;
    getline(std::cin, str);
    std::stringstream ss(str);
    while (ss >> n){
        std::cout << n + N << " ";
    }
    return 0;
}