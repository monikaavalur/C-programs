//3.Add a node to the circular linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
	int num;
	struct node *next;
};
struct node  *ptr, *temp;
//defining functions 
struct node *create(struct node *head);
void insert_front(struct node *head);
void insert_any(struct node *head);
void display(struct node *head);

//driver program
void main()
{
	struct node *head;//creating a node head dynamically
	head = (struct node*)malloc(sizeof(struct node));
	head->num = NULL;
	head->next = head;
//calling the functions
	head = create(head);
	display(head);
	insert_front(head);
	display(head);
		insert_any(head);
		display(head);
	
}//end of main
//functon to create a node
struct node *create(struct node *head)
{
	head = (struct node*)malloc(sizeof(struct node));
	head->next = head;
	printf("Enter the data");
	scanf_s("%d", &head->num);
	temp = head;

	temp->next = (struct node*)malloc(sizeof(struct node));
	temp = temp->next;
	temp->next = head;
	printf("enter the data");
	scanf_s("%d", &temp->num);
	return head;
}//end of create()
//function to insert in the front
void insert_front(struct node *head)
{
	ptr=head;
//traversing the array to find the last node	
	while (ptr->next != head)
	{
		ptr = ptr->next;
	}
	//creating a new node dynamically
	ptr->next = (struct node *)malloc(sizeof(struct node));
	ptr = ptr->next;
	printf("Enter the data");
	scanf_s("%d",&ptr->num);
	ptr->next = head;
}//end of the function
//function to insert the node in any position
void insert_any(struct node *head)
{
	temp = (struct node *)malloc(sizeof(struct node));//creating a new node dynamically
	int data,position;
	printf("enter the data");
	scanf_s("%d", &data);
	printf("enter the position");
	scanf_s("%d", &position);
	temp->num = data;
	struct node  *current = head;//traversing the list to find the position to insert a new node
    for (int i = 2; i <= position - 1; i++)
        {
	            current = current->next;
        }
		        // Links new node with node ahead of it and previous to it
		       temp->next = current->next;
	      current->next = temp;	
}//end of the function
//function to display the list
void display(struct node *head)
{
	ptr = head;
	printf("%d-->", ptr->num);
	ptr = ptr->next;
	while (ptr!= head)
	{
		printf("%d-->", ptr->num);
		ptr = ptr->next;
	}
	printf("\n");
}
