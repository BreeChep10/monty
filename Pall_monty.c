#include "monty.h"


/**
 *monty_pall - prints all the elments
 *@stack: the head of the linkes list
 *@l: the line number
 *Return: nothing
 */


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
