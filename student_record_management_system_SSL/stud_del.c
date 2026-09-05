#include "header.h"
void delete_node(SLL **ptr)
{
    if (*ptr == NULL)
    {
        printf("No student records available.\n");
        return;
    }
    char choice;
    printf("Delete by (R/r: Roll Number, N/n: Name): ");
    scanf(" %c", &choice);
    int target_roll = -1;
    if (choice == 'R' || choice == 'r')
    {
        printf("Enter roll number to delete: ");
        scanf("%d", &target_roll);
    }
    else if (choice == 'N' || choice == 'n')
    {
        char search_name[50];
        printf("Enter name to delete: ");
        scanf(" %[^\n]", search_name);
        SLL *curr = *ptr;
        int count = 0;
        printf("\nMatching Records:\n");
        while (curr != NULL)
        {
            if (strcmp(curr->name, search_name) == 0)
            {
                printf("Roll No: %d | Name: %s | Percentage: %.2f\n", curr->rollno, curr->name, curr->percentage);
                count++;
            }
            curr = curr->next;
        }
        if (count == 0)
        {
            printf("No student record found with name '%s'.\n", search_name);
            return;
        }
        printf("Enter the Roll Number of the record to delete: ");
        scanf("%d", &target_roll);
    }
    else
    {
        printf("Invalid choice!\n");
        return;
    }
    SLL *del = *ptr;
    SLL *prev = NULL;
    while (del != NULL)
    {
        if (del->rollno == target_roll)
        {
            if (del == *ptr)
                *ptr = del->next;
            else
                prev->next = del->next;
            free(del);
            printf("Record with Roll No %d deleted successfully.\n", target_roll);
            return;
        }
        prev = del;
        del = del->next;
    }
    printf("Roll Number %d not found.\n", target_roll);
}
void delete_all(SLL **ptr)
{
    SLL *del;
    if (*ptr == NULL)
    {
        printf("No student records available.\n");
        return;
    }
    while (*ptr != NULL)
    {
        del = *ptr;
        *ptr = (*ptr)->next;
        free(del);
    }
    printf("All student records deleted from memory successfully.\n");
}
