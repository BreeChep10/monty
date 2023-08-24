#include "monty.h"

/**
 *monty_pchar - prits the first character of the first element
 *@head: the head of the linked list
 *@line_number:line number
 *Return: nothing
 */
void monty_pchar(stack_t **head, unsigned int line_number)
{
	if (!*head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(monty.file);
		free(monty.Getline);
		free_stack_t(*head);

		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(monty.file);
		free(monty.Getline);
		free_stack_t(*head);

		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
