#ifndef SCREEN_H
#define SCREEN_H

#include <curses.h>
#include <string>

class Screen
{
public:
    Screen();
    ~Screen();
    WINDOW* createWindow(int height, int width, int y, int x);
    int height() {return m_height;}
    int width() {return m_width;}
    void print(WINDOW* window, const char* msg);

private:
    WINDOW* m_map;
    WINDOW* m_log;
    WINDOW* m_status;
    int m_height;
    int m_width;
};

#endif // SCREEN_H
