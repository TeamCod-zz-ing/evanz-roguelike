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

void Screen::createWindow(int windowType){
    switch(windowType){
    case DUNGEON:
        m_dungeon = newwin(m_height, m_width/2, 0, 0);
        break;
    case LOG:
        m_log = newwin(m_height/3, m_width/2, 2*(m_height/3), m_width/2);
        scrollok(m_log, true);
        break;
    }
}

void Screen::print(const char *msg){
    scroll(m_log);
    mvwprintw(m_log, m_log->_maxy-1, 1, msg);
    wrefresh(m_log);
}

void Screen::drawWorld(int cy, int cx){
    for (int x=0; x<m_dungeon->_maxx; x++){
        for (int y=0; y<m_dungeon->_maxy; y++){
            if (y==0)
                mvwprintw(m_dungeon, y, x, "#");
            else if (y==m_dungeon->_maxy-1)
                mvwprintw(m_dungeon, y, x, "#");
            else if (x==0)
                mvwprintw(m_dungeon, y, x, "#");
            else if (x==m_dungeon->_maxx-1)
                mvwprintw(m_dungeon, y, x, "#");
            else
                mvwprintw(m_dungeon, y, x, ".");
        }
        mvwprintw(m_dungeon, 0, x, "#");
    }
    mvwprintw(m_dungeon, cy, cx, "@");
    wrefresh(m_dungeon);
}
