#include "push_swap.h"
#include <stdio.h>

// Helper function to create a new stack node
t_node *create_node(int value) {
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->next = NULL;
    return (new_node);
}

// Add value to the top of the stack
void push(t_stack *stack, int value) {
    t_node *new_node = create_node(value);
    if (!new_node)
        return;  // Handle memory allocation error

    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

// Convert input to integers and add to stack
int is_valid_number(const char *str) {
    int i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i]) {
        if (str[i] < '0' || str[i] > '9')
            return 0;  // Invalid character
        i++;
    }
    return 1;
}

void parse_input(int argc, char **argv, t_stack *stack) {
    for (int i = argc - 1; i > 0; i--) {
        if (!is_valid_number(argv[i])) {
            write(2, "Error\n", 6);  // Print error and exit
            exit(EXIT_FAILURE);
        }
        push(stack, atoi(argv[i]));
    }
}

