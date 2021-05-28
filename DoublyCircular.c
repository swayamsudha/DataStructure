#include<stdio.h>
#include<stdlib.h>

void traverse();
//void traversereverse();
void insertbegin();
void insertend();
void insertafternode();
//void insertspecificlocation();
void deletebegin();
void deleteend();
void deleteafternode();
/*void deletefromspecificlocation();*/
struct node
{
	int info;
	struct node *next,*prev;
};
struct node *start = NULL;

main()
{
	int choice;
	while(1)
	{
		printf("\n1.Traverse\n2.Insert at begin\n3.Insert at end\n4.Insert after a given node\n5.Insert at a specific location\n6.Delete from beginning\n7.Delete from end\n8.Delete After a given node\n9.Delete from specific location\n10.Reverse\n11.Sorting\n12.Merging\n13.Reverse Traverse\n15.EXIT\n14.Create Second linked list\n");
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
			/*case 5:
					insertspecificlocation();
					break;*/
			case 6:
					deletebegin();
					break;
			case 7:
					deleteend();
					break;
			case 8:
					deleteafternode();
					break;
			/*case 9:
					deletefromspecificlocation();
					break;
			case 13:
					traversereverse();
					break;*/
			case 15:
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
		do
		{
			printf("%d\t",temp->info);
			temp = temp->next;
		}while(temp != start->prev);
	}
}
/*void traversereverse()
{
	struct node *temp;
	if(start == NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		temp = start;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		printf("\nValues of list are\n");
		while(temp != NULL)
		{
			printf("%d\t",temp->info);
			temp = temp->prev;
		}
	}
}*/
void insertbegin()
{
	struct node *temp,*ptr;
	int item;
	temp = (struct node *)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("\nOverflow\n");
	}
	else
	{
		printf("\nEnter the value to insert\n");
		scanf("%d",&item);
		temp->info = item;
		//temp->next = temp;
		//temp->prev = temp;
		if(start == NULL)
		{
			start = temp;
			temp->next = start;
		 	temp->prev = start;
		}
		else
		{
			ptr = start;
			if(ptr->next == start)
			{
				ptr->next = temp;
				ptr->prev = temp;
				temp->next = start;
				temp->prev = start;
				start = temp;
			}
			else
			{
			
				while(ptr->next != start)
				{
					ptr = ptr->next;
				}
				temp->next = start;
				start->prev = temp;
				temp->prev = ptr;
				ptr->next = temp;
				start = temp;
			}

		}
	
	}
	
	printf("\nNode is inserted successfully...");	
}
void insertend()
{
	struct node *temp,*ptr; 
	int item;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the value to insert\n");
	scanf("%d",&item);
	temp->info = item;
	temp->next = temp;
	temp->prev = temp;
	if(start == NULL)
	{
		start = temp;
	}
	else if(start->prev == start &&  start->next==start)
	{
		start->next = temp;
		start->prev = temp;
		temp->next = start;
		temp->prev = start;
	}
	else
	{
		ptr = start;
		while(ptr->next != start)	
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
		temp->prev = ptr;
		temp->next = start;
		start->prev = temp;
	}
}
void insertafternode()
{
	struct node *temp,*ptr1,*ptr2;
	int item,value;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the value to insert\n");
	scanf("%d",&item);
	temp->info = item;
	temp->next = NULL;
	temp->prev = NULL;
	if(start == NULL)
	{
		start = temp;
	}
	else
	{
		printf("\nEnter the value after which you want to insert\n");
		scanf("%d",&value);
		ptr1 = start;
		while(ptr1->next != start && ptr1->info != value)
		{
			ptr1 = ptr1->next;
		}
		
		if(ptr1 == NULL)
		{
			printf("\nNode is not present\n");
		}
		else if(ptr1->next == start)
		{
				ptr1->next = temp;
				temp->prev = ptr1;
				ptr1->prev = temp;
				temp->next = ptr1;
		}
		else
		{
				ptr2 = ptr1->next;
				temp->prev = ptr1;
				ptr1->next = temp;
				ptr2->prev = temp;
				temp->next = ptr2;
		}
		
	}	
		
}
/*void insertspecificlocation()
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
			start->prev = temp;
			start = temp;
		}
		else
		{
			ptr = start;
			while(ptr != NULL && count!=loc)
			{
				ptr1=ptr;
				ptr = ptr->next;
				count++;
			}
			if(ptr1 == NULL)
			{
				printf("\nNode is not present\n");
			}
			
			else
			{
				ptr1->next = temp;
				temp->prev = ptr1;
				temp->next = ptr;
				ptr->prev = temp;
			}
			
		}
		
	}

}*/
void deletebegin()
{
	struct node *temp,*last;
	if(start == NULL)
	{
		printf("\nList is empty\n");
	}
	else if(start->next == start)
	{
			printf("\nDelete node = %d\n",start->info);
			start = NULL;
	}
	else
	{
		last = start;
		while(last->next != start)
		{
			last = last->next;	
		}
		temp = start;
		start = start->next;
		last->next = start;
		start->prev = last;
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
		if(start ->next == start)
		{
			temp1 = start;
			printf("\nDelete node = %d\n",start->info);
			start = NULL;
			free(temp1);
		}
		else
		{
			temp1 = start;
			while(temp1->next != start)
			{
				temp1 = temp1->next;
			}
			temp2 = temp1->prev;
			temp2->next = start;
			start->prev = temp1;
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
		while(ptr1 != start && ptr1->info != value)
		{
			ptr1 = ptr1->next;
		}
		if(ptr1 == NULL)
		{
			printf("\nNode is not present\n");
		}
		else if(ptr1->next == start)
		{
			printf("\n%d is the last node\n",ptr1->info);
		}
		else
		{
			ptr2 = ptr1->next;
			ptr1->next = ptr2->next;
			ptr1->next->prev = ptr1;
			printf("\nDelete node = %d\n",ptr2->info);
			free(ptr2);
		}
	}
}
/*void deletefromspecificlocation()
{
	struct node *ptr1,*ptr,*ptr2;
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
			else if(ptr1->next == NULL)
			{
				ptr->next = NULL;
				printf("\nDelete node = %d\n",ptr1->info);
				free(ptr1);
			}
			else
			{
				ptr2 = ptr1->next;
				ptr->next = ptr2;
				ptr2->prev = ptr;
				printf("\nDelete node = %d\n",ptr1->info);
				free(ptr1);
			}	
		}	
	}
}*/
