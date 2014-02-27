#include "Student.h"
#include "iostream"

using namespace std;

typedef struct Subjects
{
	char name_of_subject[20];
	int mark;
	struct Subjects *list;
	struct Subjects *next;
};

class Student
{
	char* group;
	char* name_of_student;
	struct Subjects subject;

public:
	/*Student();
	Student( int gr );
	Student( char* gr );
	~Student();*/
	void PushMark();
};

