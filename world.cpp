#include "world.h"

World::World()
{
}

void World::drawWorld(WINDOW *dungeon, int width, int height) const{
    for (int x=0; x<width; x++){
        for (int y=0; y<height; y++){
            if (y==0)
                mvwprintw(dungeon, y, x, "#");
            else if (y==height-1)
                mvwprintw(dungeon, y, x, "#");
            else if (x==0)
                mvwprintw(dungeon, y, x, "#");
            else if (x==width-1)
                mvwprintw(dungeon, y, x, "#");
            else
                mvwprintw(dungeon, y, x, ".");
        }
        mvwprintw(dungeon, 0, x, "#");
    }
}
