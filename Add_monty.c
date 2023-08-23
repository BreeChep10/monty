#include "monty.h"

void monty_add(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int sum;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		fclose(monty.file);
		free(monty.Getline);
		free_stack_t(*head);
		exit(EXIT_FAILURE);
	}
	sum = current->n + current->next->n;
	current->next->n = sum;
	*head = current->next;
	free(current);
}
