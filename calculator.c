#include <stdio.h>
#include <stdlib.h>

// Function to clear the console screen
void clearScreen()
{
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

// Function to pause the program
void pressAnyKeyToContinue()
{
  system("pause");
}

int main()
{
  // Variables
  double firstNumber, secondNumber, result;
  char operator, exitCall;

  while (1)
  {
    // Clearing Old Console and Taking Inputs
    clearScreen();

    printf("Enter the first number: ");
    scanf(" %lf", &firstNumber);

    printf("Enter the operator (+ , - , * , / , %%) : ");
    scanf(" %c", &operator);

    printf("Enter the second number: ");
    scanf(" %lf", &secondNumber);

    switch (operator)
    {
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
      if (secondNumber == 0)
      {
        printf("Error: You cannot divide a number by Zero \n");
        pressAnyKeyToContinue();
        continue;
      }
      else
      {
        result = firstNumber / secondNumber;
        break;
      }

    case '%':
      if (secondNumber == 0)
      {
        printf("Error: You cannot divide a number by Zero \n");
        pressAnyKeyToContinue();
        continue;
      }
      else
      {
        result = (int)firstNumber % (int)secondNumber;
        break;
      }

    default:
      printf("Error invalid operator \n");
      // pressAnyKeyToContinue();
      getchar();
      continue;
    }

    printf("The result is: %lf \n", result);

    printf("Do you wanna calculate more...? /n type 'y'Yes or 'n'No: ");
    scanf(" %c", &exitCall);

    if (exitCall == 'n')
    {
      break;
    }
  }
  return 0;
}
