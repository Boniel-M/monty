#include "monty.h"

/**
 * add_node_to_stack - Adds a new node to the head of the stack.
 * @stack_head: Pointer to the head of the stack.
 * @new_value: New value to be added.
 * Return: No return value.
 */
void add_node_to_stack(stack_t **stack_head, int new_value)
{
	stack_t *new_node, *temp;

	temp = *stack_head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (temp)
		temp->prev = new_node;
	new_node->n = new_value;
	new_node->next = *stack_head;
	new_node->prev = NULL;
	*stack_head = new_node;
}
