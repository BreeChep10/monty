#include "monty.h"

swervo_t monty = {NULL, 0};

int main(int argc, char **argv)
{
	FILE *file;
	unsigned int count = 0;
	ssize_t reads = 1;
	size_t index = 0;
	char *store = NULL;
	stack_t *head;

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
			if (handler(store) == -1)
			{
				fclose(file);
				free(store);
				exit(EXIT_FAILURE);
			}
		free(store);
	}
	fclose(file);

	return (0);
}
