#include "monty.h"
/**
 * mod_op - Computes the rest of the division of the second top element by the top element.
 * @top: A pointer to the pointer of the head.
 * @line_number: Keeps track of the lines in the list.
 * Return: void
 */
void mod_op(stack_t **top, unsigned int line_number)
{
	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*top)->next->n %= (*top)->n;
	pop(top, line_number);
}
