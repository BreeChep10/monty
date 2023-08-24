#include "monty.h"

void monty_rotl(stack_t **head, unsigned int line_number)
{
	stack_t *first, *last;

	(void)(line_number);

	if (!head || !(*head)->next)
		return;
	first = (*head)->next;
	last = (*head)->next;

	while (last->next)
	{
		last = last->next;
	}
	first->next->prev = *head;
	(*head)->next = first->next;
	last->next = first;
	first->next = NULL;
	first->prev = last;
}
