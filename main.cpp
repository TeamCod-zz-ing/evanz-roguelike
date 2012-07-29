#include <curses.h>
#include <iostream>
#include "world.h"

/* You may need to include your ncurses headers, these files were made using pdcurses. */

int main(){
    initscr();

    noecho();
    raw();

    nodelay(stdscr, true);
    keypad(stdscr, true);

    curs_set(0);

    int width, height;
    getmaxyx(stdscr,height,width);

    int cx = 40, cy = 12;
    int c;

    World world;

    while(((c=getch()))!=27){
        if (c==KEY_UP && cy-1 > 0)
            cy--;
        if (c==KEY_DOWN && cy+1 < height - 1)
            cy++;
        if (c==KEY_LEFT && cx-1 > 0)
            cx--;
        if (c==KEY_RIGHT && cx+1 < width - 1)
            cx++;

        world.drawWorld(width, height);

        mvprintw(cy, cx, "@");
        refresh();
    }

    endwin();
    return 0;
}

