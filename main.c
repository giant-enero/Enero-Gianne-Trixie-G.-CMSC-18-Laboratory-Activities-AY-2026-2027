#include <stdio.h>

int main() {
    int count = 5;
    float myVariable = 3.14;
    char smallLetter = 'a';
    int num1 = 10;
    char bigLetter = 'H';
    int num2 = 100;

    printf("I saw %d hashiras stealing a pie worth %.2f yen while yelling '%c'. Then, %d Michael Jacksons got angry and shouted '%c-hee' while carrying %d blue spider lilies.\n",count, myVariable, smallLetter, num1, bigLetter, num2);

    char userInput[100];

    printf("Describe your reaction in one word: ");
    scanf("%99s", userInput);

    printf("Your reaction is: %s\n", userInput);
    printf("Thank you for your reaction!\n");

    return 0;
}
