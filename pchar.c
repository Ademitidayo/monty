#include "monty.h"

/**
 * pchar - Prints the char at the top of the stack.
 * @top: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void pchar(stack_t **top, unsigned int line_number)
{
	int ascii_value = (*top)->n;

	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (ascii_value < 0 || ascii_value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(ascii_value);
	putchar('\n');
}
