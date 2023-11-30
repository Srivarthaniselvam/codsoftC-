# task 2
# simple calculator

#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

int main() {
    cout << "Welcome to the Simple Calculator Program!" << endl;

    double num1, num2, result;
    char operation;
    string continueCalculation;

    do {
    
        cout << "Enter the first number: ";
        cin >> num1;

        
        cout << "Enter the second number: ";
        cin >> num2;

        cout << "Choose an operation (+, -, *, /): ";
        cin >> operation;

        
        switch (operation) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                
                
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                    return 1; 
                }
                break;
                
            default:
                cout << "Error: Invalid operation." << endl;
                return 1; 
        }

        
        cout << "Result of (" << num1 << " " << operation << " " << num2 << "): " << result << endl;

        
        cout << "Do you want to perform another calculation? (yes/no): ";
        cin >> continueCalculation;

        
        for (char &c : continueCalculation) {
            c = tolower(c);
        }

    } while (continueCalculation == "yes");

    
    cout << "Thank you for using the calculator. Goodbye!" << endl;

    return 0;
    
}
