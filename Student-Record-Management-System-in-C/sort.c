#include"header.h"

void sort_by_name(SLL *ptr)
{
	SLL *p1,*p2;
	int roll;
	float percentage;
	char name[50];

	for(p1=ptr;p1;p1=p1->next)
	{
		for(p2=p1->next;p2;p2=p2->next)
		{
			if(strcmp(p1->name,p2->name)>0)
			{
				roll=p1->rollno;
				p1->rollno=p2->rollno;
				p2->rollno=roll;

				strcpy(name,p1->name);
				strcpy(p1->name,p2->name);
				strcpy(p2->name,name);

				percentage=p1->percentage;
				p1->percentage=p2->percentage;
				p2->percentage=percentage;
			}
		}
	}
}

void sort_by_percentage(SLL *ptr)
{
	SLL *p1,*p2;
	int roll;
	float percentage;
	char name[50];

	for(p1=ptr;p1;p1=p1->next)
	{
		for(p2=p1->next;p2;p2=p2->next)
		{
			if(p1->percentage<p2->percentage)
			{
				roll=p1->rollno;
				p1->rollno=p2->rollno;
				p2->rollno=roll;

				strcpy(name,p1->name);
				strcpy(p1->name,p2->name);
				strcpy(p2->name,name);

				percentage=p1->percentage;
				p1->percentage=p2->percentage;
				p2->percentage=percentage;
			}
		}
	}
}

void sort_student(SLL *ptr)
{
	char ch;

	if(ptr==0)
	{
		printf("No records found\n");
		return;
	}

	printf("N/n : Sort with name\n");
	printf("P/p : Sort with percentage\n");
	printf("Enter choice: ");
	scanf(" %c",&ch);

	if(ch=='n' || ch=='N')
	{
		sort_by_name(ptr);
		printf("Records sorted by name\n");
	}
	else if(ch=='p' || ch=='P')
	{
		sort_by_percentage(ptr);
		printf("Records sorted by percentage\n");
	}
	else
		printf("Invalid choice\n");
}
