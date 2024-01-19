#include "monty.h"
/**
 * swap - Swaps the top two elements of the stack
 * @top: A pointer to the pointer of the head.
 * @line_number: Keeps track of the lines in the list.
 * Return: void
 */
void swap(stack_t **top, unsigned int line_number)
{
	stack_t *temp;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*top)->next;
	(*top)->next = temp->next;
	temp->next = *top;
	temp->prev = NULL;
	(*top)->prev = temp;

	*top = temp;
}
