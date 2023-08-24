#include "monty.h"


int handler(char *statement, FILE *file, unsigned int count, stack_t **head)
{
	instruction_t opst[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{"div", monty_div},
		{"sub", monty_sub},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{NULL, NULL}
	};
	char *command;
	int i = 0;

	statement = hash(statement);
	command = strtok(statement, " \n\t");
	if (!command)
		return (0);
	i = 0, monty.head = head, monty.first = command;
	monty.second = strtok(NULL, " \n\t");
	while (opst[i].opcode && command)
	{
		if (strcmp(command, opst[i].opcode) == 0)
		{
			opst[i].f(head, count);
			return (0);
		}
		i++;
	}

	if (command && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, command);
		fclose(file);
		free(statement);
		free_stack_t(*head);
		exit(EXIT_FAILURE);
	}
	return (0);
}


char *hash(char *buffer)
{
	int i;
	bool quotes = false;

	if (buffer[0] == '#')
	{
		free(buffer);
		return (NULL);
	}

	else
	{
		for (i = 0; buffer[i]; i++)
		{
			if (buffer[i] == 34)
			{
				quotes = !quotes;
			}

			if (!quotes && buffer[i] == '#' && buffer[i - 1] == ' ')
			{
				buffer[i] = '\0';
				break;
			}
		}
	}

	return (buffer);
}

void free_stack_t(stack_t *head)
{
	stack_t *current;

	if (!head)
	{
		return;
	}

	while (head)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
