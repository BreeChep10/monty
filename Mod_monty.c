#include "monty.h"

void monty_mod(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int result;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(monty.file);
		free(monty.Getline);
		free_stack_t(*head);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(monty.file);
		free(monty.Getline);
		free_stack_t(*head);
		exit(EXIT_FAILURE);
	}

	result = (*head)->next->n % (*head)->n;
	(*head)->next->n = result;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(current);
}
