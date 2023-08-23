#include "monty.h"
#include <stdio.h>

swervo_t monty = {NULL, NULL, NULL, 0, NULL};

int main(int argc, char **argv)
{
	FILE *file;
	unsigned int count = 0;
	ssize_t reads = 1;
	size_t index = 0;
	char *store = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "L<line_number>: usage: push integer\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file <file>\n");
		exit(EXIT_FAILURE);
	}
	while (reads > 0)
	{
		reads = getline(&store, &index, file);
		count++;
		if (reads > 0)
		{
			handler(store, file, count);
		}
		free(store);
	}
	free(store);
	fclose(file);
	free_stack_t(*(monty.head));
	return (0);
}
