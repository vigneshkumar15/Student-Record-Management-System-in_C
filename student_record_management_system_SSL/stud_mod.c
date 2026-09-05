#include "header.h"
void modify_node(SLL *ptr)
{
    if (ptr == NULL)
    {
        printf("No student records available.\n");
        return;
    }
    char choice;
    int target_roll = -1;
    printf("Enter which record to search for modification\n");
    printf("R/r : Search by roll number\n");
    printf("N/n : Search by name\n");
    printf("P/p : Search by percentage\n");
    printf("Enter choice: ");
    scanf(" %c", &choice);
    if (choice == 'R' || choice == 'r')
    {
        printf("Enter Roll Number to modify: ");
        scanf("%d", &target_roll);
    }
    else if (choice == 'N' || choice == 'n')
    {
        char search_name[50];
        printf("Enter Name to search: ");
        scanf(" %[^\n]", search_name);
        SLL *curr = ptr;
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
            printf("No matching records found.\n");
            return;
        }
        printf("Enter Roll Number to modify: ");
        scanf("%d", &target_roll);
    }
    else if (choice == 'P' || choice == 'p')
    {
        float search_pct;
        printf("Enter Percentage to search: ");
        scanf("%f", &search_pct);
        SLL *curr = ptr;
        int count = 0;
        printf("\nMatching Records:\n");
        while (curr != NULL)
        {
            if (curr->percentage == search_pct)
            {
                printf("Roll No: %d | Name: %s | Percentage: %.2f\n", curr->rollno, curr->name, curr->percentage);
                count++;
            }
            curr = curr->next;
        }
        if (count == 0)
        {
            printf("No matching records found.\n");
            return;
        }
        printf("Enter Roll Number to modify: ");
        scanf("%d", &target_roll);
    }
    else
    {
        printf("Invalid choice!\n");
        return;
    }
    SLL *curr = ptr;
    while (curr != NULL)
    {
        if (curr->rollno == target_roll)
        {
            printf("\nCurrent Details:\n");
            printf("Name: %s\n", curr->name);
            printf("Percentage: %.2f\n", curr->percentage);
            printf("Enter Updated Name: ");
            scanf(" %[^\n]", curr->name);
            printf("Enter Updated Percentage (0.00 - 100.00): ");
            scanf("%f", &curr->percentage);
            while (curr->percentage < 0.00 || curr->percentage > 100.00)
            {
                printf("Invalid percentage! Enter between 0.00 and 100.00: ");
                scanf("%f", &curr->percentage);
            }
            printf("Record updated successfully.\n");
            return;
        }
        curr = curr->next;
    }
    printf("Roll Number %d not found.\n", target_roll);
}
