#include "monty.h"

/**
 * setQueueMode - Sets the stack mode to queue (FIFO).
 *
 * @stack: Pointer to the stack head.
 * @lineNum: Line number (not used).
 *
 * Return: No return value.
 */
void setQueueMode(stack_t **stack, unsigned int lineNum)
{
	(void)stack;
	(void)lineNum;
	bus.lifi = 1;
}

/**
 * enqueue - Adds a node to the tail of the stack.
 * @n: New value.
 * @stack: Pointer to the stack head.
 *
 * Return: No return value.
 */
void enqueue(stack_t **stack, int n)
{
	stack_t *newNode, *aux;

	aux = *stack;
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = n;
	newNode->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
		aux->next = newNode;
		newNode->prev = aux;
	}
	else
	{
		*stack = newNode;
		newNode->prev = NULL;
	}
}
