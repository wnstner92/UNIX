#include <stdio.h>

int main()
{
int testhour, testmin;
scanf("%d", &testhour);

scanf("%d", &testmin);
if(testhour <13)
printf("%d : %dAM", testhour%12, testmin);
else

printf("%d : %dPM", testhour%12, testmin);
}
