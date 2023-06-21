#include "monty.h"

/**
 * multiply_top_elements - Multiplies the top two elements of the stack.
 * @stack: Pointer to the stack head.
 * @line_number: Line number.
 * Return: No return value.
 */
void multiply_top_elements(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int length = 0, product;

	current = *stack;
	while (current)
	{
		current = current->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	product = current->next->n * current->n;
	current->next->n = product;
	*stack = current->next;
	free(current);
}
