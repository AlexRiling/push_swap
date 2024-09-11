#include "push_swap.h"

void sort_2(t_stack *a) {
    if (a->top->value > a->top->next->value) {
        sa(a);
    }
}

void sort_3(t_stack *a) {
    int first = a->top->value;
    int second = a->top->next->value;
    int third = a->top->next->next->value;

    if (first > second && second < third && first < third) {
        sa(a);
    } else if (first > second && second > third) {
        sa(a);
        rra(a);
    } else if (first > second && second < third && first > third) {
        ra(a);
    } else if (first < second && second > third && first < third) {
        sa(a);
        ra(a);
    } else if (first < second && second > third && first > third) {
        rra(a);
    }
}

void sort_small_stack(t_stack *a) {
    if (a->size == 2) {
        sort_2(a);
    } else if (a->size == 3) {
        sort_3(a);
    }
}

int find_min(t_stack *stack) {
    t_node *current = stack->top;
    int min = current->value;
    while (current) {
        if (current->value < min)
            min = current->value;
        current = current->next;
    }
    return min;
}

int find_max(t_stack *stack) {
    t_node *current = stack->top;
    int max = current->value;
    while (current) {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return max;
}

int find_index(t_stack *stack, int value) {
    t_node *current = stack->top;
    int index = 0;
    while (current) {
        if (current->value == value)
            return index;
        current = current->next;
        index++;
    }
    return -1;
}

void rotate_to_top(t_stack *stack, int index, void (*rotate)(t_stack *), void (*reverse_rotate)(t_stack *)) {
    if (index <= stack->size / 2) {
        while (index > 0) {
            rotate(stack);
            index--;
        }
    } else {
        while (index < stack->size) {
            reverse_rotate(stack);
            index++;
        }
    }
}

int find_next_closest(t_stack *stack, int min, int max) {
    t_node *current = stack->top;
    int closest = max + 1;
    while (current) {
        if (current->value >= min && current->value <= max && current->value < closest) {
            closest = current->value;
        }
        current = current->next;
    }
    return closest;
}

void push_chunk_to_b(t_stack *a, t_stack *b, int min, int max) {
    int median = (min + max) / 2;
    int size = a->size;
    while (size--) {
        if (a->top->value >= min && a->top->value <= max) {
            pb(a, b);
            if (b->top->value < median) {
                rb(b);
            }
        } else {
            int next_index = find_index(a, find_next_closest(a, min, max));
            rotate_to_top(a, next_index, ra, rra);
        }
    }
}

void push_back_largest_to_a(t_stack *a, t_stack *b) {
    while (b->size > 0) {
        int max = find_max(b);
        int max_index = find_index(b, max);
        rotate_to_top(b, max_index, rb, rrb);
        pa(b, a);
    }
}

void rotate_a_to_sorted(t_stack *a) {
    int min = find_min(a);
    int min_index = find_index(a, min);
    rotate_to_top(a, min_index, ra, rra);
}

void sort_large_stack(t_stack *a, t_stack *b) {
    int chunk_count = 5;
    push_chunk_to_b(a, b, 0, a->size / chunk_count);
    push_back_largest_to_a(a, b);
    rotate_a_to_sorted(a);
}
