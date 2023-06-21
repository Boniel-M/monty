#include "monty.h"

/**
 * rstk_left - Rotates the stack to the top.
 * @stack: Pointer to the stack head.
 * @lineNum: Line number (unused).
 *
 * Return: No return value.
 */
void rstk_left(stack_t **stack,  __attribute__((unused)) unsigned int lineNum)
{
	stack_t *tmp = *stack, *aux;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	aux = (*stack)->next;
	aux->prev = NULL;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp;
	(*stack) = aux;
}
