#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;
    double result;

    cout << "Welcome to the basic calculator program!" << endl;


    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

   
    cout << "Enter the operation (+, -, *, /): ";
    cin >> operation;

    switch (operation) {
        case '+':
            result = num1 + num2;
            cout << "The result of " << num1 << " + " << num2 << " is " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << "The result of " << num1 << " - " << num2 << " is " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "The result of " << num1 << " * " << num2 << " is " << result << endl;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                cout << "The result of " << num1 << " / " << num2 << " is " << result << endl;
            } else {
                cout << "Error! Division by zero." << endl;
            }
            break;
        default:
            cout << "Error! Invalid operation." << endl;
            break;
    }

    return 0;
}
