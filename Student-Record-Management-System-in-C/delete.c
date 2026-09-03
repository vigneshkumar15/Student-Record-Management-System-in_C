#include"header.h"

void delete_by_roll(SLL **ptr)
{
	SLL *del,*prev=0;
	int roll;

	printf("Enter roll number to delete: ");
	scanf("%d",&roll);

	del=*ptr;

	while(del)
	{
		if(del->rollno==roll)
		{
			if(del==*ptr)
				*ptr=del->next;
			else
				prev->next=del->next;

			free(del);
			printf("Record deleted successfully\n");
			return;
		}

		prev=del;
		del=del->next;
	}

	printf("Roll number not found\n");
}

void delete_by_name(SLL **ptr)
{
	SLL *temp=*ptr;
	int roll,found=0;
	char name[50];

	printf("Enter name to delete: ");
	scanf(" %49[^\n]",name);

	while(temp)
	{
		if(strcmp(temp->name,name)==0)
		{
			printf("Roll No: %d  Name: %s  Percentage: %.2f\n",
				temp->rollno,temp->name,temp->percentage);
			found=1;
		}

		temp=temp->next;
	}

	if(found==0)
	{
		printf("Name not found\n");
		return;
	}

	printf("Enter roll number of record to delete: ");
	scanf("%d",&roll);

	temp=*ptr;

	while(temp)
	{
		if(temp->rollno==roll && strcmp(temp->name,name)==0)
		{
			SLL *del=*ptr;
			SLL *prev=0;

			while(del)
			{
				if(del==temp)
				{
					if(del==*ptr)
						*ptr=del->next;
					else
						prev->next=del->next;

					free(del);
					printf("Record deleted successfully\n");
					return;
				}

				prev=del;
				del=del->next;
			}
		}

		temp=temp->next;
	}

	printf("Selected record not found\n");
}

void delete_student(SLL **ptr)
{
	char ch;

	if(*ptr==0)
	{
		printf("No records found\n");
		return;
	}

	printf("R/r : Enter roll number to delete\n");
	printf("N/n : Enter name to delete\n");
	printf("Enter choice: ");
	scanf(" %c",&ch);

	switch(ch)
	{
		case 'r':
		case 'R':
			delete_by_roll(ptr);
			break;

		case 'n':
		case 'N':
			delete_by_name(ptr);
			break;

		default:
			printf("Invalid choice\n");
	}
}

void delete_all(SLL **ptr)
{
	SLL *del;

	if(*ptr==0)
	{
		printf("No records found\n");
		return;
	}

	while(*ptr)
	{
		del=*ptr;
		*ptr=del->next;
		free(del);
	}

	printf("All records deleted successfully\n");
}

void free_all(SLL **ptr)
{
	SLL *del;

	while(*ptr)
	{
		del=*ptr;
		*ptr=del->next;
		free(del);
	}
}
