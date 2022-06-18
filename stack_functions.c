#include "monty.h"
/**
 * op_push - Pushes an element to the stack
 * @stack: doubly linked list representation of the stack
 * @line_number: line number of the instruction
 * Return: void
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	(void) line_number;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = arg;
	if (*stack == NULL)
		new_node->next = NULL;
	else
		new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}
/**
 * op_pall - Prints all elements of the stack
 * @stack: doubly linked list representation of the stack
 * @line_number: Line number of the instruction
 * Return: void
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	const stack_t *ptr;
	(void) line_number;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	ptr = *stack;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
/**
 * op_pint - Prints the value at the top of the stack
 * @stack: doubly linked list representation of the stack
 * @line_number: Line number of the instruction
 * Return: void
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		error_func(line_number, 2);
	printf("%d\n", (*stack)->n);
}
/**
 * op_pop - Removes the top element of the stack.
 * @stack: doubly linked list representation of the stack
 * @line_number: Line number of the instruction
 * Return: void
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL)
		error_func(line_number, 3);

	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		ptr = (*stack)->next;
		(*stack) = ptr;
		ptr = ptr->prev;
		(*stack)->prev = NULL;
		free(ptr);
	}
}
/**
 * op_swap - swaps top two elements of the stack
 * @stack: doubly linked list representation of the stack
 * @line_number: Line number of the instruction
 * Return: void
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
		error_func(line_number, 4);
	ptr = (*stack)->next;
	(*stack)->prev = ptr;
	(*stack)->next = ptr->next;
	ptr->prev = NULL;
	ptr->next = *stack;
	*stack = ptr;
}
