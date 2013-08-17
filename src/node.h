/*
 * node.h for libmenu
 * by lenormf
 */

#pragma once

#include "type.h"
#include "error.h"

struct menu_s;
typedef struct menu_s menu_t;

typedef struct menu_node_s {
	// Menu to which the node belongs
	menu_t const *parent_menu;

	// Index of the node on the menu
	u32 index;
} menu_node_t;

menu_error_e menu_node_init(menu_node_t*);
menu_error_e menu_node_free(menu_node_t*);
