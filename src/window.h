#pragma once

#include "globals.h"

void window_handler(int sig);
void window_resize();
void print_to_body(WINDOW* body);
void update_topbar(WINDOW* topbar);