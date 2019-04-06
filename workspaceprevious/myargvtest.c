#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
printf("argc: %d\n", argc);
printf("FileName: %s\n", argv[0]);
printf("%s %s\n", argv[1], argv[2]);
printf("uid = %d, gid = %d\n", getuid(), getgid());
execl("/bin/ls", "/bin/ls", "-al", "/tmp" , NULL);
return 0;
}
