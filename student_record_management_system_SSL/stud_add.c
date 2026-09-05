#include "header.h"
void add_node(SLL **ptr)
{
    SLL *new, *last;
    int roll = 1;
    new = (SLL *)malloc(sizeof(SLL));
    if (new == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    while (1)
    {
        SLL *temp = *ptr;
        int found = 0;
        while (temp != NULL)
        {
            if (temp->rollno == roll)
            {
                found = 1;
                break;
            }
            temp = temp->next;
        }
        if (found == 0)
            break;
        roll++;
    }
    new->rollno = roll;
    printf("Assigned Roll No: %d\n", new->rollno);
    printf("Enter Student Name: ");
    scanf(" %[^\n]", new->name);
    printf("Enter Percentage (0.00 - 100.00): ");
    scanf("%f", &new->percentage);
    while (new->percentage < 0.00 || new->percentage > 100.00)
    {
        printf("Invalid percentage! Enter between 0.00 and 100.00: ");
        scanf("%f", &new->percentage);
    }
    new->next = NULL;
    if (*ptr == NULL)
        *ptr = new;
    else if (new->rollno < (*ptr)->rollno)
    {
        new->next = *ptr;
        *ptr = new;
    }
    else
    {
        last = *ptr;
        while (last->next != NULL && last->next->rollno < new->rollno)
            last = last->next;
        new->next = last->next;
        last->next = new;
    }
    printf("Record added successfully!\n");
}
