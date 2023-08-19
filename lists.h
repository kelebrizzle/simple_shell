#ifndef LISTSH
#define LISTSH
#include <unistd.h>

/**
* struct list_s - Node of a singly linked list
 * @stri_ng: String data associated with the node
 * @val_u: Value string data associated with the node
 * @len: Length of the string data
 * @val_len: Length of the value string data
 * @next: Pointer to the next node in the list
 *
 * Description: This structure defines a node in a singly linked list
 * used in the ALX shell project to manage data.
*/

typedef struct list_s
{
	char *stri_ng;
	char *val_u;
	unsigned int len;
	unsigned int val_len;
	struct list_s *next;
} list_t;

int _putchar(char c);

size_t print_list(list_t *h);

size_t list_len(list_t *h);

list_t *add_node(list_t **head, char *stri_ng, char *val_u);

void free_list(list_t *head);

list_t *get_node(list_t *head, char *stri_ng);


#endif
