#include<stdio.h>
#include<stdlib.h>

void traverse();
void insertbegin();
void insertend();
void insertafternode();
void insertspecificlocation();
void deletebegin();
void deleteend();
void deleteafternode();
void deletefromspecificlocation();
void reverse();
void sort();
void merge();
void insertend1();

struct node
{
	int info;
	struct node *next;
};
struct node *start = NULL;
struct node *start1 = NULL;
main()
{
	int choice;
	while(1)
	{
		printf("\n1.Traverse\n2.Insert at begin\n3.Insert at end\n4.Insert after a given node\n5.Insert at a specific location\n6.Delete from beginning\n7.Delete from end\n8.Delete After a given node\n9.Delete from specific location\n10.Reverse\n11.Sorting\n12.Merging\n13.EXIT\n14.Create Second linked list\n");
		printf("Enter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					traverse();
					break;
			case 2:
					insertbegin();
					break;
			case 3:
					insertend();
					break;
			case 4:
					insertafternode();
					break;
			case 5:
					insertspecificlocation();
					break;
			case 6:
					deletebegin();
					break;
			case 7:
					deleteend();
					break;
			case 8:
					deleteafternode();
					break;
			case 9:
					deletefromspecificlocation();
					break;
			case 10:
					reverse();
					break;
			case 11:
					sort();
					break;
			case 12:
					merge();
					break;
			case 14:
					insertend1();
					break;
			case 13:
					exit(0);
			default:
					printf("\nWrong Choice\n");
		}
	}
}
void traverse()
{
	struct node *temp;
	if(start == NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		temp = start;
		printf("\nValues of list are\n");
		while(temp != NULL)
		{
			printf("%d\t",temp->info);
			temp = temp->next;
		}
	}
}
void insertbegin()
{
	struct node *temp;
	int item;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the value to insert\n");
	scanf("%d",&item);
	temp->info = item;
	temp->next = NULL;
	if(start == NULL)
	{
		start = temp;
	}
	else
	{
		temp->next = start;
		start = temp;
	}	
}
void insertend()
{
	struct node *temp,*ptr;
	int item;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the value to insert\n");
	scanf("%d",&item);
	temp->info = item;
	temp->next = NULL;
	if(start == NULL)
	{
		start = temp;
	}
	else
	{
		ptr = start;
		while(ptr->next != NULL)	
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
}
void insertend1()
{
	struct node *temp,*ptr;
	int item;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the value to insert\n");
	scanf("%d",&item);
	temp->info = item;
	temp->next = NULL;
	if(start1 == NULL)
	{
		start1 = temp;
	}
	else
	{
		ptr = start1;
		while(ptr->next != NULL)	
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
}
void insertafternode()
{
	struct node *temp,*ptr;
	int item,value;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the value to insert\n");
	scanf("%d",&item);
	temp->info = item;
	temp->next = NULL;
	if(start == NULL)
	{
		start = temp;
	}
	else
	{
		printf("\nEnter the value after which you want to insert\n");
		scanf("%d",&value);
		ptr = start;
		while(ptr != NULL && ptr->info != value)
		{
			ptr = ptr->next;
		}
		if(ptr == NULL)
		{
			printf("\nNode is not present\n");
		}
		else
		{
			temp->next = ptr->next;
			ptr->next = temp;
		}
	}		
}
void insertspecificlocation()
{
	struct node *temp,*ptr,*ptr1;
	int item,loc,count=1;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the value to insert\n");
	scanf("%d",&item);
	temp->info = item;
	temp->next = NULL;
	if(start == NULL)
	{
		start = temp;
	}
	else
	{
		printf("\nEnter the location at which you want to insert\n");
		scanf("%d",&loc);
		if(loc == 1)
		{
			temp->next = start;
			start = temp;
		}
		else
		{
			ptr = start;
			while(ptr != NULL && count!=loc)
			{
				ptr1 = ptr;
				ptr = ptr->next;
				count++;
			}
			if(ptr == NULL)
			{
				printf("\nNode is not present\n");
			}
			else
			{
				ptr1->next = temp;
				temp->next = ptr;
			}
		}
	}
}

void deletebegin()
{
	struct node *temp;
	if(start == NULL)
	{
		printf("\nList is empty\n");
	}
	else
	{
		temp = start;
		start = start->next;
		printf("\nDelete node = %d\n",temp->info);
		free(temp);
	}
}
void deleteend()
{
	struct node *temp1,*temp2;
	if(start == NULL)
	{
		printf("\nList is empty\n");
	}
	else
	{
		if(start ->next == NULL)
		{
			temp1 = start;
			printf("\nDelete node = %d\n",start->info);
			start = NULL;
			free(temp1);
		}
		else
		{
			temp1 = start;
			while(temp1->next != NULL)
			{
				temp2 = temp1;
				temp1 = temp1->next;
			}
			temp2->next = NULL;
			printf("\nDelete node = %d\n",temp1->info);
			free(temp1);
		}	
	}
}
void deleteafternode()
{
	struct node *ptr1,*ptr2;
	int value;
	if(start == NULL)
	{
		printf("\nList is empty\n");
	}
	else
	{
		printf("\nEnter the value after which you want to delete\n");
		scanf("%d",&value);
		ptr1 = start;
		while(ptr1 != NULL && ptr1->info != value)
		{
			ptr1 = ptr1->next;
		}
		if(ptr1 == NULL)
		{
			printf("\nNode is not present\n");
		}
		else
		{
			ptr2 = ptr1->next;
			ptr1->next = ptr2->next;
			printf("\nDelete node = %d\n",ptr2->info);
			free(ptr2);
		}	
	}
}
void deletefromspecificlocation()
{
	struct node *ptr1,*ptr;
	int loc,count=1;
	if(start == NULL)
	{
		printf("\nList is empty\n");
	}
	else
	{
		printf("\nEnter the location from which you want to delete\n");
		scanf("%d",&loc);
		if(loc == 1)
		{
			ptr1 = start;
			start = start->next;
			printf("\nDelete node = %d\n",ptr1->info);
			free(ptr1);
		}
		else
		{
			ptr1 = start;
			while(ptr1 != NULL && count!=loc)
			{
				ptr = ptr1;
				ptr1 = ptr1->next;
				count++;
			}
			if(ptr1 == NULL)
			{
				printf("\nNode is not present\n");
			}
			else
			{
				ptr->next = ptr1->next;
				printf("\nDelete node = %d\n",ptr1->info);
				free(ptr1);
			}	
		}	
	}
}
void reverse()
{
	struct node *ptr1,*ptr2,*ptr3;
	if(start == NULL)
	{
		printf("\nList is empty\n");
	}
	else
	{
		ptr1 = start;
		ptr2 = NULL;
		ptr3 = NULL;
		while(ptr1 != NULL)
		{
			ptr2 = ptr1->next;
			ptr1->next = ptr3;
			ptr3 = ptr1;
			ptr1 = ptr2;
		}
		start = ptr3;
	}	
}
void sort()
{
	int temp;
	struct node *ptr1,*ptr2;
	if(start == NULL)
	{
		printf("\nList is empty\n");
	}
	else
	{
		ptr1 = start;
		while(ptr1->next != NULL)
		{
			ptr2 = start;
			while(ptr2->next != NULL)
			{
				if(ptr2->info > ptr2->next->info)
				{
					temp = ptr2->info;
					ptr2->info = ptr2->next->info;
					ptr2->next->info = temp;
				}
				ptr2 = ptr2->next;
			}
			ptr1 = ptr1->next;
		}
	}
}
void merge()
{
	struct node *temp;
	temp = start;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = start1;
}
