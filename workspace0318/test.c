#include <pthread.h> // lpthread option
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>
#include <ncurses.h>
void *print();
void write(char*m);
 int Break;
int main()
{
 initscr();
 pthread_t trd_id;
 int sid = shmget(200724514,32,0666|IPC_CREAT);
 char* msg = (char*)shmat(sid,0,0);
 memset(msg,0,32);
 pthread_create(&trd_id,NULL,print,NULL);
 
 
 while(Break != 1)
 {
  write(msg);
 }
 
 pthread_join(trd_id,NULL);
 
 
 return 0;
}
void *print()
{
 int sid = shmget(200724514,32,0666|IPC_CREAT);
 char* msg = (char*)shmat(sid,0,0);
 WINDOW* chat;
 chat = subwin(stdscr,20,60,0,0);
 box(chat,'|','-');
 while( Break != 1)
 {
  box(chat,'|','-');
  if(strlen(msg)>0)
  {
   if(strcmp(msg,"/q")==0)
     break;
    mvwprintw(chat,3,3,"%s\n",msg);
    memset(msg,0,32); 
  }
  wrefresh(chat);
//     wclear(chat); 
  //  memset(msg,0,32); 
 }
}
void write(char*m)
{
 WINDOW* inp;
 inp = subwin(stdscr,10,60,20,0);
 box(inp,'|','-');
 mvwscanw(inp,2,2,"%s",m);
 if(strcmp(m,"/q")==0)
  Break = 1;
 wclear(inp);
}
