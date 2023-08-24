#include "monty.h"

void monty_mul(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int mul;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(monty.file);
		free(monty.Getline);
		free_stack_t(*head);
		exit(EXIT_FAILURE);
	}
	mul = current->next->n * current->n;
	current->next->n = mul;
	*head = current->next;
	free(current);
}
