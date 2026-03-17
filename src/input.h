#pragma once

#include "window.h"


int handle_input(WINDOW* body, WINDOW* topbar, int ch);
void scroll_up(WINDOW* body, WINDOW* topbar);
void scroll_down(WINDOW* body, WINDOW* topbar);
void scroll_left(WINDOW* body, WINDOW* topbar);
void scroll_right(WINDOW* body, WINDOW* topbar);