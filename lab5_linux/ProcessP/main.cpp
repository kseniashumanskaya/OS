#include <iostream>
#include <sstream>
#include <cmath>

int main() {
    int n;
    std::string str;
    getline(std::cin, str);
    std::stringstream ss(str);
    while (ss >> n){
        std::cout << pow(n, 3)<< " ";
    }
    return 0;
}
