#include "monty.h"

void monty_push(stack_t **stack, unsigned int line_number)
{
	int value;

	if (!monty.second)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack_t(*stack);
		free(monty.Getline);
		fclose(monty.file);
		exit(EXIT_FAILURE);
	}
	check_second();
	value = atoi(monty.second);
	*stack = add_dnodeint(stack, value);

/*	new_node->n = value;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;
		*stack = new_node;*/
}
