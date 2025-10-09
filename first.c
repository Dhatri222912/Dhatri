#include <stdio.h>
#include <stdlib.h>
#define size 5

struct stack {
    int top;
    int data[size];
};
typedef struct stack stack;

void push(stack *s, int item) {
    if (s->top == size - 1)
        printf("Stack overflow\n");
    else {
        s->top += 1;
        s->data[s->top] = item;
    }
}

void pop(stack *s) {
    if (s->top == -1)
        printf("Stack underflow\n");
    else {
        printf("\nElement popped is %d\n", s->data[s->top]);
        s->top -= 1;
    }
}

void display(stack *s) {
    int i;
    if (s->top == -1)
        printf("\nStack is empty\n");
    else {
        printf("Stack contents:\n");
        for (i = s->top; i >= 0; i--)
            printf("%d\n", s->data[i]);
    }
}

int main() {
    int ch, item;
    stack s;
    s.top = -1;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to be pushed: ");
                scanf("%d", &item);
                push(&s, item);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
