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
} menu_button_t;

menu_error_e menu_button_init(menu_button_t*, menu_label_t const*, u32, u32, void*);
menu_error_e menu_button_free(menu_button_t*);
