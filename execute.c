#include "monty.h"
/**
 * execute - executes the opcode
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: pointer to monty file
 * @content: line content
 * Return: no return
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] =
	{
		{"pint", print_top},
		{"push", func_push},
		{"mul", multiply_top_elements},
		{"pop", pop_stack},
		{"pchar", printChar},
		{"mod", compute_modulo},
		{"sub", subtract},
		{"queue", setQueueMode},
		{"pall", print_stack},
		{"rotr", rstk_right},
		{"swap", swap_elements},
		{"rotl", rstk_left},
		{"pstr", printStackString},
		{"stack", switch_to_stack_mode},
		{"div", divide_top_elements},
		{"add", add_top_elements},
		{"nop", perform_nop},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	if (bus.arg)
	{
		size_t arg_len = strlen(bus.arg);

		if (arg_len > 0 && bus.arg[arg_len - 1] == '$')
			bus.arg[arg_len - 1] = '\0';
	}
	if (op)
	{
		size_t opcode_len = strlen(op);

		if (opcode_len > 0 && op[opcode_len - 1] == '$')
			op[opcode_len - 1] = '\0';
	}
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
