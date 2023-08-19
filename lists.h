#ifndef LISTSH
#define LISTSH
#include <unistd.h>

/**
* struct list_s - Node of a singly linked list
 * @str: String data associated with the node
 * @val: Value string data associated with the node
 * @len: Length of the string data
 * @valLen: Length of the value string data
 * @next: Pointer to the next node in the list
 *
 * Description: This structure defines a node in a singly linked list
 * used in the ALX shell project to manage data.
*/

typedef struct list_s
{
	char *string;
	char *val;
	unsigned int len;
	unsigned int valLen;
	struct list_s *next;
} list_t;

int _putchar(char c);

size_t print_list(list_t *h);

size_t list_len(list_t *h);

list_t *add_node(list_t **head, char *string, char *val);

void free_list(list_t *head);

list_t *get_node(list_t *head, char *string);


#endif
