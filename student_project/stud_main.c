#include"header.h"

int main()
{
    SLL *headptr=0;
    char ch;

    read_file(&headptr);

    while(1){
        printf("\033[32m********  STUDENT RECORD MENU  ********\n");
        printf("a/A : Add new record\n");
        printf("d/D : Delete a record\n");
        printf("s/S : Show the list\n");
        printf("m/M : Modify a record\n");
        printf("v/V : Save records\n");
        printf("e/E : Exit\n");
        printf("t/T : Sort the list\n");
        printf("l/L : Delete all the records\n");
        printf("r/R : Reverse the list\n");
        printf("Enter your choice:\033[31m\n");

        scanf(" %c",&ch);

        switch(ch){
            case 'a': case 'A': add_middle(&headptr); break;

            case 'd': case 'D': delete_node(&headptr); break;

            case 's': case 'S': print_node(headptr); break;

            case 'm': case 'M': printf("Modify not implemented yet\n"); break;

            case 'v': case 'V': save_file(headptr); break;

            case 't': case 'T': sort_data(headptr); break;

            case 'l': case 'L': delete_all(&headptr); break;

            case 'r': case 'R': reverse_links(&headptr); break;

            case 'e': case 'E': exit(0);

            default: printf("\033[31;4;1;5mUnknown choice\033[0m\n");
        }
    }
}
