#include <stdlib.h>

typedef struct {
    int stack[256];
    int top;
} stack_256;

void    push(int value, stack_256* stack);
int     pop(stack_256* stack);
