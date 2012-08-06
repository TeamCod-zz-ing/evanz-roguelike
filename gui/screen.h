#ifndef SCREEN_H
#define SCREEN_H

#include <curses.h>
#include <string>

enum {DUNGEON, LOG, STATUS};

class Screen
{
public:
    Screen();
    ~Screen();
    void createWindow(int windowType);
    int height() {return m_height;}
    int width() {return m_width;}
    WINDOW* dungeon() {return m_dungeon;}
    void print(const char* msg);
    void drawWorld(int cy, int cx);
private:
    WINDOW* m_dungeon;
    WINDOW* m_log;
    int m_height;
    int m_width;
};

#endif // SCREEN_H
