#include <iostream>
#include <number.h>
#include <vector.h>

int main() {
    Number num1(14);
    Number num2(300);
    Vector vector(num1, num2);
    Number num3 = (num1 + num2 + Number(14) / Number(2) * Number(3) - Number(10));
    num3.Print();
    std:: cout << " ";
    vector.AngleCalculation().Print();
    std:: cout << " ";
    vector.RadiusCalculation().Print();
}
