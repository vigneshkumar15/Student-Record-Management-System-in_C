#include"header.h"

void print_node(SLL *ptr)
{
    printf("\033[34m*****************\n");
    if(ptr==0){
        printf("NO records found\n");
        return ;
    }
    while(ptr){
        printf("%d %s %.2f\n",ptr->rollno,ptr->name,ptr->percentage);
        ptr=ptr->next;
    }
    printf("**************************\033[0m\n");
}

int count_node(SLL *ptr)
{
    int c=0;
    while(ptr){
        c++;
        ptr=ptr->next;
    }
    return c;
}
