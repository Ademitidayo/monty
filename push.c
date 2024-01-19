#include "monty.h"

/**
 * check_int - To check if eachh char in a string is digit.
 * @string: The string
 * Return: 1 on success
 */
int check_int(const char *string)
{
	if (string == NULL || *string == '\0')
		return (0);
	while (*string != '\0')
	{
		if (!isdigit(*string) && *string != '-' && *string != '+')
		{
			return (0);
		}
		string++;
	}

	return (1);
}

/**
 * push - To add items to the list.
 * @top: A pointer to the pointer of the head.
 * @line_number: Keeps track of the lines in the list.
 * Return: void
 */
void push(stack_t **top, unsigned int line_number)
{
	stack_t *new_item;
	char *added_arg;
	int num;

	added_arg = strtok(NULL, " \t\n");
	if (added_arg == NULL || !check_int(added_arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(added_arg);

	new_item = malloc(sizeof(stack_t));
	if (new_item == NULL)
	{
		return;
	}

	new_item->n = num;
	new_item->prev = NULL;
	new_item->next = *top;

/*	new_item->next = *top;
*/
	if (*top != NULL)
	{
		(*top)->prev = new_item;
	}
	*top = new_item;
}

/**
 * pall - To print all values in the list.
 * @top: A pointer to the pointer of the head.
 * @line_number: Keeps track of the lines in the list.
 * Return: void
 */
void pall(stack_t **top, unsigned int line_number)
{
	stack_t *first;
	(void)line_number;

	first = *top;

	while (first != NULL)
	{
		printf("%d\n", first->n);
		first = first->next;
	}
}
