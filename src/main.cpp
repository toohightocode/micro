#include "globals.h"
#include "window.h"
#include "input.h"
#include "file.h"
#include <iostream>
#include <csignal>
#include <algorithm>



int main(int argc, char* argv[]) {
    if (argc > 1) {
        filename = argv[1];
        load_file(buffer, argv[1]);
        if (buffer.empty()) return 0;
    } else {
        std::cout << "No file provided to open\nusage: micro [filename]\nwhere [filename] the base file name with extension" << std::endl;
        return 0;
    }

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    timeout(100);  
    getmaxyx(stdscr, h, w);

    topbar = newwin(1, w, 0, 0);
    body = newwin(h - 2, w, 2, 0);
    keypad(body, TRUE);

    wrefresh(stdscr);
    update_topbar(topbar);
    print_to_body(body);

    signal(SIGWINCH, window_handler);

    // Main event loop
    while (true) {
        // Check and handle resize immediately
        if (g_need_resize) {
            g_need_resize = false;
            window_resize();
            continue;
        }

        int ch = getch();

        if (ch == ERR) {
            continue;
        }

        if (ch == KEY_RESIZE) {
            window_resize();
            continue;
        }

        if (!handle_input(body, topbar, ch)) break;
    }

    endwin();
    return 0;
}