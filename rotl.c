#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: A pointer to the pointer of the head.
 * @line_number: Keeps track of the lines in the list.
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	first = *stack;
	last = *stack;

	while (last->next != NULL)
		last = last->next;

	*stack = first->next;
	(*stack)->prev = NULL;

	first->next = NULL;
	first->prev = last;
	last->next = first;
}
