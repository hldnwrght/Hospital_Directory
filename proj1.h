#include "structs.h"

struct Node * findPatientbyID(struct Node * head, unsigned int ID);
void displayList(struct Node * head);
struct Node * addNewPatient(struct Node * head);
struct Node * removePatient(struct Node * head, unsigned int ID);
struct Node * updatePatient(struct Node * head, unsigned int ID);
void showCheckupHistory(struct Node * head, unsigned int ID);
struct Node * sortByName(struct Node * head);
struct Node * sortByWardNumber(struct Node * head);
void write2File(struct Node  * head, char * filename);
struct Node  * freeList(struct Node * head);



