#include "monty.h"

void push_monty(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack_t(*stack);
		exit(EXIT_FAILURE);
	}
	if (!monty.first)
	{
		fprintf(stderr, "L<line_number>: usage: push integer\n", line_number);
		free_stack_t(*stack);
		exit(EXIT_FAILURE);
	}
	value = atoi(monty.second);

	new_node->n = value;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
