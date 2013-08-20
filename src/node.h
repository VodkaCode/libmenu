/*
 * node.h for libmenu
 * by lenormf
 */

#pragma once

#include "type.h"
#include "error.h"

struct menu_s;
typedef struct menu_s menu_t;

struct menu_node_s;
typedef struct menu_node_s menu_node_t;

typedef menu_error_e (*node_renderer_t)(menu_node_t*, u32, u32);

typedef struct menu_node_s {
	// Width of the node
	u32 w;
	// Height of the node
	u32 h;

	// Menu to which the node belongs
	menu_t const *parent_menu;

	// Index of the node on the menu
	u32 index;

	// Private implementation-dependant data
	void *data;

	// Pointer to the function that will render the node on the menu
	node_renderer_t render;
} menu_node_t;

menu_error_e menu_node_init(menu_node_t*, u32, u32, void*, node_renderer_t);
menu_error_e menu_node_free(menu_node_t*);
