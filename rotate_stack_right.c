#include "monty.h"

/**
 * rstk_right - Rotates the stack to the bottom.
 * @stack: Pointer to the stack head.
 * @lineNum: Line number (unused).
 *
 * Return: No return value.
 */
void rstk_right(stack_t **stack, __attribute__((unused)) unsigned int lineNum)
{
	stack_t *copy;

	copy = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	while (copy->next)
	{
		copy = copy->next;
	}

	copy->next = *stack;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*stack)->prev = copy;
	(*stack) = copy;
}
