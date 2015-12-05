//4.Reverse an Linked list , using recursion (There are two approaches )
#include<stdio.h>
#include<stdlib.h>
//basic structure
struct node{
	int num;
	struct node *next;
};
//defining the functions
void insert(struct node **head, int Data);
void display(struct node *head);
struct node *Reverse(struct node **head);
struct node *reverse(struct node *new_node,struct node **head);
//function for inserting a new node
void insert(struct node **head, int Data)
{
	struct node *new_Node = (struct node*)malloc(sizeof(struct node));//creating a new node dynamically
	new_Node->num = Data;//assigning the values to new node
	new_Node->next = *head;
	*head = new_Node;
}//end of function insert()
//function to display the linked list
void display(struct node *ptr)
{
	while (ptr != NULL)
	{
		printf("%d->", ptr->num);
		ptr = ptr->next;
	}
	printf("NULL\n");
}//end of function display()
//function to reverse the linked list
struct node *Reverse(struct node **head)
{
	struct node *current_node;
	struct node *previous_node;
	// empty list
	if (*head == NULL)
		return 0;

	current_node = *head;
	previous_node = current_node->next;

	// List has only one node
	if (previous_node == NULL)
		return 0;

	//reverse the rest list and put the first element at the end 
	Reverse(&previous_node);
	current_node->next->next = current_node;

	
	current_node->next = NULL;

	// fix the head pointer 
	*head = previous_node;
	return *head;

}//end of the function
//second function to reverse the linked list
struct node *reverse(struct node *new_node,struct node **head)
{

	if (new_node->next == 0)
	{
		*head = new_node;
		return new_node;
	}
	else
	{
		struct node *previous_node = reverse(new_node->next, head);
		previous_node->next = new_node;
		new_node->next = 0;
		return new_node;
	}
	
}


main()
{
	struct node *head = NULL;

	int i=10;
	while (i != 0)
	{
		insert(&head, i--);
	}
	display(head);

	Reverse(&head);
	display(head);
	printf("\n");
	while (i != 0)
	{
		insert(&head, i--);
	}
	display(head);

	reverse(head,&head);
	display(head);
	return 0;
	
}

