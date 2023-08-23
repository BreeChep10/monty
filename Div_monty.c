#include "monty.h"


void monty_div(stack_t **head, unsigned int num)
{
	int total = 0, i = 0;
	stack_t *curr = *head;


	while (curr)
	{
		curr = curr->next;
		i++;
	}

	if (i < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short", num);
		fclose(monty.file);
		free(monty.Getline);
		free_stack_t(*head);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: can't div, division by zero", num);
		fclose(monty.file);
		free(monty.Getline);
		free_stack_t(*head);
		exit(EXIT_FAILURE);
	}

	curr = *head;
	total = curr->next->n / curr->n;
	curr->next->n = total;
	*head = (*head)->next;
	free(curr);
	(*head)->prev = NULL;
}
