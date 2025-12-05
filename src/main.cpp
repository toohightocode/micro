#include "globals.hpp"
#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <vector>
#include <string>

// functions declarations
int handle_input(WINDOW* body,WINDOW* topbar, int ch);
void print_to_body(WINDOW* body);
void update_topbar(WINDOW* topbar);
void scroll_up(WINDOW* body, WINDOW* topbar);
void scroll_down(WINDOW* body, WINDOW* topbar);
void scroll_left(WINDOW* body);
void scroll_right(WINDOW* body);
void load_file(std::vector<std::string>& buffer, const std::string& filename);

// declaring external variables
extern std::string filename;
extern std::vector<std::string> buffer;
extern int lines_of_buffer;
int top_line = 0; // line of buffer displayed at the top
int left_col = 0;  // first visible column (for horizontal scroll)
int h, w;

int main(int argc, char* argv[]) {
    // check for cmdline arguments
    if (argc > 1) {
        filename = argv[1];
        load_file(buffer, argv[1]);
    } else {
        std::cout << "No file provided to open\nusage: micro [filename]\nwhere [filename] the base file name with extension" << std::endl;
        return 0;
    }

    // initialize ncurses window
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    getmaxyx(stdscr, h, w);


    // topbar window
    WINDOW* topbar = newwin(1, w, 0, 0);
    update_topbar(topbar);
    wrefresh(topbar);
    
    // body window
    WINDOW* body = newwin(h-1, w, 2, 0);
    keypad(body, TRUE);
    refresh();
    wrefresh(topbar);
    
    while (true) {
        print_to_body(body);
        int ch = getch();
        if (!handle_input(body, topbar, ch)) break;
        wrefresh(body);
        wrefresh(topbar);
    }
    
    endwin();
    return 0;
}





// INPUT HANDLING
int handle_input(WINDOW* body,WINDOW* topbar, int ch) {
    if (ch == 'q' || ch == 'Q') {
        return 0;
    } else if (ch == KEY_UP) {
        scroll_up(body, topbar);
    } else if (ch == KEY_DOWN) {
        scroll_down(body, topbar);
    } else if (ch == KEY_LEFT) {
        scroll_left(body);
    } else if (ch == KEY_RIGHT) {
        scroll_right(body);
    }
    // Refresh the window after printing
    wrefresh(body);
    return 1;
}

void scroll_up(WINDOW* body,WINDOW* topbar) {
    if (top_line > 0) {
        top_line--;
    }
    print_to_body(body);
    update_topbar(topbar);
}

void scroll_down(WINDOW* body, WINDOW* topbar) {
    int height = getmaxy(body);
    int max_top_line = std::max(0, (int)buffer.size() - height+2);
    if (top_line < max_top_line) {
        top_line++;
    }
    print_to_body(body);
    update_topbar(topbar);
}


void scroll_left(WINDOW* body) {
    if (left_col > 0) {
        left_col--;
    }
}

void scroll_right(WINDOW* body) {
    // find the longest line in the buffer (or optimize later)
    size_t max_len = 0;
    for (const auto& line : buffer)
        if (line.size() > max_len)
            max_len = line.size();

    int width = w; // global window width (already set by getmaxyx)

    if (left_col + width < (int)max_len) {
        left_col++;
    }
}






// FILE STREAM
void load_file(std::vector<std::string>& buffer, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return;
    }

    buffer.clear();  // clear any previous contents
    std::string line;
    while (std::getline(file, line)) {
        buffer.push_back(line);
    }
    lines_of_buffer = buffer.size();

    file.close(); // optional, happens automatically on destruction
}





void print_to_body(WINDOW* body) {
    werase(body); // clear previous content

    int height, width;
    getmaxyx(body, height, width);

    for (int i = 0; i < height && (top_line + i) < (int)buffer.size(); i++) {
        const std::string& line = buffer[top_line + i];

        // get the visible portion of the line starting from left_col
        std::string visible;
        if ((int)line.size() > left_col)
            visible = line.substr(left_col, width);
        else
            visible = ""; // if scrolled past end of line

        mvwprintw(body, i, 0, "%s", visible.c_str());
    }

    wrefresh(body);
}


void update_topbar(WINDOW* topbar) {
    werase(topbar);

    // version
    std::string version = "micro v1.0";
    mvwprintw(topbar, 0, w - version.length(), "%s", version.c_str());

    // line number
    mvwprintw(topbar, 0, 0, "line %d / %d", top_line + h-2, buffer.size()+1);

    // filename in the center
    int x = std::max(0, w/2 - (int)filename.size()/2);
    mvwprintw(topbar, 0, x, "%s", filename.c_str());

    wrefresh(topbar);
}
