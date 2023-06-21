#include "monty.h"

/**
 * switch_to_stack_mode - Switches to stack mode.
 * @stack: Pointer to the stack head.
 * @lineNum: Line number (unused).
 *
 * Return: No return value.
 */
void switch_to_stack_mode(stack_t **stack, unsigned int lineNum)
{
	(void)stack;
	(void)lineNum;
	bus.lifi = 0;
}
