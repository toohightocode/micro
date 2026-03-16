#include "globals.h"
#include "input.h"
#include <algorithm>

// INPUT HANDLING
int handle_input(WINDOW* body, WINDOW* topbar, int ch) {
    if (ch == 'q' || ch == 'Q') {
        return 0;
    } else if (ch == KEY_UP) {
        scroll_up(body, topbar);
    } else if (ch == KEY_DOWN) {
        scroll_down(body, topbar);
    } else if (ch == KEY_LEFT) {
        scroll_left(body, topbar);
    } else if (ch == KEY_RIGHT) {
        scroll_right(body, topbar);
    }
    return 1;
}

void scroll_up(WINDOW* body, WINDOW* topbar) {
    if (top_line > 0) {
        top_line--;
    }
    print_to_body(body);
    update_topbar(topbar);
}

void scroll_down(WINDOW* body, WINDOW* topbar) {
    int height = getmaxy(body);
    int max_top_line = std::max(0, (int)buffer.size() - height);
    if (top_line < max_top_line) {
        top_line++;
    }
    print_to_body(body);
    update_topbar(topbar);
}

void scroll_left(WINDOW* body, WINDOW* topbar) {
    if (left_col > 0) {
        left_col--;
    }
    print_to_body(body);
    update_topbar(topbar);
}

void scroll_right(WINDOW* body, WINDOW* topbar) {
    size_t max_len = 0;
    for (const auto& line : buffer) {
        if (line.size() > max_len)
            max_len = line.size();
    }

    if (left_col + w < (int)max_len) {
        left_col++;
    }
    print_to_body(body);
    update_topbar(topbar);
}