#pragma once

#include <ncurses.h>
#include <atomic>
#include <vector>
#include <string>

// variable declarations
extern WINDOW* topbar;
extern WINDOW* body;
extern WINDOW* linenumbers;
extern std::atomic<bool> g_need_resize;
extern std::vector<std::string> buffer;
extern std::string filename;
extern int lines_of_buffer;
extern int top_line;
extern int left_col;
extern int h, w;
extern int linenumbers_width;