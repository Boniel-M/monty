#include "monty.h"

/**
 * swap_elements - Swaps the top two elements of the stack.
 * @stack: Pointer to the stack head.
 * @lineNum: Line number.
 *
 * Return: No return value.
 */
void swap_elements(stack_t **stack, unsigned int lineNum)
{
	stack_t *temp;
	int len = 0, aux;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", lineNum);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	aux = temp->n;
	temp->n = temp->next->n;
	temp->next->n = aux;
}
