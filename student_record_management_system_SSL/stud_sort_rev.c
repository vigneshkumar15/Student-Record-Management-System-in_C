#include "header.h"
int count_node(SLL *ptr)
{
    int c = 0;
    while (ptr != NULL)
    {
        c++;
        ptr = ptr->next;
    }
    return c;
}
void sort_list(SLL *ptr)
{
    if (ptr == NULL)
    {
        printf("No records found to sort.\n");
        return;
    }
    char choice;
    printf("Sort by (N/n: Name, P/p: Percentage): ");
    scanf(" %c", &choice);
    int c = count_node(ptr);
    SLL *p1;
    SLL *p2;
    SLL temp;
    int i, j;
    for (i = 0; i < c - 1; i++)
    {
        p1 = ptr;
        p2 = p1->next;
        for (j = 0; j < c - 1 - i; j++)
        {
            int swap_condition = 0;
            if (choice == 'N' || choice == 'n')
            {
                if (strcmp(p1->name, p2->name) > 0)
                    swap_condition = 1;
            }
            else if (choice == 'P' || choice == 'p')
            {
                if (p1->percentage < p2->percentage)
                    swap_condition = 1;
            }
            else
            {
                printf("Invalid choice!\n");
                return;
            }
            if (swap_condition)
            {
                temp.rollno = p1->rollno;
                strcpy(temp.name, p1->name);
                temp.percentage = p1->percentage;
                p1->rollno = p2->rollno;
                strcpy(p1->name, p2->name);
                p1->percentage = p2->percentage;
                p2->rollno = temp.rollno;
                strcpy(p2->name, temp.name);
                p2->percentage = temp.percentage;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    printf("List sorted successfully.\n");
}
void reverse_links(SLL **ptr)
{
    SLL *prev = NULL;
    SLL *curr = *ptr;
    SLL *next;
    if (*ptr == NULL)
    {
        printf("No records found to reverse.\n");
        return;
    }
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *ptr = prev;
    printf("List links reversed successfully.\n");
}
