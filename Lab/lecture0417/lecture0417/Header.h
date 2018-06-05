#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum boolean
{
	FALSE,TRUE
}Boolean;
typedef struct node
{
	char item_name[100];
	struct node *next_ptr;

}Node;
Node * make_node(char *new_item);
Boolean insert_at_front(Node **head_ptr,char *new_item);
Boolean insert_in_order(Node **head_ptr, char *new_item);
Boolean delete_item(Node **head_ptr, char *new_item);
void print_list(Node *head_ptr);