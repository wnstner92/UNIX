#include <stdio.h>
#include "mymacro.h"

int main()
{
//#define A 0
#if A
printf("A is defined(1)\n");
#else

printf("A is not defined(2)\n");
#endif

#if 0

printf("A is not defined(3)\n");
#endif

#if 1

printf("B is not defined(4)\n");
#endif

#if defined(A) || defined(B)
printf("A or B is defined(5)\n");

#endif

/*
#ifndef D
#error This program must be compiled in D
#endif
*/


#if defined(A) && defined(B)

printf("A and B is not defined(6)\n");
#endif

#ifdef A

printf("A is  defined(7)\n");
#endif

#ifdef C
printf("A is  defined(8)\n");
#endif

printf("C is not defined(9)\n");

#ifdef __STDC__
    printf("This program conforms with the ANSI C standard\n");
#else
    printf("This program does not conforms with the ANSI C standard\n");
#endif

#ifdef __cplusplus
    printf("This computer is working with c++ \n");
#else
    printf("This computer is working with c \n");
#endif

printf("line %d\n", __LINE__);

#if A==1 // A>5 or A<1
printf("A: %d [999]\n",A);
#endif

return 0;
}
