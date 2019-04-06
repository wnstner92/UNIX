#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct chat{
	char user_name[LOGIN_NAME_MAX];
	char message[CHAR_MAX];

}Chat;

int main()
{
	Chat* chat = (Chat *)malloc(sizeof(Chat)*10);
	if(chat == NULL){return -1;}
	strcpy(chat[0].user_name, "leejunsoo");
	strcpy(chat[0].message, "");

	WINDOW *InputWnd, *OutputWnd, *LoginWnd;
	initscr();

	while(1)
	{
		int input, x=1;
		OutputWnd = subwin(stdscr, 9, 29, 0, 0);
		box(OutputWnd, '|', '-');
		waddstr(OutputWnd, "Output");
		scrollok(OutputWnd, TRUE); // use to scroll
		mvwprintw(OutputWnd, 1, x++, chat[x].message);
		x++;

		refresh();
		wrefresh(OutputWnd);

		LoginWnd = subwin(stdscr, 14, 12, 0, 29);
		box(LoginWnd, '|', '-');
		waddstr(LoginWnd, chat[0].user_name);
		//refresh();
		wrefresh(LoginWnd);
		//strcpy(chat[0].message, (char*)input);
		InputWnd = subwin(stdscr, 5, 29, 9, 0);
		box(InputWnd, '|', '-');
		waddstr(InputWnd, "Input");
		//mvscanw(1,1, chat[0].message);
		refresh();
		wrefresh(InputWnd);
	
		getstr(chat[0].message);
	}
	
	endwin();
	return 0;
}
