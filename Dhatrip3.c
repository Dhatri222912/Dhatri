#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack implementation
char stack[MAX];
int top = -1;

// Push character onto stack
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    } else {
// Pop character from stack
char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack underflow!\n");
        return '\0';
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char str[]) {
    int len = strlen(str);
    
    // Push all characters to the stack
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }

    // Compare characters while popping from the stack
    for (int i = 0; i < len; i++) {
        if (str[i] != pop()) {
            return 0; // Not a palindrome
        }
    }

    return 1; // Is a palindrome
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    
    // Remove newline character from input
    str[strcspn(str, "\n")] = '\0';

    if (isPalindrome(str)) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }

    return 0;
}
