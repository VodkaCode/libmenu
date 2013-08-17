/*
 * button.h for libmenu
 * by lenormf
 */

#pragma once

#include "node.h"

typedef struct menu_button_s {
	menu_node_t node;

	// Label that will be rendered on the menu (the button's name)
	char label[32];

	// Pointer to the function that will render the node on the menu
	menu_error_e (*render)(struct menu_button_s*, void*);
} menu_button_t;

menu_error_e menu_button_init(menu_button_t*, char const*);
menu_error_e menu_button_free(menu_button_t*);
