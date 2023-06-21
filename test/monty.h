#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void func_push(stack_t **stack, unsigned int lineNum);
void print_stack(stack_t **stack, unsigned int line_number);
void print_top(stack_t **stack, unsigned int line_number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void pop_stack(stack_t **stack, unsigned int line_number);
void swap_elements(stack_t **stack, unsigned int lineNum);
void add_top_elements(stack_t **stack, unsigned int line_number);
void perform_nop(stack_t **stack, unsigned int line_number);
void subtract(stack_t **stack, unsigned int lineNum);
void divide_top_elements(stack_t **stack, unsigned int line_number);
void multiply_top_elements(stack_t **stack, unsigned int line_number);
void compute_modulo(stack_t **stack, unsigned int line_number);
void printChar(stack_t **stack, unsigned int lineNum);
void printStackString(stack_t **stack, unsigned int lineNum);
void rstk_left(stack_t **stack,  __attribute__((unused)) unsigned int lineNum);
void rstk_right(stack_t **stack, __attribute__((unused)) unsigned int lineNum);
void add_node_to_stack(stack_t **stack_head, int new_value);
void enqueue(stack_t **stack, int n);
void setQueueMode(stack_t **stack, unsigned int lineNum);
void switch_to_stack_mode(stack_t **stack, unsigned int lineNum);

#endif
