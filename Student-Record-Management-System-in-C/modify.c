#include"header.h"

void update_record(SLL *ptr)
{
	char name[50];
	float percentage;

	printf("Current Name: %s\n",ptr->name);
	printf("Current Percentage: %.2f\n",ptr->percentage);

	printf("Enter new name: ");
	scanf(" %49[^\n]",name);

	while(1)
	{
		printf("Enter new percentage: ");
		scanf("%f",&percentage);

		if(percentage>=0 && percentage<=100)
			break;

		printf("Percentage must be between 0 and 100\n");
	}

	strcpy(ptr->name,name);
	ptr->percentage=percentage;

	printf("Record modified successfully\n");
}

void modify_student(SLL *ptr)
{
	char ch,name[50];
	int roll,found;
	float percentage;
	SLL *temp;

	if(ptr==0)
	{
		printf("No records found\n");
		return;
	}

	printf("Enter which record to search for modification\n");
	printf("R/r : Search by roll number\n");
	printf("N/n : Search by name\n");
	printf("P/p : Search by percentage\n");
	printf("Enter choice: ");
	scanf(" %c",&ch);

	if(ch=='r' || ch=='R')
	{
		printf("Enter roll number: ");
		scanf("%d",&roll);

		temp=ptr;

		while(temp)
		{
			if(temp->rollno==roll)
			{
				update_record(temp);
				return;
			}

			temp=temp->next;
		}

		printf("Roll number not found\n");
	}
	else if(ch=='n' || ch=='N')
	{
		printf("Enter name: ");
		scanf(" %49[^\n]",name);

		temp=ptr;
		found=0;

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

		printf("Enter roll number of record to modify: ");
		scanf("%d",&roll);

		temp=ptr;

		while(temp)
		{
			if(temp->rollno==roll && strcmp(temp->name,name)==0)
			{
				update_record(temp);
				return;
			}

			temp=temp->next;
		}

		printf("Selected record not found\n");
	}
	else if(ch=='p' || ch=='P')
	{
		printf("Enter percentage: ");
		scanf("%f",&percentage);

		temp=ptr;
		found=0;

		while(temp)
		{
			if(temp->percentage==percentage)
			{
				printf("Roll No: %d  Name: %s  Percentage: %.2f\n",
					temp->rollno,temp->name,temp->percentage);
				found=1;
			}

			temp=temp->next;
		}

		if(found==0)
		{
			printf("Percentage not found\n");
			return;
		}

		printf("Enter roll number of record to modify: ");
		scanf("%d",&roll);

		temp=ptr;

		while(temp)
		{
			if(temp->rollno==roll && temp->percentage==percentage)
			{
				update_record(temp);
				return;
			}

			temp=temp->next;
		}

		printf("Selected record not found\n");
	}
	else
		printf("Invalid choice\n");
}
