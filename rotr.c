#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: A pointer to the pointer of the head.
 * @line_number: Keeps track of the lines in the list.
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *secondLast;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	secondLast = *stack;

	while (last->next != NULL)
	{
		secondLast = last;
		last = last->next;
	}

	secondLast->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}
