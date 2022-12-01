#include <iostream>
#include <sstream>
#include <cmath>

int main() {
    int sum = 0;
    int n;
    std::string str;
    getline(std::cin, str);
    std::stringstream ss(str);
    while (ss >> n) {
        sum += n;
    }
    std:: cout << sum;
    return 0;
}

