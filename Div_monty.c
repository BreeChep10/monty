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
		fprintf(stderr, "L%d: can't div, stack too short\n", num);
		fclose(monty.file);
		free(monty.Getline);
		free_stack_t(*head);
		exit(EXIT_FAILURE);
	}

	curr = *head;
	if (curr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num);
		fclose(monty.file);
		free(monty.Getline);
		free_stack_t(*head);
		exit(EXIT_FAILURE);
	}

	total = curr->next->n / curr->n;
	curr->next->n = total;
	*head = curr->next;
	(*head)->prev = NULL;
	free(curr);
}
