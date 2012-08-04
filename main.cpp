#include <curses.h>
#include <iostream>
#include "world.h"
#include "gui/screen.h"

/* You may need to include your ncurses headers, these files were made using pdcurses. */

int main(){
    Screen* screen = new Screen;

    int height = screen->height();
    int width = screen->width();

    WINDOW* dungeon = screen->createWindow(height, width/2, 0, 0);
    WINDOW* message = screen->createWindow(height, width/2, 0, width/2);

    int cx = dungeon->_maxx/2;
    int cy = dungeon->_maxy/2;
    int c;

    World *world = new World;

    while(((c=getch()))!=27){
        switch(c) {
        case(KEY_UP):
            if(cy-1 > 0) {
                cy--;
                screen->print(message, "Moved up");
            }
            break;
        case(KEY_DOWN):
            if(cy+1 < height -1) {
                cy++;
                screen->print(message, "Moved down");
            }
            break;
        case(KEY_LEFT):
            if(cx-1 > 0) {
                cx--;
                screen->print(message, "Moved left");
            }
            break;
        case(KEY_RIGHT):
            if(cx+1 < width/2 - 1) {
                cx++;
                screen->print(message, "Moved right");
            }
            break;
        }

        world->drawWorld(dungeon, width/2, height);
        mvwprintw(dungeon, cy, cx, "@");

        wrefresh(dungeon);
    }
    delete world;
    delwin(dungeon);
    delwin(message);
    endwin();
    return 0;
}

