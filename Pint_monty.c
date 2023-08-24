#include "monty.h"
/**
 *monty_pint - orints the data of the first element
 *@head: the head of the linked list
 *@line_number: line number
 *Return: nothing
 */
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
