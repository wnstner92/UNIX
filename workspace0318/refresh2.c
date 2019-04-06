#include <ncurses.h>
#include <unistd.h>

int main()
{
    int c = 0;
    initscr(); // Initialize the window
    noecho(); // Don't echo any key presses
    curs_set(FALSE); // Don't display a cursor

    while(c<1000)
    {
	mvprintw(0,0,"%d", c++);
	refresh();
	sleep(1);
    }

    //mvprintw(0,0,"Hello, world!"); // save in the buffer
    //refresh(); // display 
    sleep(10);


    endwin();
    return 0;
}
