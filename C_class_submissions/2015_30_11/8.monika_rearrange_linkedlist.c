//8.Given a linked list which is in pattern like combination of ascending and descending.Sort it.(First all ascending numbers occur, next all descending nums)

//Note : min of descending part is greater than max of ascending
  // Ex : Input 1->2->7->20->15->10
	//	Output 1->2->7->10->15->20

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
struct node *arrange(struct node **head);
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
struct node *arrange(struct node **head)
{
	struct node *previous_node = *(head);
	struct node *current_node = previous_node->next;
	//loop to traverse the linked list to sort the list
	while (current_node != NULL)
	{
		if (previous_node->data >current_node->data)
		{
			struct node *temp = previous_node->data;
			previous_node->data = current_node->data;
			current_node->data = temp;
		}
		previous_node = previous_node->next;
		current_node = current_node->next;
	}
	previous_node = *head;
	return previous_node;
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
	struct node *list1 = NULL, *list3 = NULL;
	list1 = create(list1);
	list3 = arrange(&list1);
	display(list3);
}

