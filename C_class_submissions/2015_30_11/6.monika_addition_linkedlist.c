//6.Write a program to add two linked list(Each node is represented by a digit) (Note: Unequal Lengths can also be given)
//Ex: Input 1->2->3->4 and 1->2->3->4
	//Output 2->4->6->8

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Linked list node */
struct node
{
	int data;
	struct node* next;
};
struct node *create(struct node *head);
struct node *insert_s(struct node *head, int data);
struct node* addTwoLists(struct node* first, struct node* second);
void display(struct node *node);

/* Function to create a new node with given data */
struct node *create(struct node *head)
{
	int index, num, data;
	printf("Enter the number of nodes : ");
	scanf_s("%d", &num);
	head = NULL;
	for (index = 1; index <= num; index++)
	{
		printf("Enter the element to be inserted : ");
		scanf_s("%d", &data);
		head = insert_s(head, data);
	}
	return head;
}//End of create_slist()

struct node *insert_s(struct node *head, int data)
{
	struct node *list, *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	//list empty or data to be added in beginning 
	if (head == NULL || data<head->data)
	{
		temp->next = head;
		head = temp;
		return head;
	}
	else
	{
		list = head;
		while (list->next != NULL && list->next->data < data)
			list = list->next;
		temp->next = list->next;
		list->next = temp;
	}
	return head;
}//End of insert_s()

struct node *newNode(int data)
{
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}
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
/* Adds contents of two linked lists and return the head node of resultant list */
struct node* addTwoLists(struct node* list1, struct node* list2)
{
	struct node* res = NULL; 
	struct node *temp=0, *prev = NULL;
	int carry = 0, sum;

	while (list1 != NULL || list2 != NULL)
	{
	
		if (list1==NULL)
			sum = carry+list2->data;
		else if (list2==NULL)
			sum = carry+list1->data;
		else
			sum = carry + list1->data + list2->data;
		

		// update carry for next calulation
		if (sum >= 10)
			carry = 1;
		else
			carry = 0;
		

		// update sum if it is greater than 10
		sum = sum % 10;

		// Create a new node with sum as data
		temp = newNode(sum);

		// if this is the first node then set it as head of the resultant list
		if (res == NULL)
			res = temp;
		else // If this is not the first node then connect it to the rest.
			prev->next = temp;

		// Set prev for next insertion
		prev = temp;

		// Move first and second pointers to next nodes
		if (list1) list1 = list1->next;
		if (list2) list2 = list2->next;
	}

	if (carry > 0)
		temp->next = newNode(carry);

	// return head of the resultant list
	return res;
}

// A utility function to print a linked list
void display(struct node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

/* Drier program to test above function */
int main(void)
{
	struct node *list1 = NULL, *list2 = NULL,*list3=NULL;
	list1 = create(list1);
	Reverse(&list1);//calling the function create
	list2 = create(list2);
	Reverse(&list2);
	//printing the lists by calling  the function dispaly
	list3=addTwoLists(list1, list2);
	Reverse(&list3);
	display(list3);
}

