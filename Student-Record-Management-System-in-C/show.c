#include"header.h"

void print_node(SLL *ptr)
{
	if(ptr==0)
	{
		printf("No records found\n");
		return;
	}

	printf("--------------------------------------------------\n");
	printf("Roll No.   Name                 Percentage\n");
	printf("--------------------------------------------------\n");

	while(ptr)
	{
		printf("%-10d %-20s %.2f\n",
			ptr->rollno,ptr->name,ptr->percentage);

		ptr=ptr->next;
	}

	printf("--------------------------------------------------\n");
}
