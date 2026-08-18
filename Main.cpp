#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

double calculator(std::string me) {
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
    cout << "Enter your mathematical expression: ";
    std::getline(std::cin, expression);
    std::cout << "Result: " << calculator(expression) << std::endl;
    return 0;
}
