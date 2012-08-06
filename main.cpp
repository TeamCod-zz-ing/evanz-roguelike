#include <curses.h>
#include <iostream>
#include "gui/screen.h"

/* You may need to include your ncurses headers, this build was created using pdcurses.
I've consolidated the world class into the screen class in an attempt to nudge things towards
an MVC type design.*/

int main(){
    Screen* screen = new Screen;

    screen->createWindow(DUNGEON);
    screen->createWindow(LOG);

    int cx = screen->dungeon()->_maxx/2;
    int cy = screen->dungeon()->_maxy/2;
    int c;

    while(((c=getch()))!=27){
        switch(c){
        case(KEY_UP):
            if(cy-1 > 0) {
                cy--;
                screen->print("Moved up");
            }
            break;
        case(KEY_DOWN):
            if(cy+1 < (screen->height() - 1)) {
                cy++;
                screen->print("Moved down");
            }
            break;
        case(KEY_LEFT):
            if(cx-1 > 0) {
                cx--;
                screen->print("Moved left");
            }
            break;
        case(KEY_RIGHT):
            if(cx+1 < (screen->width()/2 - 1)) {
                cx++;
                screen->print("Moved right");
            }
            break;
        }
        screen->drawWorld(cy, cx);
    }
    return 0;
}

