#include"header.h"

void sort_data(SLL *ptr)
{
    if(ptr==0){
        printf("No records found\n");
        return ;
    }
    int c=count_node(ptr);
    SLL *p1=ptr ,*p2,t;
    int i,j;
    for(i=0;i<c-1;i++){
        p2=p1->next;
        for(j=0;j<c-1-i;j++){
            if(p1->rollno > p2->rollno){
                t.rollno=p1->rollno;
                strcpy(t.name,p1->name);
                t.percentage=p1->percentage;

                p1->rollno = p2->rollno;
                strcpy(p1->name,p2->name);
                p1->percentage=p2->percentage;

                p2->rollno=t.rollno;
                strcpy(p2->name,t.name);
                p2->percentage=t.percentage;
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
}
