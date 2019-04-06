#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
	int student_id;
	char name[10];
};

int main()
{
	
	struct student* a_student;
	a_student = (struct student*)malloc(sizeof(struct student));

	a_student->student_id = 20156666;
	strcpy(a_student->name, "kim");
	



	free(a_student);

	return 0;
}
