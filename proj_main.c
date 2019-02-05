#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>

#include "structs.h"
#include "proj1.h"
#include "proj2.h"

#define OUTPUT_FILENAME "final_proj_patients.txt"

void printMainMenu();


int main(void)
{
	struct Node *head;   //pointer to the first node (element) of the linked list
	char X;
	unsigned int id;
	unsigned int sorting_option;
	int done = 0;

	/* Initialize the linked list to be empty */
	head = NULL;


	while (!done)
	{
		printMainMenu();
		printf(">>>>> Enter a command : ");

		X = getchar();
		fflush(stdin);
		X = toupper(X);
	
		switch(X) {

			case 'D':
			//	Display list
				displayList(head);
				break;

			case 'A':
				// Add new patient
				head = addNewPatient(head);
				displayList(head);
				break;

			case 'R':
				// Remove patient
				if (head == NULL)
					printf("The list is empty.\n");
				else {
					displayList(head);
					do {
						printf(">>>>> Choose a Patient ID : ");
					} while (scanf("%u", &id) == 0);
					head = removePatient(head, id);
					displayList(head);
				}
				break;

			case 'U':
				//	Update patient checkup history
				if (head == NULL)
					printf("The list is empty.\n");
				else {
					displayList(head);
					do {
						printf(">>>>> Choose a Patient ID : ");
					} while (scanf("%u", &id) == 0);
					head = updatePatient(head, id);
				}
				break;

			case 'C':
				// Show patient checkup history
				if (head == NULL)
					printf("The list is empty.\n");
				else {
					displayList(head);
					do {
						printf(">>>>> Choose a Patient ID : ");
					} while (scanf("%u", &id) == 0);
					showCheckupHistory(head, id);
				}
				break;

			case 'S':
				// Sort list by patient name OR by ward number
				if (head == NULL)
					printf("The list is empty.\n");
				else {
					do {
						printf(">>>>> Enter 1 to sort by Patient Name, Enter 2 to sort by Ward Number : ");
					} while (scanf("%u", &sorting_option) == 0 || (sorting_option != 1 && sorting_option != 2));

					if (sorting_option == 1)
						head = sortByName(head);
					else //if (sorting_option == 2)
						head = sortByWardNumber(head);
					displayList(head);
					//now put the list back in its original order!
					head = sortByID(head);
				}
				break;

			case 'Q':
			// Terminate
				if (head != NULL) {
					write2File(head, OUTPUT_FILENAME);
					head = freeList(head);
				}
				done = 1;
				break;

		} //end switch

		fflush(stdin);

	} //end while

	return 0;
}


void printMainMenu()
{
	printf("*******************************************************\n");
	printf("*******************************************************\n");
	printf("                Main Menu\n");
	printf("*******************************************************\n");
	printf("\tD\t\tDisplay List\n");
	printf("\tA\t\tAdd New Patient\n");
	printf("\tR\t\tRemove Patient\n");
	printf("\tU\t\tUpdate Patient Checkup History\n");
	printf("\tC\t\tShow Patient Checkup History\n");
	printf("\tS\t\tSort list by Patient Name or by Ward Number\n");
	printf("\tQ\t\tTerminate Program\n");
	printf("*******************************************************\n");
	printf("*******************************************************\n");

}

