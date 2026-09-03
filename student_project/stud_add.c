#include"header.h"

void add_middle(SLL **ptr)
{
    SLL *new,*last;
    new=malloc(sizeof(SLL));
    printf("Enter Rollno name and percentage\n");
    scanf("%d %s %f",&new->rollno,new->name,&new->percentage);

    if((*ptr==0) || (new->rollno < (*ptr)->rollno))
    {
        new->next=*ptr;
        *ptr=new;
    }
    else
    {
        last= *ptr;
        while((last->next!=0) && (new->rollno > last->next->rollno))
            last=last->next;

        new->next= last->next;
        last->next=new;
    }
}
