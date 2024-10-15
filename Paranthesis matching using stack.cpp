#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Stack {
    int top;
    int capacity;
    char* array;
};


struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}


int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}


void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}


char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->array[stack->top--];
}


int isMatchingParenthesis(char* expression) {
    struct Stack* stack = createStack(strlen(expression));

 
    for (int i = 0; i < strlen(expression); i++) {
        char current = expression[i];

       
        if (current == '(' || current == '{' || current == '[') {
            push(stack, current);
        }

       
        if (current == ')' || current == '}' || current == ']') {
            if (isEmpty(stack)) {
                return 0; // Unbalanced (extra closing parenthesis)
            }
            char top = pop(stack);
            if ((current == ')' && top != '(') ||
                (current == '}' && top != '{') ||
                (current == ']' && top != '[')) {
                return 0; // Mismatched parentheses
            }
        }
    }

 
    return isEmpty(stack);
}

int main() {
    char expression[100];

   
    printf("Enter an expression with parentheses: ");
    scanf("%s", expression);

   
    if (isMatchingParenthesis(expression)) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are NOT balanced.\n");
    }

    return 0;
}
