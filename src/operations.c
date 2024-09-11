#include "push_swap.h"

// Swap the first two elements of stack a
void sa(t_stack *stack) {
    if (stack->size < 2)
        return;
    t_node *first = stack->top;
    t_node *second = first->next;
    first->next = second->next;
    second->next = first;
    stack->top = second;
    write(1, "sa\n", 3);
}

// Swap the first two elements of stack b
void sb(t_stack *stack) {
    if (stack->size < 2)
        return;
    t_node *first = stack->top;
    t_node *second = first->next;
    first->next = second->next;
    second->next = first;
    stack->top = second;
    write(1, "sb\n", 3);
}

// Swap both stacks (sa and sb)
void ss(t_stack *a, t_stack *b) {
    sa(a);
    sb(b);
    write(1, "ss\n", 3);
}

// Push the top element from stack a to stack b
void pb(t_stack *a, t_stack *b) {
    if (a->size == 0)
        return;
    t_node *tmp = a->top;
    a->top = a->top->next;
    a->size--;
    tmp->next = b->top;
    b->top = tmp;
    b->size++;
    write(1, "pb\n", 3);
}

// Push the top element from stack b to stack a
void pa(t_stack *b, t_stack *a) {
    if (b->size == 0)
        return;
    t_node *tmp = b->top;
    b->top = b->top->next;
    b->size--;
    tmp->next = a->top;
    a->top = tmp;
    a->size++;
    write(1, "pa\n", 3);
}

// Rotate stack a upwards
void ra(t_stack *stack) {
    if (stack->size < 2)
        return;
    t_node *first = stack->top;
    t_node *last = stack->top;
    while (last->next)
        last = last->next;
    stack->top = first->next;
    first->next = NULL;
    last->next = first;
    write(1, "ra\n", 3);
}

// Rotate stack b upwards
void rb(t_stack *stack) {
    if (stack->size < 2)
        return;
    t_node *first = stack->top;
    t_node *last = stack->top;
    while (last->next)
        last = last->next;
    stack->top = first->next;
    first->next = NULL;
    last->next = first;
    write(1, "rb\n", 3);
}

// Rotate both stacks upwards
void rr(t_stack *a, t_stack *b) {
    ra(a);
    rb(b);
    write(1, "rr\n", 3);
}

// Reverse rotate stack a downwards
void rra(t_stack *stack) {
    if (stack->size < 2)
        return;
    t_node *prev = NULL;
    t_node *last = stack->top;
    while (last->next) {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = stack->top;
    stack->top = last;
    write(1, "rra\n", 4);
}

// Reverse rotate stack b downwards
void rrb(t_stack *stack) {
    if (stack->size < 2)
        return;
    t_node *prev = NULL;
    t_node *last = stack->top;
    while (last->next) {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = stack->top;
    stack->top = last;
    write(1, "rrb\n", 4);
}

// Reverse rotate both stacks downwards
void rrr(t_stack *a, t_stack *b) {
    rra(a);
    rrb(b);
    write(1, "rrr\n", 4);
}

// Free the stack
void free_stack(t_stack *stack) {
    t_node *current = stack->top;
    t_node *next;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
    stack->top = NULL;
    stack->size = 0;
}
