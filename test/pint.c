#include "monty.h"

void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
        free_all(stack);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

