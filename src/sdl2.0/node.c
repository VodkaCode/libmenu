/*
 * node.c for libmenu
 * by lenormf
 */

#include <node.h>

menu_error_e menu_node_init(menu_node_t *n, u32 w, u32 h) {
	if (!n
	    || !w
	    || !h)
		return MENU_ERR_INVALID_PARAMETER;

	n->w = w;
	n->h = h;

	return MENU_ERR_NONE;
}

menu_error_e menu_node_free(menu_node_t *n) {
	if (!n)
		return MENU_ERR_INVALID_PARAMETER;

	return MENU_ERR_NONE;
}
