#include <ncurses.h>
#include <unistd.h>

int main()
{
    initscr(); // Initialize the window
    //noecho(); // Don't echo any key presses
    //curs_set(FALSE); // Don't display a cursor


    mvprintw(0,0,"Hello, world!"); // save in the buffer
    refresh(); // display 
    sleep(10);


    endwin();
    return 0;
}
