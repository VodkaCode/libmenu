/*
 * menu.c for libmenu
 * by lenormf
 */

#include <string.h>
#include <stdlib.h>
#include <SDL2/SDL_ttf.h>
#include <menu.h>
#include <node.h>

#define MENU_NODES_POOL_SIZE 10

static menu_node_t *get_free_node(menu_t const *m) {
	u32 i;
	for (i = 0; i < m->sz_nodes; i++)
		if (!m->nodes[i].parent_menu)
			return &m->nodes[i];

	return NULL;
}

static menu_error_e grow_nodes_pool(menu_t *m, u32 sz) {
	m->sz_nodes += sz;
	m->nodes = realloc(m->nodes, m->sz_nodes * sizeof(menu_node_t));
	if (!m->nodes)
		return MENU_ERR_ALLOCATION_FAILURE;

	return MENU_ERR_NONE;
}

menu_error_e menu_init(menu_t *m, u32 x, u32 y, void *d) {
	if (!m
	    || !x
	    || !y)
		return MENU_ERR_INVALID_PARAMETER;

	m->x = x;
	m->y = y;
	m->nb_nodes = 0;
	m->nodes = calloc(MENU_NODES_POOL_SIZE, sizeof(menu_node_t));
	if (!m->nodes)
		return MENU_ERR_ALLOCATION_FAILURE;
	m->sz_nodes = MENU_NODES_POOL_SIZE;
	m->data = d;

	return MENU_ERR_NONE;
}

menu_error_e menu_free(menu_t *m) {
	if (!m)
		return MENU_ERR_INVALID_PARAMETER;

	free(m->nodes);

	return MENU_ERR_NONE;
}

menu_error_e menu_add_node(menu_t *m, menu_node_t const *n) {
	menu_error_e err;
	menu_node_t *holder_node;

	if (!m
	    || !n)
		return MENU_ERR_INVALID_PARAMETER;

	holder_node = get_free_node(m);
	if (!holder_node) {
		// Grow the size of the pool if you can't add a new node in it
		if (m->sz_nodes < m->nb_nodes + 1) {
			err = grow_nodes_pool(m, MENU_NODES_POOL_SIZE);
			if (err != MENU_ERR_NONE)
				return err;
		}
		holder_node = &m->nodes[m->nb_nodes];
	}

	// Copy the given node to the internal pool slot
	holder_node->w = n->w;
	holder_node->h = n->h;

	// Assign the node to the menu
	holder_node->parent_menu = m;
	holder_node->index = m->nb_nodes;

	m->nb_nodes++;

	return MENU_ERR_NONE;
}
