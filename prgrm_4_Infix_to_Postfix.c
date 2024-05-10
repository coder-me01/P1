#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 40

char stack[SIZE];
int top = -1;

void push(char item) {
    if (top == SIZE - 1) {
        printf("\nStack Overflow\n");
        exit(1);
    } else {
        stack[++top] = item;
    }
}

char pop() {
    if (top < 0) {
        printf("\nStack Underflow: Invalid infix expression\n");
        exit(1);
    }
    return stack[top--];
}

int precedence(char op) {
    switch (op) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return -1;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    int i, j;
    char ch;
    for (i = j = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while ((ch = pop()) != '(') {
                postfix[j++] = ch;
            }
        } else {
            while (top != -1 && precedence(infix[i]) <= precedence(stack[top])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[SIZE], postfix[SIZE];
    printf("Enter infix expression: ");
    fgets(infix, SIZE, stdin);
    infix[strlen(infix) - 1] = '\0'; // Remove newline character from input
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
