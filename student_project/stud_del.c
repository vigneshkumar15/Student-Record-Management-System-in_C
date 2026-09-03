#include"header.h"

void delete_node(SLL **ptr)
{
    if(*ptr==0){
        printf("No records found\n");
        return ;
    }
    char name[50];
    printf("Enter name to delete\n");
    scanf("%s",name);
    SLL *del=*ptr,*prev;
    while(del){
        if(strcmp(name,del->name)==0){
            if(del == *ptr)
                *ptr=del->next;
            else
                prev->next=del->next;

            free(del);
            return;
        }
        prev=del;
        del=del->next;
    }
    printf("Name not found\n");
}

void delete_all(SLL **ptr)
{
    if(*ptr==0){
        printf("No records found\n");
        return ;
    }

    int c=1;
    SLL *del=*ptr;
    while(del){
        *ptr=del->next;
        sleep(1);
        printf("Node deleted:%d\n",c++);
        free(del);
        del=*ptr;
    }
    printf("all the nodes deleted\n");
}
