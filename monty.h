#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct swervo_s - global variable struct
 * @tink: tinker signature
 * @first: the first tokenized word
 * @second: the second tokenized word
 * @mode: determines whether queue or stack
 * @count: the line number
 * @head: the head of the linked list
 * @file: the input file
 * @Getline: a lin ein the input file
 *
 * Description: holds essential variables to be used during runtime
 */
typedef struct swervo_s
{
	char *tink;
	char *first;
	char *second;
	int mode;
	int count;
	stack_t **head;
	FILE *file;
	char *Getline;
} swervo_t;

extern swervo_t monty;

int handler(char *store, FILE *file, unsigned int count, stack_t **head);
int execute(stack_t **head, unsigned int count);
void free_stack_t(stack_t *head);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void monty_pall(stack_t **stack, unsigned int l __attribute__((unused)));
void monty_push(stack_t **head, unsigned int line_number);
void monty_pint(stack_t **head, unsigned int line_number);
void monty_pop(stack_t **head, unsigned int line_number);
void monty_swap(stack_t **head, unsigned int line_number);
void monty_add(stack_t **head, unsigned int line_number);
void monty_nop(stack_t **head, unsigned int line_number);
void monty_sub(stack_t **head, unsigned int line_number);
void monty_mul(stack_t **head, unsigned int line_number);
void monty_mod(stack_t **head, unsigned int line_number);
void monty_pchar(stack_t **head, unsigned int line_number);
void monty_pstr(stack_t **head, unsigned int line_number);
void monty_rotl(stack_t **head, unsigned int line_number);
void monty_div(stack_t **head, unsigned int num);
void monty_rotr(stack_t **head, unsigned int num);
void check_second(void);
char *hash(char *buffer);


#endif /*BREE<$$>LEE*/
