#include <stdio.h>
#include "stack.h"

void parse(char *str);

int indexn = 0;
int i = 0;
stack_256 st;
char program[30000] = {0};
char current;

int main(int argc, char *argv[]) {
    if (argc == 2) {
        parse(argv[1]);
    }

    printf("\n");

    return 0;
}

void parse(char *str) {
    while ((current = str[i])) {
        current == '>' ? indexn++ : indexn;
        current == '<' ? indexn-- : indexn;
        current == '+' ? program[indexn]++ : program[indexn];
        current == '-' ? program[indexn]-- : program[indexn];

        if (current == '.') {
            printf("%c", program[indexn]);
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
