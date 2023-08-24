#include "monty.h"

void monty_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	(void)(line_number);

	if (!*head)
	{
		printf("\n");
		fclose(monty.file);
		free(monty.Getline);
		free_stack_t(*head);
	}
	while (current)
	{
		if (current->n == 0 || current->n < 0 || current->n > 127)
			break;
		else
		{
			printf("%C", current->n);
			current = current->next;
		}
	}
	printf("\n");
}
