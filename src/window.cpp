#include "globals.h"
#include "window.h"
#include <algorithm>

// Signal handler - ASYNC, keep minimal!
void window_handler(int sig) {
    (void)sig;
    g_need_resize = true;
}

// Resize windows
void window_resize() {
    endwin();
    refresh();
    
    getmaxyx(stdscr, h, w);
    
    // Minimum size protection
    if (h < 3 || w < 10) return;
    
    // Delete old windows
    delwin(topbar);
    delwin(body);
    
    // Recreate with new dimensions
    topbar = newwin(1, w, 0, 0);
    body = newwin(h - 2, w, 2, 0);
    keypad(body, TRUE);
    
    // Redraw everything
    clear();
    refresh();
    update_topbar(topbar);
    print_to_body(body);
}


void print_to_body(WINDOW* body) {
    werase(body);

    int height, width;
    getmaxyx(body, height, width);

    for (int i = 0; i < height && (top_line + i) < (int)buffer.size(); i++) {
        const std::string& line = buffer[top_line + i];

        std::string visible;
        if ((int)line.size() > left_col)
            visible = line.substr(left_col, width);
        else
            visible = "";

        mvwprintw(body, i, 0, "%s", visible.c_str());
    }

    wrefresh(body);
}

void update_topbar(WINDOW* topbar) {
    werase(topbar);

    std::string version = "micro v1.0";
    mvwprintw(topbar, 0, w - version.length(), "%s", version.c_str());

    int body_height = getmaxy(body);
    int last_visible = top_line + body_height;
    if (last_visible > buffer.size()) {
        last_visible = buffer.size();
    }
    
    if (buffer.empty()) {
        mvwprintw(topbar, 0, 0, "line 0 / 0");
    } else {
        mvwprintw(topbar, 0, 0, "line %d-%d / %d", 
                  top_line + 1,
                  last_visible,
                  buffer.size());
    }

    int x = std::max(0, w/2 - (int)filename.size()/2);
    mvwprintw(topbar, 0, x, "%s", filename.c_str());

    wrefresh(topbar);
}