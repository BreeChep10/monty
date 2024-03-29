#include "monty.h"
/**
 *monty_pstr - prints the string at the top of the stack
 *@head: head of the linked list
 *@line_number: line number
 *Return: nothing
 */
void monty_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	(void)(line_number);

	if (!*head)
	{
		printf("\n");
		fclose(monty.file);
		free(monty.Getline);
		free_stack_t(*head);

		return;
	}
	while (current)
	{
		if (current->n == 0 || current->n > 127 || current->n < 0)
			break;
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
