#include "header.h"
void save_file(SLL *ptr)
{
    FILE *fp;
    if (ptr == NULL)
    {
        printf("No records to save.\n");
        return;
    }
    fp = fopen("student.dat", "w");
    if (fp == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }
    while (ptr != NULL)
    {
        fprintf(fp, "%d|%s|%f\n", ptr->rollno, ptr->name, ptr->percentage);
        ptr = ptr->next;
    }
    fclose(fp);
    printf("Records saved successfully to student.dat.\n");
}
void read_file(SLL **ptr)
{
    FILE *fp = fopen("student.dat", "r");
    if (fp == NULL)
        return;
    SLL *new_node;
    SLL *last;
    while (1)
    {
        new_node = (SLL *)malloc(sizeof(SLL));
        if (new_node == NULL)
        {
            printf("Memory allocation failed!\n");
            fclose(fp);
            return;
        }
        if (fscanf(fp, "%d|%49[^|]|%f", &new_node->rollno, new_node->name, &new_node->percentage) != 3)
        {
            free(new_node);
            break;
        }
        new_node->next = NULL;
        if (*ptr == NULL)
            *ptr = new_node;
        else
        {
            last = *ptr;
            while (last->next != NULL)
                last = last->next;
            last->next = new_node;
        }
    }
    fclose(fp);
}
