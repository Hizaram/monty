#include "monty.h"

/**
 * push - adds an element on the stack
 * @stack: stack
 * @line_number: line number
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;

	(void) line_number;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = global_var;
	new->prev = NULL;

	if (*stack == NULL)
	{
		new->next = NULL;
		*stack = new;
		return;
	}
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: stack
 * @line_number: line number
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	(void) line_number;
	temp = *stack;
	if ((*stack) == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: stack
 * @line_number: line number
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	printf("%d\n", temp->n);
}

/**
 * pop - pop top node in stack
 * @stack: stack
 * @line_number: line number
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * get_func - matches opcode from input to existing opcode in struct
 * @op: character to check
 * @stack: stack
 * @line_number: line number
 *
 * Return: the pointer to the appropriate function or NULL if nothing matches
 */

void get_func(char *op, stack_t **stack, unsigned int line_number)
{
	instruction_t find_op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"add", add},
		{"swap", swap},
		{"sub", sub},
		{"div", divi},
		{"mul", mul},
		{"mod", modd},
		{NULL, NULL}
	};
	int index = 0;

	while (find_op[index].opcode != NULL)
	{
		if (opcode[0] == "#")
			return;
		if (strcmp(find_op[index].opcode, op) == 0)
		{
			find_op[index].f(stack, line_number);
			return;
		}
		index++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
	exit(EXIT_FAILURE);
}
