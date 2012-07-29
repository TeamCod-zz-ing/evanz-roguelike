#ifndef WORLD_H
#define WORLD_H

#include <curses.h>

class World {
public:
    World();

    //drawWorld() will print the world ASCII to the screen, in the future there could be a function for random world generation which would return a buffer to be drawn by drawWorld().
    void drawWorld(WINDOW *dungeon, int width, int height) const;
private:
    //Many different world attributes could go here: size, 'type', level, a map buffer, etc.
};

#endif // WORLD_H
