#include "monty.h"


void monty_rotr(stack_t **head, unsigned int num)
{
	stack_t *next, *cp, *prev;

	(void) num;
	cp = *head;
	prev = NULL;


	if (*head)
	{
		while (cp)
		{
			next = cp->next;
			cp->next = prev;
			prev = cp;
			cp = next;
		}
		*head = prev;
	}
}
