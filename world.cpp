#include "world.h"

World::World()
{
}

void World::drawWorld(int width, int height) const{
    for (int x=0; x<width; x++){
        for (int y=0; y<height; y++){
            if (y==0)
                mvprintw(y, x, "#");
            else if (y==height-1)
                mvprintw(y, x, "#");
            else if (x==0)
                mvprintw(y, x, "#");
            else if (x==width-1)
                mvprintw(y, x, "#");
            else
                mvprintw(y, x, ".");
        }
        mvprintw(0, x, "#");
    }
}
