#include "Header.h"

Node * make_node(char *new_item)
{
	// allocate space on heap
	Node *mem_ptr = NULL;

	mem_ptr = (Node *)malloc(sizeof(Node));

	if (mem_ptr != NULL) // we were able to allocate a block on the heap
	{
		// initialize the block of memory
		mem_ptr->next_ptr = NULL; // always set next_ptr to NULL in Node
								  // initialize the product description
		strcpy(mem_ptr->item_name, new_item); // (*mem_ptr).
	}

	return mem_ptr; // return the starting address of the new block of memory
}

Boolean insert_at_front(Node **head_ptr, char *new_item)
{
	Node *mem_ptr = make_node(new_item);
	Boolean success = FALSE;

	if (mem_ptr != NULL)
	{
		success = TRUE;
		mem_ptr->next_ptr = (*head_ptr);
		(*head_ptr) = mem_ptr;
	}
	return success;
}

void print_list(Node *head_ptr)
{
	printf("-->");

	while (head_ptr != NULL)
	{
		printf("%s--> ",head_ptr->item_name);
		head_ptr = head_ptr->next_ptr;
	}
}

Boolean insert_in_order(Node **head_ptr, char *new_item)
{
	Node *mem_ptr = NULL,*cur_ptr=NULL, *prev_ptr=NULL;
	Boolean success = FALSE;
	mem_ptr = make_node(new_item);

	if (mem_ptr != NULL)//if successful at alocating space
	{
		success = TRUE;

		cur_ptr = *head_ptr; //set curptr to head of the list;
		//find the place in the list to insert
		while ((cur_ptr!=NULL)&&strcmp(mem_ptr->item_name,cur_ptr->item_name) > 0)
		{
			//go to next node in list, simply tracking
			prev_ptr = cur_ptr;
			cur_ptr = cur_ptr->next_ptr;
		}
		if (prev_ptr != NULL)
		{
			prev_ptr->next_ptr = mem_ptr;
			mem_ptr->next_ptr = cur_ptr;
		}
		else //insert at front - empy list
		{
			mem_ptr->next_ptr = cur_ptr;
			*head_ptr = mem_ptr;
		}
	}
	return success;
}

Boolean delete_item(Node **head_ptr, char *new_item)
{
	Node *cur_ptr = *head_ptr, *prev_ptr = NULL;
	Boolean success = FALSE;
	while ((cur_ptr != NULL)&& (!success))
	{
		if (strcmp(cur_ptr->item_name, new_item) == 0)
		{
			success = TRUE;
		}
		else
		{
			//advance through list
			prev_ptr = cur_ptr;
			cur_ptr = cur_ptr->next_ptr;
		}

	}
	if (success)
	{
		if (prev_ptr != NULL)
		{
			prev_ptr->next_ptr = cur_ptr->next_ptr;
			free(cur_ptr);
		}
		else
		{
			*head_ptr = cur_ptr->next_ptr;
			free(cur_ptr);
		}
	}
	return success;
}