#include"header.h"

void reverse_list(SLL **ptr)
{
	SLL *prev=0;
	SLL *cur=*ptr;
	SLL *next;

	if(*ptr==0)
	{
		printf("No records found\n");
		return;
	}

	while(cur)
	{
		next=cur->next;
		cur->next=prev;
		prev=cur;
		cur=next;
	}

	*ptr=prev;

	printf("List reversed successfully\n");
}
