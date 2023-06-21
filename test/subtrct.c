#include "monty.h"

/**
 * subtract - Subtracts the top element of the stack from the second top element.
 * @stack: Pointer to the stack head.
 * @lineNum: Line number.
 *
 * Return: No return value.
 */
void subtract(stack_t **stack, unsigned int lineNum)
{
	stack_t *temp;
	int result, count;

	temp = *stack;
	for (count = 0; temp != NULL; count++)
		temp = temp->next;
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lineNum);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	result = temp->next->n - temp->n;
	temp->next->n = result;
	*stack = temp->next;
	free(temp);
}
