#include "monty.h"

void monty_pint(stack_t **head, unsigned int line_number)
{
	if (!*head)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(monty.file);
		free(monty.Getline);
		free_stack_t(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
