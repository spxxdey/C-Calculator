#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

double quadratic() {
    std::string me;
    double a;
    double b;
    double c;
    std::cout << "Enter your mathematical expression: ";
    std::getline(std::cin, me);
    me.erase(std::remove_if(me.begin(), me.end(), ::isspace), me.end());
    int xSquared = me.find("x**2");
    int equals = me.find("=");
    // int x = me.find("x", xSquared + 3);
    if (xSquared == 0) {
        a = 1;
    } else {
        a = std::stod(me.substr(0, xSquared));
    }
    b = std::stod(me.substr(equals - 2));
    c = std::stod(me.substr(equals + 1));
    c = -c;
    double discr = b * b - 4 * a * c;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "discriminant = " << discr << std::endl;
    double positive = (-b + std::sqrt(discr)) / (2 * a);
    double negative = (-b - std::sqrt(discr)) / (2 * a);
    std::cout << "Answer: x = " << positive << ", x = " << negative << std::endl;
    return 0;
}

double simple() {
    std::string me;
    cout << "Enter your mathematical expression: ";
    std::getline(std::cin, me);
    me.erase(std::remove_if(me.begin(), me.end(), ::isspace), me.end());
    for (int i = 0; i < me.length(); i++) {
        if (me[i] == '+' || me[i] == '-' || me[i] == '*' || me[i] == '/') {
            double num1 = std::stod(me.substr(0, i));
            double num2 = std::stod(me.substr(i + 1));
            if (me[i] == '+') {
                return num1 + num2;
            } else if (me[i] == '-') {
                return num1 - num2;
            } else if (me[i] == '*') {
                return num1 * num2;
            } else {
                return num1 / num2;
            }
        }
    }

    return 0;
}

int main() 
{
    std::string expression;
    std::string choice;
    cout << "What kind of expression do you want to solve?" << "\n" << "1. Simple ( For example 2 + 2 = 4)" << "\n" << "2. Algebra ( For example 2x + 3y = 30)" << "\n\n" << "Enter: ";
    std::cin >> choice;
    cin.ignore();
    if (choice == "1") {
        std::cout << "Result: " << simple() << std::endl;
    } else if (choice == "2") {
        quadratic();
    }
    return 0;
}
