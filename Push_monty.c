#include "monty.h"
/*
void monty_push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *string = monty.second;
	int j = 0;
	int flag = 0;


	if (!monty.second)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack_t(*stack);
		free(monty.Getline);
		fclose(monty.file);
		exit(EXIT_FAILURE);
	}

	if (string[0] == '-')
			j++;
	for (j = 0; string[j]; j++)
	{
		if (string[j] > 57 || string[j] < 48)
			flag = 1;
	}

	if (flag == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", monty.count);
		fclose(monty.file);
		free(monty.Getline);
		free_stack_t(*(monty.head));
		exit(EXIT_FAILURE);
	}

	value = atoi(monty.second);
	*stack = add_dnodeint(stack, value);

}
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
			fclose(monty.file);
			free(monty.Getline);
			free_stack_t(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(monty.file);
		free(monty.Getline);
		free_stack_t(*head);
		exit(EXIT_FAILURE); }
	n = atoi(monty.second);
	if (monty.mode == 0)
		if (add_dnodeint(head, n) == NULL)
		{
			fprint(stderr, "Error: malloc failed");
			fclose(monty.file);
			free(monty.Getline);
			free_stack_t(head);
			exit(EXIT_FAILURE);
		}
	else
		if (add_dnodeint_end(head, n); == NULL)
		{
			fprint(stderr, "Error: malloc failed");
			fclose(monty.file);
			free(monty.Getline);
			free_stack_t(head);
			exit(EXIT_FAILURE);
		}
}
