
   #include <stdio.h>
#define MAX 32  // Maximum number of bits for an integer

// Stack structure
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initialize(Stack *s) {
    s->top = -1;
}

// Check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push function
void push(Stack *s, int value) {
    if (!isFull(s)) {
        s->items[++(s->top)] = value;
    } else {
        printf("Stack overflow!\n");
    }
}

// Pop function
int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    } else {
        printf("Stack underflow!\n");
        return -1;
    }
}

// Function to convert integer to binary using stack
void convertToBinary(int number) {
    Stack s;
    initialize(&s);

    if (number == 0) {
        printf("Binary: 0\n");
        return;
    }

    while (number > 0) {
        push(&s, number % 2);
        number /= 2;
    }

    printf("Binary: ");
    while (!isEmpty(&s)) {
        printf("%d", pop(&s));
    }
    printf("\n");
}

// Main function
int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Please enter a non-negative integer.\n");
    } else {
        convertToBinary(number);
    }

    return 0;
}
