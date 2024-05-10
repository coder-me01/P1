#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Function to perform arithmetic operations
int performOperation(char operator, int operand1, int operand2) {
    switch(operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        default: printf("Invalid operator\n"); return -1;
    }
}

// Function to evaluate postfix expression
int evaluatePostfix(char *expression) {
    int stack[MAX_SIZE];
    int top = -1;

    for(int i = 0; expression[i] != '\0'; i++) {
        if(isdigit(expression[i])) {
            stack[++top] = expression[i] - '0'; // Convert char to int
        } else {
            int operand2 = stack[top--];
            int operand1 = stack[top--];
            int result = performOperation(expression[i], operand1, operand2);
            stack[++top] = result;
        }
    }

    return stack[top];
}

int main() {
    char expression[MAX_SIZE];
    printf("Enter the postfix expression: ");
    scanf("%s", expression);

    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}
