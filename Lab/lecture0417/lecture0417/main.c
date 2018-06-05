#include "Header.h"

int main(void)
{
	Node item1 = { "Milk" };
	//Node grocery_list[15] = { "Milk","Eggs","Bread" };

	Node *head_ptr = NULL;
	insert_in_order(&head_ptr, "Bananas");
	insert_in_order(&head_ptr, "Apples");
	insert_in_order(&head_ptr, "Artichokes");
	insert_in_order(&head_ptr, "");
	insert_in_order(&head_ptr, "Eggs");

	
	print_list(head_ptr);

	delete_item(&head_ptr, "Artichokes");
	insert_at_front(head_ptr, "Milk");
	printf("Product descr: %s\n", head_ptr->item_name);
	head_ptr = (Node *) malloc(sizeof(Node)); // placed on heap - memory store
	strcpy(head_ptr->item_name, "Milk");
	head_ptr->next_ptr = NULL;

	puts(head_ptr->item_name);




	return 0;
}