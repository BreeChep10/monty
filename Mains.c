#include "monty.h"

swervo_t monty = {NULL, 0};

int main(int argc, char **argv)
{
	FILE *file;
/*	int count = 0;*/
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
	/*	printf("%s", store);*/
	}

	free(store);
	fclose(file);

	return (0);
}
