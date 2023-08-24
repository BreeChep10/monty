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
		return;
	}
	while (current && current->n > 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
