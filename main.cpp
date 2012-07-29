#include <curses.h>
#include <iostream>
#include "world.h"

/* You may need to include your ncurses headers, these files were made using pdcurses. */
extern WINDOW  *createWindow(int height, int width, int y, int x) {
    WINDOW *window;
    window = newwin(height, width, y, x);
    wrefresh(window);
    return window;
}


WINDOW *dungeon;
WINDOW *message;
int main(){
    initscr();
    start_color();
    noecho();
    raw();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    curs_set(0);

    int width;
    int height;
    getmaxyx(stdscr,height,width);

    dungeon = createWindow(height, width/2, 0, 0);
    message = createWindow(height, width/2, 0, width/2);
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    wcolor_set(message, 1, 0);

    int cx = dungeon->_maxx/2;
    int cy = dungeon->_maxy/2;
    int c;

    World world;

    while(((c=getch()))!=27){
        switch(c) {
        case(KEY_UP):
            if(cy-1 > 0)
                cy--;
            break;
        case(KEY_DOWN):
            if(cy+1 < height -1)
                cy++;
            break;
        case(KEY_LEFT):
            if(cx-1 > 0)
                cx--;
            break;
        case(KEY_RIGHT):
            if(cx+1 < width/2 - 1)
                cx++;
            break;
        }

    /*
        if (c==KEY_UP && cy-1 > 0)
            cy--;
        if (c==KEY_DOWN && cy+1 < height - 1)
            cy++;
        if (c==KEY_LEFT && cx-1 > 0)
            cx--;
        if (c==KEY_RIGHT && cx+1 < width - 1)
            cx++;
    */

        world.drawWorld(dungeon, width/2, height);

        mvwprintw(dungeon, cy, cx, "@");
        mvwprintw(message, 1, 1, "This is a test message in green!");

        wrefresh(dungeon);
        wrefresh(message);
    }

    endwin();
    return 0;
}

