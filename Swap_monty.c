#include "monty.h"

void monty_swap(stack_t **head, unsigned int line_number)
{
	int current;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(monty.file);
		free(monty.Getline);
		free_stack_t(*head);
		exit(EXIT_FAILURE);
	}

	current = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = current;
}
