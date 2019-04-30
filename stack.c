#include "stack.h"

void push(int value, stack_256* stack) {
    stack->stack[stack->top] = value;

    stack->top++;
}

int pop(stack_256* stack) {
    if (stack->top == 0) {
        exit(1);
    }

    stack->top--;
    return stack->stack[stack->top];
}
