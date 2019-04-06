#include <stdlib.h>

int main()
{
	int *iptr;
	char *cptr;
	// malloc() always provides aligned memory
	cptr = malloc(sizeof(int) + 1); // 5byte
	// Increment the pointer by one, making it misaligned
	cptr++;
	iptr = (int *) cptr; // iptr is 0x100 
	// Dereference it as an int pointer, causing an unaligned access
	*iptr = 42;
	printf("%d\n", *iptr);
	return 0;
}
