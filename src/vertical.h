/*
 * vertical.h for libmenu
 * by lenormf
 */

#pragma once

#include "menu.h"

#define MENU_VERTICAL_VSPACING 20

typedef enum {
	MENU_VERTICAL_VAR_VSPACING,
} menu_vertical_var_e;

typedef struct menu_vertical_s {
	menu_t menu;

	int vertical_spacing;

	menu_error_e (*render)(struct menu_vertical_s*);
	menu_error_e (*handle_input)(struct menu_vertical_s*);
} menu_vertical_t;

menu_error_e menu_vertical_init(menu_vertical_t*, u32, u32, void*);
menu_error_e menu_vertical_free(menu_vertical_t*);

menu_error_e menu_vertical_set(menu_vertical_t*, menu_vertical_var_e, ...);
