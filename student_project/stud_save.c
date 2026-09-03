#include"header.h"

void read_file(SLL **ptr)
{
    SLL *new,*last;
    FILE *fp;
    fp=fopen("student.dat","r");
    if(fp==0)
    {
        printf("File not present\n");
        return ;
    }
    while(1){
        new=malloc(sizeof(SLL));
        if(fscanf(fp,"%d %s %f",&new->rollno,new->name,&new->percentage)==-1){
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
    printf("\033[34m*****************\n");
    if(ptr==0){
        printf("NO records found\n");
        return ;
    }
    FILE *fp;
    fp=fopen("student.dat","w");
    while(ptr){
        fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
        ptr=ptr->next;
    }
    printf("Data saved in File\n");
    printf("**************************\033[0m\n");
    fclose(fp);
}
