#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "proj2.h"

char *NAMES [] = {"Farhad Akbar", "Bassam Awad Alanazi", "Roger Cungtha Biak", "Christian Curtis Collier", "Tanner Durnil", "Melissa Gudeman", "Daniel Patrick Kobold Jr", "Travis Lee Leondis", "Cleopatrio Soares Neto", "Daniel Biaklian Sang", "Bryant Bernard", "Joaquin John Garcia", "Jacob Austin Shebesh", "D'Artagnan S. Engle", "You Zhou", "SYAMIL ALI", "Joi Ashlyn Officer"};
char *ILLNESSES[] = { "Heart disease", "Diabetes", "Melanoma", "Colon Cancer", "Eye Surgery", "Lung Cancer", "High Blood Pressure", "Ear infection" };
const int NumWards = 10;


void fillNewPatientData(struct Patient * V)
{
	static int first_time = 1;
	time_t t;

	/* Intialize the random number generator */
	if (first_time) {
		srand((unsigned)time(&t));
		first_time = 0;
	}

	V->ID = rand() % 9000 + 1000;
	strcpy(V->name, NAMES[rand() % 17]);
	strcpy(V->illness, ILLNESSES[rand() % 8]);
	V->wardNumber = 100 + rand() % NumWards;
	V->num_checkups = 0;

}


//one the famous sorting methods, adapted to linked lists ...
struct Node * sortByID(struct Node * head)
{
	int done;
	struct Node *ptr;
	struct Node *tmp, *stmp;


	//Special cases: when the list contains 0 or 1 elements, then no need to sort!
	if (head == NULL || head->hook == NULL)
		return head;


	done = 0;


	while(!done)
	{
		done = 1;
		for (ptr = head;  ptr->hook != NULL; )
		{
			if(ptr->data.ID > ptr->hook->data.ID)
			{
				done = 0;

				if(ptr == head)
				{
					head = ptr->hook;
					tmp = head->hook;
					head->hook = ptr;
					ptr->hook = tmp;

				} else {
					tmp = head;
					while (tmp->hook != ptr)
						tmp = tmp->hook;
					stmp = ptr->hook->hook;
					tmp->hook = ptr->hook;
					ptr->hook->hook = ptr;
					ptr->hook = stmp;					
				}

			}
			else
				ptr=ptr->hook;
		}
	}

	return head;
}

