#include <unistd.h>
#include <stdlib.h>

typedef struct {
    int stack[256];
    int top;
} stack_256;

void    push(int value, stack_256* stack);
int     pop(stack_256* stack);
void    parse(char *str);

int indexn = 0;
int i = 0;
stack_256 st;
char program[30000] = {0};
char current;

int main(int argc, char *argv[]) {
    if (argc == 2) {
        parse(argv[1]);
    }

    write(1, "\n", 1);

    return 0;
}

void parse(char *str) {
    while ((current = str[i])) {
        current == '>' ? indexn++ : indexn;
        current == '<' ? indexn-- : indexn;
        current == '+' ? program[indexn]++ : program[indexn];
        current == '-' ? program[indexn]-- : program[indexn];

        if (current == '.') {
            write(1, &program[indexn], 1);
        }

        else if (current == '[') {
            push(i++, &st);
            int end;
            while (program[indexn]) {
                parse(str);
                end = pop(&st);
                i = pop(&st);
            }
            i = end;
        }

        else if (current == ']') {
            push(i, &st);
            return;
        }

        i++;
    }
}


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
