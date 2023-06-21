#include "monty.h"

/**
 * printStackString - Prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: Pointer to the stack head.
 * @lineNum: Line number (not used).
 *
 * Return: No return value.
 */
void printStackString(stack_t **stack, unsigned int lineNum)
{
	stack_t *curr;
	(void)lineNum;

	curr = *stack;
	while (curr)
	{
		if (curr->n > 127 || curr->n <= 0)
		{
			break;
		}
		printf("%c", curr->n);
		curr = curr->next;
	}
	printf("\n");
}
