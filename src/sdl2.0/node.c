/*
 * node.c for libmenu
 * by lenormf
 */

#include <node.h>
#include <menu.h>

menu_error_e menu_node_init(menu_node_t *n, u32 x, u32 y, u32 w, u32 h, void *d, node_renderer_t nr) {
	if (!n
	    || !w
	    || !h
	    || !nr)
		return MENU_ERR_INVALID_PARAMETER;

	n->x = x;
	n->y = y;
	n->w = w;
	n->h = h;
	n->data = d;
	n->render = nr;

	return MENU_ERR_NONE;
}

menu_error_e menu_node_free(menu_node_t *n) {
	if (!n)
		return MENU_ERR_INVALID_PARAMETER;

	return MENU_ERR_NONE;
}
