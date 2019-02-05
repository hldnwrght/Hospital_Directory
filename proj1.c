#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "proj1.h"
#include "proj2.h"
#include <time.h>
#include <stdio.h>


/* This functions returns a pointer to the node containing the given patient's record */
struct Node * findPatientbyID(struct Node * head, unsigned int ID){
	struct Node * ptr = NULL;
	struct Node* temp = head;
	while (temp->data.ID != ID)
	{
		temp = temp->hook;
	}
	ptr = temp;
	return ptr;   //pointer to the node containing the patient's data
}


/* Display current elements of the linked list in their current order. For each element, display the patient's name, ID, and ward number on a single line, separated by commas .  */
void displayList(struct Node * head) {
	struct Node *current = head;
	while (current != NULL)
	{
		printf("%s,%d,%d\n", current->data.name, current->data.wardNumber, current->data.ID);
		current = current->hook;
	}
}


/* This function first calls genNewPatient, then stores the returned data in a new Node structure, and finally attaches this node at the start of the linked list */
struct Node * addNewPatient(struct Node * head) {
	struct Node *patient;
	patient = (struct Node*) malloc(sizeof(struct Node));
	fillNewPatientData(patient);
	if (head == NULL)
	{
		head = patient;
		patient->hook = NULL;
		return head;
	}
	else
	{
		patient->hook = head;
	}
	
}


/* This function first find the Node where the given patient's record is stored in the list, then deletes it from the list */
struct Node * removePatient(struct Node * head, unsigned int ID) {
	struct Node *current = head;
	struct Node *temp = head;
	while (current->data.ID != ID)
	{
		if (current->hook == NULL)
		{
			printf("ID not found\n\n");
			break;
		}
		temp = current;
		current = current->hook;
	}
	
	if(current->hook != NULL)
	{
		temp->hook = current->hook;
		free(current);
	}
	return head;
}


/* This function adds today's date and current hour as a new checkup date in the checkupHistory field of the given patient's record */
struct Node * updatePatient(struct Node * head, unsigned int ID) {
	struct Node *temp;
	time_t t;
	struct tm* currTime;
	time(&t);
	currTime = localtime(&t);
	int x;
	temp = findPatientbyID(head, ID);
	x = temp->data.num_checkups;
	temp->data.checkupHistory[x].day = currTime->tm_mday;
	temp->data.checkupHistory[x].hour = currTime->tm_hour;
	temp->data.checkupHistory[x].month = (currTime->tm_mon) + 1;
	temp->data.checkupHistory[x].year = (currTime->tm_year) + 1900;
	(temp->data.num_checkups)++;
	return head;
}


void showCheckupHistory(struct Node * head, unsigned int ID) {
	struct Node *temp;
	int y;
	temp = findPatientbyID(head, ID);
	int x = temp->data.num_checkups;
	if (x == 0)
	{
		printf("No Checkups on file\n");
	}
	else if (x > 0)
	{
		for (y = 0; y < x; y++)
		{
			printf("%d) Day: %d Month: %d Year: %d Time: %d\n", y + 1, temp->data.checkupHistory[y].day, temp->data.checkupHistory[y].month, temp->data.checkupHistory[y].year, temp->data.checkupHistory[y].hour);
		}
	}
	printf("Press enter to continue");
	getchar();
	getchar();
}


struct Node * sortByName(struct Node * head) {

	return head;
}


struct Node * sortByWardNumber(struct Node * head) {
	int x;
	struct Node *ptr;
	struct Node *temp, *temp2;

	if (head == NULL || head->hook == NULL)
	{
		return head;
	}


	x = 0;


	while (!x)
	{
		x = 1;
		for (ptr = head; ptr->hook != NULL; )
		{
			if (ptr->data.wardNumber > ptr->hook->data.wardNumber)
			{
				x = 0;

				if (ptr == head)
				{
					head = ptr->hook;
					temp = head->hook;
					head->hook = ptr;
					ptr->hook = temp;

				}
				else {
					temp = head;
					while (temp->hook != ptr)
						temp = temp->hook;
					temp2 = ptr->hook->hook;
					temp->hook = ptr->hook;
					ptr->hook->hook = ptr;
					ptr->hook = temp2;
				}

			}
			else
				ptr = ptr->hook;
		}
	}
	return head;
}


/* This function writes the information in all patient records into a text file */
void write2File(struct Node  * head, char * filename) {
	FILE *file = fopen(filename, "w");
	int x = 1;
	struct Node *current = head;
	while (current != NULL)
	{
		fprintf(file, "%d) %d %s %d %s %d \n", x, current->data.ID, current->data.name, current->data.wardNumber, current->data.illness, current->data.num_checkups);
		current = current->hook;
		x++;
	}
	fclose(file);
}


/* This function deallocates all the dynamic variables used to store the nodes of the linked list */
struct Node  * freeList(struct Node * head) {
	struct Node *current = head;
	struct Node *temp = head;
	while (current->hook != NULL)
	{
		temp = current->hook;
		free(current);
		current = temp;
	}
	head = NULL;
	return head;
}

