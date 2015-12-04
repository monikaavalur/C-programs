//Merge two linked lists that are in sorted order


#include<stdio.h>
#include<stdlib.h>
//creating a basic structure
struct node
{
	int num;
	struct node *next;
};
//delaring the struct functions
struct node *create(struct node *head);
struct node *insert_s(struct node *head, int data);
struct node *insert(struct node *head, int data);
void display(struct node *head);
void merge(struct node *list1, struct node *list2);
//driver progra,
main()
{
	struct node *list1 = NULL, *list2 = NULL;
	list1 = create(list1);//calling the function create
	list2 = create(list2);
//printing the lists by calling  the function dispaly
	printf("List1 : ");
	display(list1);
	printf("List2 : ");
	display(list2);
	merge(list1, list2);//calling the function merge
}//End of main()
//function to merge the linked lists
void merge(struct node *list1, struct node *list2)
{
	struct node *list3;//creating a new list and assigning null to it
	list3 = NULL;
//loop to merge the two lists
	while (list1 != NULL && list2 != NULL)
	{
          //assigning the numbers to list3 by checking the different conditoins below
		if (list1->num < list2->num)
		{
			list3 = insert(list3, list1->num);
			list1 = list1->next;
		}
		else if (list2->num < list1->num)
		{
			list3 = insert(list3, list2->num);
			list2 = list2->next;
		}
		else if (list1->num == list2->num)
		{
			list3 = insert(list3, list1->num);
			list1 = list1->next;
			list2 = list2->next;
		}
	}
	//If second list has finished and elements left in first list
	while (list1 != NULL)
	{
		list3 = insert(list3, list1->num);
		list1 = list1->next;
	}
	//If first list has finished and elements left in second list
	while (list2 != NULL)
	{
		list3 = insert(list3, list2->num);
		list2 = list2->next;
	}
	printf("Merged list is : ");//printing merge list
	display(link3);
}
//function to create a linked list by inserting new nodes
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
	temp->num = data;
	//list empty or data to be added in beginning 
	if (head == NULL || data<head->num)
	{
		temp->next = head;
		head = temp;
		return head;
	}
	else
	{
		list = head;
		while (list->next != NULL && list->next->num < data)
			list = list->next;
		temp->next = list->next;
		list->next = temp;
	}
	return head;
}//End of insert_s()

struct node *insert(struct node *start, int data)
{
	struct node *list, *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->num = data;
	//If list is empty
	if (start == NULL)
	{
		temp->next = start;
		start = temp;
		return start;
	}
	else    //Insert at the end of the list
	{
		list = start;
		while (list->next != NULL)
			list = list->next;
		temp->next = list->next;
		list->next = temp;
	}
	return start;
}//End of insert()

void display(struct node *start)
{
	struct node *list;
	if (start == NULL)
	{
		printf("List is empty\n");
		return;
	}
	list = start;
	while (list != NULL)
	{
		printf("%d ", list->num);
		list = list->next;
	}
	printf("\n");
}//End of display()
