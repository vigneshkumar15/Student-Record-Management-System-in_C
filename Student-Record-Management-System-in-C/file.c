#include"header.h"

void read_file(SLL **ptr)
{
	FILE *fp;
	SLL *new,*last;

	fp=fopen("student.dat","r");

	if(fp==0)
		return;

	while(1)
	{
		new=malloc(sizeof(SLL));

		if(new==0)
		{
			fclose(fp);
			return;
		}

		if(fscanf(fp,"%d %49s %f",
			&new->rollno,new->name,&new->percentage)!=3)
		{
			free(new);
			break;
		}

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
	}

	fclose(fp);
}

void save_file(SLL *ptr)
{
	FILE *fp;

	fp=fopen("student.dat","w");

	if(fp==0)
	{
		printf("File opening failed\n");
		return;
	}

	while(ptr)
	{
		fprintf(fp,"%d %s %.2f\n",
			ptr->rollno,ptr->name,ptr->percentage);

		ptr=ptr->next;
	}

	fclose(fp);

	printf("Records saved successfully\n");
}
