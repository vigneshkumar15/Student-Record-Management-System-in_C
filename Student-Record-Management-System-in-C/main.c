#include"header.h"

int main()
{
	SLL *headptr=0;
	char op,ch;

	read_file(&headptr);

	while(1)
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
		scanf(" %c",&op);

		switch(op)
		{
			case 'a':
			case 'A':
				add_student(&headptr);
				break;

			case 'd':
			case 'D':
				delete_student(&headptr);
				break;

			case 's':
			case 'S':
				print_node(headptr);
				break;

			case 'm':
			case 'M':
				modify_student(headptr);
				break;

			case 'v':
			case 'V':
				save_file(headptr);
				break;

			case 't':
			case 'T':
				sort_student(headptr);
				break;

			case 'l':
			case 'L':
				delete_all(&headptr);
				break;

			case 'r':
			case 'R':
				reverse_list(&headptr);
				break;

			case 'e':
			case 'E':
				printf("\nS/s : Save and exit\n");
				printf("E/e : Exit without saving\n");
				printf("Enter your choice: ");
				scanf(" %c",&ch);

				if(ch=='s' || ch=='S')
					save_file(headptr);

				free_all(&headptr);
				printf("Program terminated\n");
				return 0;

			default:
				printf("Invalid choice\n");
		}
	}
}
