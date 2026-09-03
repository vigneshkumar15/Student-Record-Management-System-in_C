#include"header.h"

void reverse_links(SLL **ptr)
{
    if(*ptr==0){
        printf("No records found\n");
        return ;
    }

    int i=0,c=count_node(*ptr);
    if(c>1){
        SLL **a=malloc(sizeof(SLL *)*c);
        SLL *t=*ptr;

        while(t){
            a[i++]=t;
            t=t->next;
        }

        for(i=c-1;i>0;i--)
            a[i]->next=a[i-1];

        a[0]->next=0;
        *ptr=a[c-1];
        free(a);
    }
}
