#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NUM 1004

typedef struct user {
   int status;
   int numberOfMessage;
   char user_name[LOGIN_NAME_MAX];
   char *message[MAX_NUM];
}User;

void refreshWnd(WINDOW *win)
{
	refresh();
	wrefresh(win);
}

void setWnd(WINDOW* win, char* winName)
{
   scrollok(win, TRUE); // use to scroll
   box(win, '|', '-');
   waddstr(win, winName);
   refreshWnd(win);
}

void addStr(WINDOW *win, int x, int y, char* inputValue)
{
   mvwprintw(win, x, y, inputValue);
   wrefresh(win);
}

int saveWord(int inputValue, char* inputBuf, int* temp_index)
{
   int result = 0;

   if (inputValue == '\n') {
      result = 1;
      inputValue = '\0';
   }
   else { result = 0; }

   inputBuf[(*temp_index)++] = inputValue;
   return result;
}

int main()
{
   initscr();
   char temp_buf[CHAR_MAX] = {};
   char total_buf[CHAR_MAX] = {};
   int buf_index = 0;
   int inputWord;
   int i;
   User user;
   curs_set(FALSE);
   strcpy(user.user_name, "leejunsoo");
   user.numberOfMessage = 0;
   //strcpy(user.message[0], "i");

   WINDOW *InputWnd, *OutputWnd, *LoginWnd;


   while (1)
   {
      OutputWnd = subwin(stdscr, 15, 50, 0, 0);
      LoginWnd = subwin(stdscr, 18, 30, 0, 50);
      InputWnd = subwin(stdscr, 3, 50, 15, 0);
      setWnd(OutputWnd, "Output");
      setWnd(LoginWnd, "User");
      setWnd(InputWnd, "Input");

      mvwprintw(LoginWnd, 1, 1, user.user_name);
      refreshWnd(LoginWnd);

      inputWord = getch();
      if (saveWord(inputWord, temp_buf, &buf_index) == 1)
      {
        clear();
    
        user.message[user.numberOfMessage] = (char*)malloc(strlen(temp_buf) + 1);
        strcpy(user.message[user.numberOfMessage], temp_buf);
        user.numberOfMessage++;
   /*
		for(i=0;i<user.numberOfMessage;++i)
        mvwprintw(OutputWnd, 1+i, 1, user.message[i]);
        refreshWnd(OutputWnd);
*/
        mvwprintw(OutputWnd, 1+i, 1, temp_buf);
        refreshWnd(OutputWnd);
      }
      else {
         mvwprintw(InputWnd, 1, 1, temp_buf);
         refreshWnd(InputWnd);
      }

   }
   free(user.message);
   endwin();
   return 0;
}
