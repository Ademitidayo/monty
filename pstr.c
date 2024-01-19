#include "monty.h"
/**
 * pstr - Prints the string starting at the top of the stack.
 * @top: A pointer to the pointer of the head.
 * @line_number: Keeps track of the lines in the list.
 * Return: void
 */
void pstr(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;

	while (current != NULL && current->n != 0 && (current->n >= 0 && current->n <= 127))
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
	(void)line_number;
}
