#include "monty.h"

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
