#include "monty.h"

/**
 *monty_add - adds the first two elements
 *@head: the head of the linked list
 *@line_number: the line counter
 *Return: nothing
 */
void monty_add(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int sum;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(monty.file);
		free(monty.Getline);
		free_stack_t(*head);
		exit(EXIT_FAILURE);
	}
	sum = (*head)->n + (*head)->next->n;
	(*head)->next->n = sum;
	*head = (*head)->next;
	(*head)->prev = NULL;

	free(current);
}
