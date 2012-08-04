#include "screen.h"


Screen::Screen(){
    initscr();
    start_color();
    noecho();
    raw();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    curs_set(0);
    getmaxyx(stdscr, m_height, m_width);
}

Screen::~Screen(){
        endwin();
}

WINDOW* Screen::createWindow(int height, int width, int y, int x) {
    WINDOW *window;
    window = newwin(height, width, y, x);
    wrefresh(window);
    return window;
}

void Screen::print(WINDOW* window, const char* msg) {
    scrollok(window, true);
    scroll(window);
    mvwprintw(window, window->_maxy-1, 1, msg);
    wrefresh(window);
}
