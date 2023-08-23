#include "monty.h"


int handler(char *statement, FILE *file, unsigned int count)
{

	stack_t *head;
	char *command;

	head = NULL;
	command = strtok(statement, " \n\t");
	if (command && command[0] == '#')
	{
		return (0);
	}
	monty.head = &head;
	monty.first = command;
	monty.second = strtok(NULL, " \n\t");

	if (execute(&head, count) == -1)
	{
		fclose(file);
		free(statement);
		free_stack_t(head);
		exit(EXIT_FAILURE);
	}
	return (0);
}




int execute(stack_t **head, unsigned int count)
{
	instruction_t opst[] = {
		{"push", monty_push},
		{"pall", monty_pall},
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
	int flag;

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
