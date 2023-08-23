#include "monty.h"

/**
 *add_dnodeint_end - at a node at the end
 *@head: the head of the linked list
 *@n: the  data
 *Return: pointer to the new data
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new,  *h;


	new = malloc(sizeof(stack_t));

	if (!new)
	{
		return (NULL);
	}

	new->next = NULL;
	new->n = n;

	h = *head;

	if (h != NULL)
	{
		while (h->next)
		{
			h = h->next;
		}
	}

	new->prev = h;

	if (h)
	{
		h->next = new;
	}

	*head = new;

	return (new);
}
