#include "monty.h"

/**
 *monty_rotr - reverses a stack
 *@head: the head of the linked list
 *@num: line number
 *Return: nothing
 */

void monty_rotr(stack_t **head, unsigned int num)
{
	stack_t *next, *cp, *prev;

	(void) num;
	cp = *head;
	prev = NULL;


	if (*head && (*head)->next != NULL)
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
