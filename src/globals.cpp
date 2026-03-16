#include "globals.h"

WINDOW* topbar = nullptr;
WINDOW* body = nullptr;
std::atomic<bool> g_need_resize{false};
std::vector<std::string> buffer;
std::string filename;
int lines_of_buffer = 0;
int top_line = 0;
int left_col = 0;
int h = 0, w = 0;