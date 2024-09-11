#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

// Stack node structure
typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

// Stack structure
typedef struct s_stack {
    t_node *top;
    int size;
} t_stack;

// Function declarations
void parse_input(int argc, char **argv, t_stack *stack);
void sa(t_stack *stack);
void sb(t_stack *stack);
void ss(t_stack *a, t_stack *b);
void pa(t_stack *b, t_stack *a);
void pb(t_stack *a, t_stack *b);
void ra(t_stack *stack);
void rb(t_stack *stack);
void rr(t_stack *a, t_stack *b);
void rra(t_stack *stack);
void rrb(t_stack *stack);
void rrr(t_stack *a, t_stack *b);
void free_stack(t_stack *stack);
void sort_small_stack(t_stack *a);
void sort_large_stack(t_stack *a, t_stack *b);

int find_min(t_stack *stack);
int find_max(t_stack *stack);
int is_sorted(t_stack *stack);

#endif
