/*
 * vertical.c for libmenu
 * by lenormf
 */

#include <SDL2/SDL_render.h>
#include <vertical.h>

static menu_error_e vertical_renderer(menu_vertical_t *m, void *r) {
	SDL_Renderer *renderer = r;

	(void)m;
	(void)renderer;

	return MENU_ERR_NONE;
}

menu_error_e menu_vertical_init(menu_vertical_t *m, u32 x, u32 y) {
	menu_error_e err;

	if (!m)
		return MENU_ERR_INVALID_PARAMETER;

	err = menu_init(&m->menu, x, y);
	if (err != MENU_ERR_NONE)
		return err;

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
