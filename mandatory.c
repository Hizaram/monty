#include "monty.h"

/**
 * nop - implement the nop function
 * @stack: stack
 * @line_number: line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: stack
 * @line_number: line number
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top = NULL;
	stack_t *second = NULL;

	top = *stack;
	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	second = (*stack)->next;

	top->prev = second;
	second->prev = NULL;
	top->next = second->next;
	second->next = top;

	*stack = second;

}

/**
 * modd - finds the mod of the second element of the stack divided by the top
 * @stack: stack
 * @line_number: line number
 */

void modd(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int remainder = 0;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	remainder = temp->next->n % temp->n;
	temp->next->n = remainder;

	pop(stack, line_number);
}

/**
 * comm - implement the comments handling
 * @stack: stack
 * @line_number: line number
 */
void comm(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
