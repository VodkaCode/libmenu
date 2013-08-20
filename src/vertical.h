/*
 * vertical.h for libmenu
 * by lenormf
 */

#pragma once

#include "menu.h"

typedef struct menu_vertical_s {
	menu_t menu;

	menu_error_e (*render)(struct menu_vertical_s*);
} menu_vertical_t;

menu_error_e menu_vertical_init(menu_vertical_t*, u32, u32, void*);
menu_error_e menu_vertical_free(menu_vertical_t*);
