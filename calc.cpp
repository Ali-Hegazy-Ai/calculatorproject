#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

// Function to display help instructions
void displayHelp() {
    cout << "\n=== Help ===\n";
    cout << "This calculator supports basic operations and functions:\n";
    cout << "1. +  : Addition\n";
    cout << "2. -  : Subtraction\n";
    cout << "3. *  : Multiplication\n";
    cout << "4. /  : Division\n";
    cout << "5. ^  : Exponentiation (power)\n";
    cout << "6. sqrt(x) : Square root of x\n";
    cout << "7. sin(x), cos(x), tan(x) : Trigonometric functions (angles in degrees)\n\n";
    cout << "To use, type an expression like '2 + 3', 'sqrt(16)', 'sin(30)', or '2^3'.\n";
    cout << "To exit, type 'exit'.\n";
    cout << "=====================\n";
}

// Function to evaluate square root
double sqrtFunction(double value) {
    if (value < 0) {
        throw runtime_error("Error: Square root of negative number is undefined.");
    }
    return sqrt(value);
}

// Function to evaluate trigonometric functions in degrees
double sinFunction(double value) {
    return sin(value * M_PI / 180.0);  // Convert degrees to radians
}

double cosFunction(double value) {
    return cos(value * M_PI / 180.0);  // Convert degrees to radians
}

double tanFunction(double value) {
    return tan(value * M_PI / 180.0);  // Convert degrees to radians
}

// Function to parse and evaluate the expression
double evaluateExpression(const string& input) {
    double num1, num2, result;
    char op;

    stringstream ss(input);

    // Check for sqrt
    if (input.find("sqrt") != string::npos) {
        ss >> op; // consume the 'sqrt'
        ss >> op; // consume the '('
        ss >> num1;
        ss >> op; // consume the ')'
        return sqrtFunction(num1);
    }

    // Check for sin, cos, tan
    if (input.find("sin") != string::npos) {
        ss >> op; // consume the 'sin'
        ss >> op; // consume the '('
        ss >> num1;
        ss >> op; // consume the ')'
        return sinFunction(num1);
    }

    if (input.find("cos") != string::npos) {
        ss >> op; // consume the 'cos'
        ss >> op; // consume the '('
        ss >> num1;
        ss >> op; // consume the ')'
        return cosFunction(num1);
    }

    if (input.find("tan") != string::npos) {
        ss >> op; // consume the 'tan'
        ss >> op; // consume the '('
        ss >> num1;
        ss >> op; // consume the ')'
        return tanFunction(num1);
    }

    // Check for basic operations: +, -, *, /, ^
    if (ss >> num1 >> op >> num2) {
        switch (op) {
            case '+': return num1 + num2;
            case '-': return num1 - num2;
            case '*': return num1 * num2;
            case '/': 
                if (num2 == 0) throw runtime_error("Error: Division by zero.");
                return num1 / num2;
            case '^': return pow(num1, num2);
            default:
                throw runtime_error("Error: Invalid operator.");
        }
    }

    throw runtime_error("Error: Invalid expression.");
}

int main() {
    string input;

    cout << "=== Advanced Calculator ===\n";
    cout << "Type 'help' for instructions.\n";
    cout << "=====================\n";

    while (true) {
        cout << "\nEnter expression: ";
        getline(cin, input);

        // Exit if user types "exit"
        if (input == "exit") {
            cout << "Goodbye!\n";
            break;
        }

        // Show help if user types "help"
        if (input == "help") {
            displayHelp();
            continue;
        }

        try {
            double result = evaluateExpression(input);
            cout << "Result: " << result << endl;
        } catch (const exception& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}
