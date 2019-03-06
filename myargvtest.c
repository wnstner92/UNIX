#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
execl("/bin/ls", "/bin/ls", "-al", "/tmp" , NULL);
printf("argc: %d\n", argc);
printf("FileName: %s\n", argv[0]);
printf("%s %s\n", argv[1], argv[2]);

return 0;
}
