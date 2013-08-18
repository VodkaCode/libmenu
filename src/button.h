/*
 * button.h for libmenu
 * by lenormf
 */

#pragma once

#include "node.h"
#include "label.h"

typedef struct menu_button_s {
	menu_node_t node;

	// Label that will be rendered on the menu (the button's name)
	menu_label_t label;

	// Pointer to the function that will render the node on the menu
	menu_error_e (*render)(struct menu_button_s*, void*);

	// Private implementation-dependant data
	void *data;
} menu_button_t;

menu_error_e menu_button_init(menu_button_t*, menu_label_t const*, u32, u32);
menu_error_e menu_button_free(menu_button_t*);
