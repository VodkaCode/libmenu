/*
 * menu.h for libmenu
 * by lenormf
 */

#pragma once

#include "type.h"
#include "error.h"
#include "font.h"

struct menu_node_s;
typedef struct menu_node_s menu_node_t;

typedef struct menu_s {
	// X coordinate of the menu on the renderer
	u32 x;
	// Y coordinate of the menu on the renderer
	u32 y;

	// Number of nodes in the menu (input, buttons, etc)
	u32 nb_nodes;
	// "Pool" of nodes
	menu_node_t *nodes;
	// Number of nodes pre-allocated in the pool
	u64 sz_nodes;

	// Private implementation-dependant data
	void *data;
} menu_t;

menu_error_e menu_init(menu_t*, u32, u32, void*);
menu_error_e menu_free(menu_t*);

menu_error_e menu_add_node(menu_t*, menu_node_t const*);
