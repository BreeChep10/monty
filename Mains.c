#include "monty.h"
#include <stdio.h>
swervo_t monty = {NULL, NULL, NULL, 0, 0, NULL, NULL, NULL};
/**
 *main - entry point
 *@argc: the arguement count
 *@argv: the argument vector
 *Return: 0 on success
 */
int main(int argc, char **argv)
{
	FILE *file;
	unsigned int count = 0;
	ssize_t reads = 1;
	size_t index = 0;
	char *store;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	monty.file = file;
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (reads > 0)
	{
		store = NULL;
		reads = getline(&store, &index, file);
		monty.Getline = store;
		count++;
		monty.count = count;
		if (reads > 0)
		{
			handler(store, file, count, &head);
		}
		free(store);
	}
	fclose(file);
	free_stack_t(*(monty.head));
	return (0);
}
