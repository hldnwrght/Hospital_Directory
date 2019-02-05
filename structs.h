#ifndef __STRUCTS__
#define __STRUCTS__


struct Date {
	unsigned int day;	// a value between 1 and 31
	unsigned int month;	// 1: January, ..., 12: December
	unsigned int year;	// birth year, for example 1986
	unsigned int hour;	//0: midnight, 1: 1am, ..., 23 : 11pm
};

struct Patient {
	unsigned int ID;	//unique hospital admission number for each patient
	char name[30];		//Patient's name
	char illness[100];
	unsigned short wardNumber;	//ward number where patient is staying
	unsigned int num_checkups;  //number of currently used elements in the checkupHistory array
	struct Date checkupHistory[100];

};

struct Node {
	struct Patient data;
	struct Node * hook;
};



#endif

