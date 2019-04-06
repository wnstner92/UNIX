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
	a_student = (struct student*)malloc(sizeof(struct student) * 10);
							// struct student[10]

	if (a_student == NULL)
	{
		return -1;
	}

	a_student[0].student_id = 20156666;
	strcpy(a_student[0].name, "kim"); // a_student[1] is address
	
	a_student[1].student_id = 20156667;
	strcpy(a_student[1].name, "park");

	printf("%d\n", a_student[1].student_id);

	printf("%s\n", a_student[1].name);
	free(a_student);

	return 0;
}
