#include "apue.h"
#include <sys/wait.h> // waitpid()
#include <unistd.h> // getcwd()
#include <sys/param.h> // MAXHOSTNAMELEN
#include <time.h> // localtime()
#include <limits.h> // LOGIN_NAME_MAX

int cuserid();

int main(void)
{
	char buf[MAXLINE];
	char hostname[MAXHOSTNAMELEN];
	pid_t pid;
	int status;
	char *cwd;
	char username[LOGIN_NAME_MAX]; // L_cuserid is in the stdio.h
	if(cuserid(username) == 0)
	{
		fprintf(stderr, "can not find login name\n");
		exit(1);
	}
	
	gethostname(hostname, MAXHOSTNAMELEN);
	cwd = getcwd(NULL, BUFSIZ);

	time_t T = time(NULL);
	struct tm tm = *localtime(&T);
	
	if(tm.tm_hour <13)
	printf("[%02d:%02d:%02dAM]%s@%s(%s)$ ",tm.tm_hour%12, tm.tm_min, tm.tm_sec, hostname, username, cwd);
	 else 
	printf("[%02d:%02d:%02dPM]%s@%s(%s)$ ",tm.tm_hour%12, tm.tm_min, tm.tm_sec, hostname, username, cwd);

	

	while(fgets(buf, MAXLINE, stdin)!=NULL)
	{
		if(buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0;

		if((pid = fork()) < 0)
		{
			err_sys("fork error");
		}else if(pid == 0)
		{
			execlp(buf, buf, (char*)0);
			err_ret("couldn't execute: %s", buf);
			exit(127);
		}

		if((pid = waitpid(pid, &status, 0)) < 0)
			err_sys("waitpid error");
		
	if(tm.tm_hour <13)
	printf("[%02d:%02d:%02dAM]%s@%s(%s)$ ",tm.tm_hour%12, tm.tm_min, tm.tm_sec, hostname, username, cwd);
	 else 
	printf("[%02d:%02d:%02dPM]%s@%s(%s)$ ",tm.tm_hour%12, tm.tm_min, tm.tm_sec, hostname, username, cwd);
	}
	exit(0);
}
