#include "monty.h"

/**
 *handler - handles function selection
 *@statement: the command
 *@file: the input file
 *@count: the line number
 *@head: the head of the linked list
 *Return: nothing
 */
int handler(char *statement, FILE *file, unsigned int count, stack_t **head)
{
	instruction_t opst[] = {
		{"push", monty_push}, {"pall", monty_pall},
		{"pint", monty_pint}, {"pop", monty_pop},
		{"swap", monty_swap}, {"add", monty_add},
		{"nop", monty_nop}, {"div", monty_div},
		{"sub", monty_sub}, {"mul", monty_mul},
		{"mod", monty_mod}, {"pchar", monty_pchar},
		{"pstr", monty_pstr}, {"rotr", monty_rotr},
		{"rotl", monty_rotl}, {NULL, NULL}
	};
	char *command;
	int i = 0;

	command = strtok(statement, " \n\t");
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

/**
 *hash - hash handler
 *@buffer: the input string
 *Return: modified string
 */

char *hash(char *buffer)
{
	int i = 0;

	while (buffer[i] != ' ' && buffer[i] != '\t')
	{
		i++;
	}

	if (buffer[i] == '#')
	{
		return (NULL);
	}

	return (buffer);
}

/**
 *free_stack_t - frees the stack
 *@head: head of the linked list
 *Return: nothing
 */
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
