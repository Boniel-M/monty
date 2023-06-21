#include "monty.h"

/**
 * pop_stack - Removes the top element of the stack.
 * @stack: Pointer to the stack head.
 * @line_number: Line number.
 * Return: No return value.
 */
void pop_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	*stack = current->next;
	free(current);
}
