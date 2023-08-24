#include "monty.h"
/**
 *monty_push - pushes a new data to the stack
 *@head: the head of the linked list
 *@line_number: the line number
 *Return: nothing
 */
void monty_push(stack_t **head, unsigned int line_number)
{
	int n, j = 0, flag = 0;

	if (monty.second)
	{
		if (monty.second[0] == '-')
			j++;
		for (; monty.second[j] != '\0'; j++)
		{
			if (monty.second[j] > 57 || monty.second[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(monty.file), free(monty.Getline);
			free_stack_t(*head), exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(monty.file), free(monty.Getline), free_stack_t(*head);

		exit(EXIT_FAILURE); }
	n = atoi(monty.second);
	if (monty.mode == 0)
	{
		if (add_dnodeint(head, n) == NULL)
		{
			fprintf(stderr, "Error: malloc failed");
			fclose(monty.file), free(monty.Getline);
			free_stack_t(*head), exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (add_dnodeint_end(head, n) == NULL)
		{
			fprintf(stderr, "Error: malloc failed");
			fclose(monty.file), free(monty.Getline);
			free_stack_t(*head), exit(EXIT_FAILURE);
		}
	}
}
