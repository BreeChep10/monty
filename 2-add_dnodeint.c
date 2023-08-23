#include "monty.h"

/**
 *add_dnodeint - adds a new node
 *@head: the head of the linked list
 *@n: the data
 *Return: the head of the list
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new,  *h;


	new = malloc(sizeof(stack_t));

	if (!new)
	{
		return (NULL);
	}

	new->prev = NULL;
	new->n = n;

	h = *head;

	if (h != NULL)
	{
		while (h->prev)
		{
			h = h->prev;
		}
	}

	new->next = h;

	if (h)
	{
		h->prev = new;
	}

	*head = new;

	return (new);
}
