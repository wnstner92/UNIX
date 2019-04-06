#include <stdio.h>
#include <ncurses.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 45 // maximum length of message
#define MAX_NUM 11 // maximum number of messages

/* struct for store messages */
struct storage{
    char* m_list[MAX_NUM];
};

/* initalize messages */
void storage_init(struct storage* s_ptr)
{
    int i;
    for(i=0;i<MAX_NUM;++i)
        s_ptr->m_list[i] = 0;
}

/* draw box layout*/
void draw(WINDOW* wnd)
{
    box(wnd,'+','-');
    wrefresh(wnd);
}

/* if message list is full, it returns 1(true).*/ 
int is_full(struct storage* s_ptr)
{
    int i;
    for(i=0;i<MAX_NUM;++i)
        if(s_ptr->m_list[i] == 0)
            return 0; // false
    return 1; // true
}

/* show messages in output window */
void display_output(WINDOW* win, struct storage* s_ptr, int beg)
{
    int i = beg;
    int line = 3;
    
    while(line <= MAX_NUM+2) {
        if(s_ptr->m_list[i] == 0)
            return ;
        mvwprintw(win,line,1,"> ");
        mvwprintw(win,line,3,s_ptr->m_list[i]); // show a message
        wrefresh(win);
        i++;
        i = i%MAX_NUM;
        line++;
        wrefresh(win);  
    }
}

int main(void) {
    struct storage s;
    char buf[MAX_SIZE] = {0,};
    const char* name1 = "user1";
    const char* name2 = "user2";
    int storage_pos = 0, del_pos = 0, pos = 0;
    int input;
    WINDOW* OutputWnd, *InputWnd, *InfoWnd;

    storage_init(&s);
    initscr();
    noecho(); // hide keyboard inputs
    keypad(stdscr,TRUE);
    curs_set(FALSE);
    refresh();

	/* determine the size of the windows */
    OutputWnd = subwin(stdscr, 15, 50, 0, 0);
    InputWnd = subwin(stdscr, 5, 50, 15, 0);
    InfoWnd = subwin(stdscr, 18, 30, 0, 50);

	/* draw windows */
    draw(OutputWnd); 
    draw(InputWnd);
    draw(InfoWnd);
    
    /* show participant's names in InfoWnd */
    mvwprintw(InfoWnd,1,2,name1);
    mvwprintw(InfoWnd,2,2,name2);
    wrefresh(InfoWnd);

	/* show guiding sentence in output window */
    mvwprintw(OutputWnd,1,2,"if you want to exit, press 'q'.");
    wrefresh(OutputWnd);

	/* input from keyboard */
	/* show input sentence in input window */
    while(1) {
        input = getch();
        clear();
        refresh();
        if(input=='q')
            break;
        if(input==263) {  // it means backspace
            if(pos!=0)
                pos--;
        }
        /* if input the new line, */
		/* it will be showes in output window */
        else if(input=='\n') { 	
        	/* if output window is full, */
			/* it will erase the oldest sentence */
            if(is_full(&s)) {
                storage_pos = del_pos;
                free(s.m_list[del_pos]);
                s.m_list[del_pos] = 0;
                del_pos++;
                del_pos = del_pos % MAX_NUM;    
            }

			/* store the input sentence */
			/* for showing it in output window */
            s.m_list[storage_pos] = (char*)malloc(strlen(buf));
            strcpy(s.m_list[storage_pos],buf);
            storage_pos++;

			/* initialize the input pos */
            pos = 0;
        }
        
        /* store the input charecter */
        /* for showing it in input window */
        else if(pos!=MAX_SIZE)
            buf[pos++] = (char)input;
        buf[pos] = '\0';

		/* draw the layout */
        draw(OutputWnd); 
        draw(InputWnd);
        draw(InfoWnd);

        mvwprintw(InfoWnd,1,2,name1);
        mvwprintw(InfoWnd,2,2,name2);
        wrefresh(InfoWnd);

        mvwprintw(OutputWnd,1,2,"if you want to exit, press 'q'.");
        wrefresh(OutputWnd);

        display_output(OutputWnd,&s,del_pos); 
        mvwprintw(InputWnd,1,1,buf);
        wrefresh(InputWnd);
    }
    endwin();
    return 0;
}
