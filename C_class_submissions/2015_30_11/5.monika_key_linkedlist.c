//5.Given three numbers n1,n2,and r. Merge the table of n1 and n2 and find the r th number. In merging it should eliminate duplicate values (tables consists the multiples of those numbers ,ie 3 contains 3,6,9,12..)
//Ex, n1 = 3, n2 = 5 and r = 5, The merged table is 3, 5, 9, 10, 12, 15(One more 15 is removed as its duplicate) 18, 20, 21, 24, 25........so on .
//The rth num ie 5th number is 12, so OP is 12
//Extension, what if n3, n4 ..are also given ?


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
struct node *merge(struct node *list1, struct node *list2);
void find(struct node *list);
//driver program
main()
{
	struct node *list1 = NULL, *list2 = NULL,*list3=NULL;
	list1 = create(list1);//calling the function create
	list2 = create(list2);
	//printing the lists by calling  the function dispaly
	printf("List1 : ");
	display(list1);
	printf("List2 : ");
	display(list2);
	list3=merge(list1, list2);//calling the function merge
	find(list3);
}//End of main()
//function to merge the linked lists
struct node *merge(struct node *list1, struct node *list2)
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
	display(list3);
	return list3;
}
//function to find the number in the key position
void find(struct node *list)
{
	int  key,i=1,length=0;
	struct node *ptr = list;
	printf("Enter the position");//inputting the key
	scanf_s("%d", &key);
	while (ptr != NULL)
	{
		length++;
		ptr = ptr->next;
	}
	if (key>length||key<=0)
	{ 
		printf("error");
	}

	//traversing the linked list till key position
		while (list->next!=NULL)
		{
			list = list->next;
			i++;
			if (i == key)
				break;
		}
	//printing
	printf("The number at position %d is:%d", key, list->num);
		
}
//function to create a linked list by inserting new nodes
struct node *create(struct node *head)
{
	int index, num, data;
	printf("Enter the number of nodes : ");
	scanf_s("%d", &num);
	head = NULL;
		printf("Enter the element to be inserted : ");
		scanf_s("%d", &data);
		int n ;
		//loop to generate multiplication table
		for (n = 1, index = 1; index <= num; index++, n++)
		{
			head = insert_s(head, n*data);
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
