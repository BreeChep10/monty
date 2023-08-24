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
		{NULL, NULL}
	};

	char *command;
	int i = 0;

	command = strtok(statement, " \n\t");
	for (i = 0;command && command[i]; i++)
	{
		if (command[i] == '#')
			command[i] = '\0';
	}
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




int execute(stack_t **head, unsigned int count)
{
	instruction_t opst[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{NULL, NULL}
	};
	/*
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{"sub", f_sub},
		{"div", f_div},
		{"mul", f_mul},
		{"mod", f_mod},
		{"pchar", f_pchar},
		{"pstr", f_pstr},
		{"rotl", f_rotl},
		{"rotr", f_rotr},
		{"queue", f_queue},
		{"stack", f_stack}
		{NULL, NULL}
		};*/

	int i;

	for (i = 0; opst[i].opcode; i++)
	{
		if (strcmp(monty.first, opst[i].opcode) == 0)
		{
			opst[i].f(head, count);
			if (*head)
				return (0);
		}
	}

	if (opst[i].opcode == NULL)
	{
		return (-1);
	}
	return (0);
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



void check_second(void)
{
	char *string = monty.second;
	int j = 0;
	int flag = 0;

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
}
