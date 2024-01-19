#include "monty.h"
/**
 * pop - To remove the element on top
 * @top: A pointer.
 * @line_number: Keeps track of the line.
 * Return: void
 */
void pop(stack_t **top, unsigned int line_number)
{
	stack_t *remove;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	remove = *top;
	*top = (*top)->next;

	if (*top != NULL)
	{
		(*top)->prev = NULL;
	}
	remove->next = NULL;
	free(remove);
}
