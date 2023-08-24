#include "monty.h"

/**
 *monty_pop - removes the first element
 *@head: the head of the linked list
 *@line_number: the line number
 *Return: nothing
 */
void monty_pop(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (!*head)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);

		fclose(monty.file);
		free(monty.Getline);
		free_stack_t(*head);

		exit(EXIT_FAILURE);
	}
	*head = (*head)->next;

	if (*head != NULL)
		(*head)->prev = NULL;

	free(current);
}
