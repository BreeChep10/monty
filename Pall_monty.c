#include "monty.h"

void monty_pall(stack_t **stack, unsigned int l __attribute__((unused)))
{
	stack_t *current = *stack;

	if (current == NULL)
	{
		return;
	}

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
