#include "monty.h"
/**
 * op_add - adds the n value of the top two node, then pops.
 * @stack: doubly linked list representation of the stack (void)
 * @line_number: Line number of the instruction (void)
 * Return: void
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		error_func(line_number, 5);
	}
	ptr = *stack;
	if (ptr->next == NULL)
		error_func(line_number, 5);
	ptr->next->n += (*stack)->n;
	*stack = (*stack)->next;
	free(ptr);
	(*stack)->prev = NULL;
}

/**
 * op_sub - subtracts the n value of the top two node, then pops.
 * @stack: doubly linked list representation of the stack (void)
 * @line_number: Line number of the instruction (void)
 * Return: void
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		error_func(line_number, 6);
	}
	ptr = *stack;
	if (ptr->next == NULL)
		error_func(line_number, 6);
	ptr->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	free(ptr);
	(*stack)->prev = NULL;
}

/**
 * op_mul - multiplies the n value of the top two node, then pops.
 * @stack: doubly linked list representation of the stack (void)
 * @line_number: Line number of the instruction (void)
 * Return: void
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
		error_func(line_number, 9);
	ptr = *stack;
	if (ptr->next == NULL)
		error_func(line_number, 9);
	ptr->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	free(ptr);
	(*stack)->prev = NULL;
}
/**
 * op_div - divides the n value of the top two node, then pops.
 * @stack: doubly linked list representation of the stack (void)
 * @line_number: Line number of the instruction (void)
 * Return: void
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		error_func(line_number, 7);
	}
	ptr = *stack;
	if (ptr->n == 0)
		error_func(line_number, 8);
	if (ptr->next == NULL)
		error_func(line_number, 7);
	ptr->next->n /= (*stack)->n;
	*stack = (*stack)->next;
	free(ptr);
	(*stack)->prev = NULL;
}
/**
 * op_mod - mods the n value of the top two node, then pops.
 * @stack: doubly linked list representation of the stack (void)
 * @line_number: Line number of the instruction (void)
 * Return: void
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
		error_func(line_number, 10);
	ptr = *stack;
	if (ptr->n == 0)
		error_func(line_number, 11);
	if (ptr->next == NULL)
		error_func(line_number, 10);
	ptr->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	free(ptr);
	(*stack)->prev = NULL;
}
