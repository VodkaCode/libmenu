/*
 * vertical.c for libmenu
 * by lenormf
 */

#include <stdarg.h>
#include <stddef.h>
#include <SDL2/SDL_render.h>
#include <vertical.h>
#include <node.h>
#include "macro.h"

static menu_error_e vertical_renderer(menu_vertical_t *m) {
	u32 i;

	ASSERT(m->menu.data != NULL, "No renderer given");

	for (i = 0; i < m->menu.sz_nodes; i++) {
		if (!m->menu.nodes[i].parent_menu)
			continue;

		m->menu.nodes[i].render(&m->menu.nodes[i], m->menu.x, m->menu.y + (m->menu.nodes[i].h + m->vertical_spacing) * i);
	}

	return MENU_ERR_NONE;
}

menu_error_e menu_vertical_init(menu_vertical_t *m, u32 x, u32 y, void *d) {
	menu_error_e err;

	if (!m)
		return MENU_ERR_INVALID_PARAMETER;

	err = menu_init(&m->menu, x, y, d);
	if (err != MENU_ERR_NONE)
		return err;

	m->vertical_spacing = MENU_VERTICAL_VSPACING;
	m->render = &vertical_renderer;

	return MENU_ERR_NONE;
}

menu_error_e menu_vertical_free(menu_vertical_t *m) {
	menu_error_e err;

	if (!m)
		return MENU_ERR_INVALID_PARAMETER;

	err = menu_free(&m->menu);
	if (err != MENU_ERR_NONE)
		return err;

	return MENU_ERR_NONE;
}

menu_error_e menu_vertical_set(menu_vertical_t *m, menu_vertical_var_e v, ...) {
	va_list ap;

	if (!m)
		return MENU_ERR_INVALID_PARAMETER;

	va_start(ap, v);
	switch (v) {
		case MENU_VERTICAL_VAR_VSPACING: m->vertical_spacing = va_arg(ap, int); break;
		default:
			va_end(ap);
			return MENU_ERR_INVALID_PARAMETER;
	}
	va_end(ap);

	return MENU_ERR_NONE;
}
