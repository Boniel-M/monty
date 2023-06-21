#include "monty.h"

/**
 * func_push - Adds a node to the stack.
 *
 * @stack: Pointer to the stack head.
 * @lineNum: Line number.
 *
 * Return: No return value.
 */
void func_push(stack_t **stack, unsigned int lineNum)
{
	int value, i = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			i++;
		for (; bus.arg[i] != '\0'; i++)
		{
			if (bus.arg[i] > '9' || bus.arg[i] < '0')
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%u: usage: push integer\n", lineNum);
			fclose(bus.file);
			free(bus.content);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", lineNum);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	value = atoi(bus.arg);

	if (bus.lifi == 0)
	{
		add_node_to_stack(stack, value);
	}
	else
	{
		enqueue(stack, value);
	}
}
