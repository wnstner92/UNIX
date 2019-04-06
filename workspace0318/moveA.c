#include <ncurses.h>
#include <unistd.h>

int main()
{
    int row = 10, col = 10; // x,y coordinates
    initscr(); // Initialize the window
    
    keypad(stdscr, TRUE);
    while(1)
    {
        int input = getch();
	clear();
	switch(input)
	{
	    case KEY_UP:
		mvprintw(--row, col, "A");
		continue;
	    case KEY_DOWN:
		mvprintw(++row, col, "A");
		continue;
	    case KEY_LEFT:
		mvprintw(row, --col, "A");
		continue;
	    case KEY_RIGHT:
		mvprintw(row, ++col, "A");
		continue;
	}	
	if(input == 'q') break;


    }

    endwin();
    return 0;
}
