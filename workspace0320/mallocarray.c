#include <stdio.h>
#include <stdlib.h>

int main()
{
	//int student_id[3];
	int *student_id;
	student_id = (int *)malloc(sizeof(int) * 3);
	
	if ( student_id == NULL )
	{
		printf("out of memory\n");
	}

	student_id[0] = 2017333;
	student_id[1] = 2017334;
	student_id[2] = 2017335;

	for(int i=0; i<3;i++)	
	{
		printf("%d\n", student_id[i]);
	}
	

	return 0;
}
