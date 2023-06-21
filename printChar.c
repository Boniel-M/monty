#include "monty.h"

/**
 * printChar - Prints the character at the top of the stack,
 * followed by a new line.
 * @stack: Pointer to the stack head.
 * @lineNum: Line number.
 *
 * Return: No return value.
 */
void printChar(stack_t **stack, unsigned int lineNum)
{
	stack_t *current;

	current = *stack;
	if (!current)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lineNum);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (current->n > 127 || current->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", lineNum);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", current->n);
}
