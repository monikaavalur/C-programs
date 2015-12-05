// Find the median of a given linked list(sorted linked list)

#include<stdio.h>
#include<stdlib.h>

//creating the basic structure
struct node{
	int num;
	struct node *next;
};
//function to insert a new node into the linked list
void insert(struct node **head, int newData)
{
	struct node *newNode = (struct node*)malloc(sizeof(struct node));//creating a new node dynamically
	newNode->num = newData;//assigning the data to the newnode
	newNode->next = *(head);
	*(head) = newNode;//assigning the newnode to head
}
//printing the linked list
void printList(struct node *ptr)
{
	while (ptr != NULL)
	{
		printf("%d->", ptr->num);
		ptr = ptr->next;
	}
	printf("NULL\n");
}
//finding the median of the linked list
void FindMedian(struct node *head)
{
     //creating two new structs
	 struct node *previous_node = head;
	 struct node *current_node = head;
	 //traversing the linked list to find the median of the linked list
	if (head != NULL)
	{
		while (current_node != NULL&&current_node->next != NULL)
		{
			current_node = current_node->next->next;
			previous_node = previous_node->next;
		}
	}
	printf("The median is:[%d]\n\n", previous_node->num);//printing the median
}
//driver program
main()
{
	struct node *head = NULL;
	int i;
	for (i = 5; i > 0; i--)//for loop for creating a linked list
	{
		insert(&head, i);
		printList(head);
		FindMedian(head);
	}
}
