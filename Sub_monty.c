#include "monty.h"

/**
 *monty_sub - subtracts the second from the fist element
 *@head: the head of the linked list
 *@line_number: line number
 *Return: nothing
 */

void monty_sub(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int sub;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(monty.file);
		free(monty.Getline);
		free_stack_t(*head);

		exit(EXIT_FAILURE);
	}

	sub = (*head)->next->n - (*head)->n;

	(*head)->next->n = sub;
	(*head)->prev = NULL;
	*head = (*head)->next;
	free(current);
}
