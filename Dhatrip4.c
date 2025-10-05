

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack definition
char stack[MAX];
int top = -1;

// Function to push element to stack
void push(char c) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = c;
    }
}

// Function to pop element from stack
char pop() {
    if (top < 0) {
        return '\0'; // Empty stack
    } else {
        return stack[top--];
    }
}

// Function to check if opening and closing brackets match
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}') | 
}
