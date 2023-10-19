#include "monty.h"
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

void pop(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
        free_vglo(stack);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->next != NULL)
    {
        *stack = (*stack)->next;
        free((*stack)->prev);
        (*stack)->prev = NULL;
    }
    else
    {
        free(*stack);
        *stack = NULL;
    }
}

