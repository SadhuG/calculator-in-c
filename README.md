## Simple Calculator in C

This project is a simple calculator program written in C that performs basic arithmetic operations (+, -, \*, /, %). It demonstrates several key features of the C programming language, including functions, loops, conditionals, and input/output operations.

### Features of C Demonstrated

1. **Standard Library Functions**:

- The program uses standard library functions like `printf` and `scanf` from the `stdio.h` library for input and output operations.
- The `system` function from `stdlib.h` is used to clear the screen and pause the program.

2. **Conditional Compilation**:

- The `clearScreen` function uses conditional compilation (`#ifdef _WIN32`) to determine the appropriate command to clear the console screen based on the operating system (Windows or Unix-based).

3. **Functions**:

- The program defines two functions: `clearScreen` and `pressAnyKeyToContinue`, demonstrating modularity and code reuse.

4. **Loops**:

- A `while` loop is used to repeatedly prompt the user for input and perform calculations until the user decides to exit.

5. **Conditional Statements**:

- The `switch` statement is used to handle different arithmetic operations based on the operator entered by the user.
- `if` statements are used to handle division by zero errors.

6. **Type Conversion**:

   - Explicit type casting is used in the modulus operation to convert `double` values to `int`.

7. **Input/Output**:
   - The program uses `scanf` to read user input and `printf` to display results and messages to the user.

### Code Overview

```c
#include <stdio.h>
#include <stdlib.h>

// Function to clear the console screen
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Function to pause the program
void pressAnyKeyToContinue() {
    system("pause");
}

int main() {
    // Variables
    double firstNumber, secondNumber, result;
    char operator, exitCall;

    while (1) {
        // Clearing Old Console and Taking Inputs
        clearScreen();

        printf("Enter the first number: ");
        scanf(" %lf", &firstNumber);

        printf("Enter the operator (+ , - , * , / , %%) : ");
        scanf(" %c", &operator);

        printf("Enter the second number: ");
        scanf(" %lf", &secondNumber);

        switch (operator) {
            case '+':
                result = firstNumber + secondNumber;
                break;
            case '-':
                result = firstNumber - secondNumber;
                break;
            case '*':
                result = firstNumber * secondNumber;
                break;
            case '/':
                if (secondNumber == 0) {
                    printf("Error: You cannot divide a number by Zero \n");
                    pressAnyKeyToContinue();
                    continue;
                } else {
                    result = firstNumber / secondNumber;
                    break;
                }
            case '%':
                if (secondNumber == 0) {
                    printf("Error: You cannot divide a number by Zero \n");
                    pressAnyKeyToContinue();
                    continue;
                } else {
                    result = (int)firstNumber % (int)secondNumber;
                    break;
                }
            default:
                printf("Error invalid operator \n");
                getchar();
                continue;
        }

        printf("The result is: %lf \n", result);

        printf("Do you wanna calculate more...? /n type 'y'Yes or 'n'No: ");
        scanf(" %c", &exitCall);

        if (exitCall == 'n') {
            break;
        }
    }
    return 0;
}
```

This program is a great example of how to use various features of the C programming language to create a functional and interactive console application. Feel free to explore and modify the code to add more features or improve its functionality!
