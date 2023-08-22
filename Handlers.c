#include "monty.h"


int handler(char *statement, FILE *file, unsigned int count)
{

	stack_t *head;
	char *command, char *data;

	command = strtok(statement, " \n\t");

	if (command && command[0] == '#')
	{
		return (0);
	}

	swervo_t.second = strtok(NULL, " \n\t");

	
}




int execute(stack_t **head, unsigned int count)
{
	instruction_t opst[] = {
		{"push", f_push},
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
		{"stack", f_stack},
		{NULL, NULL}
	};

	int i = 0
