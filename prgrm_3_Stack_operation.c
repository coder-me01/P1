#include <stdio.h>   
#include <stdlib.h>   

#define SIZE 4   

int top = -1, a[SIZE]; 

void push();   
void pop();   
void display();   

int main()   
{   
    int choice;   
    while (1)   
    {   
        printf("\nPerform operations on the stack:");
        printf("\n1.Push \n2.Pop \n3.Display \n4.Exit");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);
        
        switch (choice)   
        {   
            case 1:   
                push();   
                break;   
            case 2:   
                pop();   
                break;   
            case 3:   
                display();   
                break;   
            case 4:   
                exit(0);   
            default:   
                printf("\nInvalid choice!!");   
        }   
    }   
}   

void push()   
{   
    int e;
    if (top == SIZE - 1)   
    {   
        printf("\nOverflow!!");   
    }   
    else   
    {   
        printf("\nEnter the element to be added onto the stack: ");   
        scanf("%d", &e);   
        top = top + 1;   
        a[top] = e;   
    }   
}   

void pop()   
{   
    if (top == -1)   
    {   
        printf("\nUnderflow!!");   
    }   
    else   
    {   
        printf("\nPopped element: %d", a[top]);   
        top = top - 1;   
    }   
}   

void display()   
{   
    if (top == -1)   
    {   
        printf("\nUnderflow!!");   
    }   
    else   
    {   
        printf("\nElements found in the stack: \n");   
        for (int i = top; i >= 0; --i)   
            printf("%d\n", a[i]);   
    }   
}
