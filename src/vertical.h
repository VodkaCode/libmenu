/*
 * vertical.h for libmenu
 * by lenormf
 */

#pragma once

#include "menu.h"

typedef struct menu_vertical_s {
	menu_t menu;

	// Pointer to the function that will render the menu onto a surface
	menu_error_e (*render)(struct menu_vertical_s*, void*);
} menu_vertical_t;

menu_error_e menu_vertical_init(menu_vertical_t*, u32, u32);
menu_error_e menu_vertical_free(menu_vertical_t*);
