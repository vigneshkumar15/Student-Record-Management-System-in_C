#include"header.h"

int roll_exists(SLL *ptr,int roll)
{
	while(ptr)
	{
		if(ptr->rollno==roll)
			return 1;

		ptr=ptr->next;
	}

	return 0;
}

int get_roll(SLL *ptr)
{
	int roll=1;

	while(roll_exists(ptr,roll))
		roll++;

	return roll;
}

void add_student(SLL **ptr)
{
	SLL *new,*last;
	int roll;
	char name[50];
	float percentage;

	new=malloc(sizeof(SLL));

	if(new==0)
	{
		printf("Memory allocation failed\n");
		return;
	}

	roll=get_roll(*ptr);

	while(1)
	{
		printf("Enter student name: ");
		scanf(" %49[^\n]",name);

		if(strlen(name)==0)
		{
			printf("Name should not be empty\n");
			continue;
		}

		break;
	}

	while(1)
	{
		printf("Enter percentage: ");
		scanf("%f",&percentage);

		if(percentage>=0 && percentage<=100)
			break;

		printf("Percentage must be between 0 and 100\n");
	}

	new->rollno=roll;
	strcpy(new->name,name);
	new->percentage=percentage;
	new->next=0;

	if(*ptr==0)
		*ptr=new;
	else
	{
		last=*ptr;

		while(last->next)
			last=last->next;

		last->next=new;
	}

	printf("Record added successfully\n");
	printf("Assigned Roll No: %d\n",roll);
}
