#include "student.h"

int main()
{
    SLL *headptr = NULL;

    read_file(&headptr);

    char choice;

    while (1)
    {
        printf("\n******** STUDENT RECORD MENU ********\n");

        printf("a/A : Add new record\n");
        printf("d/D : Delete a record\n");
        printf("s/S : Show the list\n");
        printf("m/M : Modify a record\n");
        printf("v/V : Save records\n");
        printf("e/E : Exit\n");
        printf("t/T : Sort the list\n");
        printf("l/L : Delete all the records\n");
        printf("r/R : Reverse the list\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
            case 'a':
            case 'A':
                add_node(&headptr);
                break;

            case 'd':
            case 'D':
                delete_node(&headptr);
                break;

            case 's':
            case 'S':
                print_node(headptr);
                break;

            case 'm':
            case 'M':
                modify_node(headptr);
                break;

            case 'v':
            case 'V':
                save_file(headptr);
                break;

            case 't':
            case 'T':
                sort_list(headptr);
                break;

            case 'l':
            case 'L':
                delete_all(&headptr);
                break;

            case 'r':
            case 'R':
                reverse_links(&headptr);
                break;

            case 'e':
            case 'E':
            {
                char exit_choice;

                printf("\nS/s : Save and exit\n");
                printf("E/e : Exit without saving\n");

                printf("Enter choice: ");
                scanf(" %c", &exit_choice);

                if (exit_choice == 'S' ||
                    exit_choice == 's')
                {
                    save_file(headptr);
                }
                else if (exit_choice == 'E' ||
                         exit_choice == 'e')
                {
                    printf("Exiting without saving.\n");
                }
                else
                {
                    printf("Invalid choice!\n");
                    break;
                }

                delete_all(&headptr);

                printf("Exiting program. Goodbye!\n");

                exit(0);
            }

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
