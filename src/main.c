#include "push_swap.h"

int main(int argc, char **argv) {
    t_stack a;
    t_stack b;

    a.top = NULL;
    a.size = 0;
    b.top = NULL;
    b.size = 0;

    if (argc < 2)
        return 0;  // No input

    // Parse input and populate stack a
    parse_input(argc, argv, &a);

    if (a.size <= 3) {
        sort_small_stack(&a);
    } else {
        sort_large_stack(&a, &b);
    }


    // Free stacks
    free_stack(&a);
    free_stack(&b);

    return 0;
}
