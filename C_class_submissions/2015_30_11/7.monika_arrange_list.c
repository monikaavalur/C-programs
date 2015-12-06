//7.Sorted a linked list which is in ascending order but two numbers are changed ,i mean not in the usual order they need to be 

//Ex: 1->2->3->15->10->4->20; O / p:1 - 2 - 3 - 4 - 10 - 15 - 20

#include<stdio.h>
#include<stdlib.h>

// Linked list node
struct node
{
	int data;
	struct node* next;
};
//defining the functions
struct node *create(struct node *head);
void display(struct node *node);
struct node *rearrange(struct node **head);
struct node *insert_s(struct node *head, int data);

// Function to create a new node with given data 
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
//function to display the linked list
void display(struct node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}//end of display()
//function to rearrange the linked list
struct node *rearrange(struct node **head)
{
	struct node *ptr = *(head);
	struct node *ptr1 =ptr->next;
	//loop to traverse the linked list to sort the list
	while (ptr1 != NULL)
	{
		if (ptr->data >ptr1->data )
		{
			struct node *temp = ptr->data;
			ptr->data = ptr1->data;
			ptr1->data = temp;
		}
		ptr = ptr->next;
		ptr1 = ptr1->next;
	}
	ptr = *head;
	return ptr;
}//end of rearrange()
//driver program
int main(void)
{
	struct node *list1 = NULL, *list3 = NULL;
	list1 = create(list1);
	list3 = rearrange(&list1);
	display(list3);
}



