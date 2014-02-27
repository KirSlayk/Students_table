//#include "Student.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <iostream>

using namespace std;

struct Subjects
{
	char* name_of_subject;
	int mark;
	struct Subjects *prev;
	struct Subjects *next;
};

class Student
{
	char *group;
	char *name_of_student;
public:
	Student();
	/*Student( int gr );
	Student( char* gr );
	~Student();*/
	void PushMark();
	void PushSubject( struct Subjects *struct_object, Student **student, int n );
	Subjects subject;
};

Student::Student()
{
	int ch = NULL;
	int i = 1;
	cout<<"Enter name of this srudent\n";
	name_of_student = (char*)calloc(1, sizeof(char));
	while ( (ch = getchar())!='\n' ){
		name_of_student[i - 1] = (char)ch;
		name_of_student = (char*)realloc (name_of_student, ++i);
	}
	name_of_student[i - 1] = '\0';
	
	i = 1;
	cout<<"\n";
	cout<<"Enter name of group\n";
	group = (char*)calloc(1, sizeof(char));
	while ( (ch = getchar())!='\n' ){
		group[i - 1] = (char)ch;
		group = (char*)realloc (group, ++i);
	}
	group[i - 1] = '\0';
}


void Student::PushSubject( struct Subjects *struct_object, Student **student, int n )
{
	while ( struct_object->name_of_subject ){
		for ( int i = 0; i < n; i++ ){
			student[i]->subject.name_of_subject = struct_object->name_of_subject;
			}
		struct_object = struct_object->next;
	}
}



void Push ( struct Subjects **Tail )
{
	int i = 0;
	struct Subjects *Present;
	static int head = 1;
	char repeat = 'y';
	do{	
		Present = (Subjects*) malloc(sizeof(Subjects));
		cout<<"Name of subject: ";
		Present -> name_of_subject = new char[20];
		cin>> Present -> name_of_subject;
		
		if ( head ){
			head = 0;
			Present->prev = NULL;
			*Tail = Present;
			}
		else {
			Present->prev=*Tail; //”казываем адрес на предыдущий элемент в соотв. поле
			(*Tail)->next=Present; //”казываем адрес следующего за хвостом элемента
			*Tail=Present; //ћен€ем адрес хвоста
		}
		printf("Do you want enter a new subject?\n");
		cin>> repeat ;
		cout<<"\n";

	} while ( repeat == 'y' );
	(*Tail)->next = NULL;
	printf("\n");
}

void GoTopOfList( struct Subjects **struct_object )
{
	while ( (*struct_object)->prev )
		(*struct_object) = (*struct_object)->prev;
}


void Help()
{
	printf(" HELP\n");
	printf(" -y   yes\n -n   no\n -b   back\n -push   entering new data\n -show   display\n -stud   information about student's\n\n -subj   enter new subject's\n");
}

char command[10][6] = {
	"-y",
	"-n",
	"-b",
	"-push",
	"-show",
	"-stud",
	"-subj",
};

void main()
{
	Student *student;
	struct Subjects *struct_object;
	int n = 0;
	char *buffer;

	Help();

	buffer = new char[6];
	
	cout<<"Enter number of students ";
	cin>> n;
	
	student = (Student*)malloc(n*sizeof(Student));

	while (1){
		cin>> buffer;
		getchar();
		if ( !strcmpi( buffer, command[5]) )
			for ( int i = 0; i < n; i++)
				student[i] = Student();
		else if ( !strcmpi( buffer, command[6]) ){
			Push( &struct_object );
			GoTopOfList( &struct_object );
			student->PushSubject( struct_object, &student, n );
		}
	}
	
	system("pause");
}