#include "monty.h"
/**
 * mul_op - Multiplies the second top element by the top element of the stack.
 * @top: A pointer to the pointer of the head.
 * @line_number: Keeps track of the lines in the list.
 * Return: void
 */
void mul_op(stack_t **top, unsigned int line_number)
{
	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*top)->next->n *= (*top)->n;
	pop(top, line_number);
}
