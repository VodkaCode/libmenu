/*
 * button.c for libmenu
 * by lenormf
 */

#include <string.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <button.h>

static menu_error_e button_renderer(menu_button_t *b, void *r) {
	SDL_Renderer *renderer = r;

	(void)b;
	(void)renderer;

	return MENU_ERR_NONE;
}

static menu_error_e button_create_label_surface(menu_button_t *b) {
	SDL_Surface *s;
	SDL_Color col = {
		.r = b->label.color & 0xFF0000,
		.g = b->label.color & 0x00FF00,
		.b = b->label.color & 0x0000FF,
	};

	s = TTF_RenderText_Blended(b->label.font->data,
				   b->label.name,
				   col);
	if (!s)
		return MENU_ERR_INTERNAL_FAILURE;

	b->data = s;

	return MENU_ERR_NONE;
}

menu_error_e menu_button_init(menu_button_t *b, menu_label_t const *lbl, u32 w, u32 h) {
	menu_error_e err;

	if (!b
	    || !lbl)
		return MENU_ERR_INVALID_PARAMETER;

	err = menu_node_init(&b->node, w, h);
	if (err != MENU_ERR_NONE)
		return err;

	memcpy(&b->label, lbl, sizeof(menu_label_t));

	err = button_create_label_surface(b);
	if (err != MENU_ERR_NONE)
		return err;

	b->render = &button_renderer;

	return MENU_ERR_NONE;
}

menu_error_e menu_button_free(menu_button_t *b) {
	if (!b)
		return MENU_ERR_INVALID_PARAMETER;

	menu_node_free(&b->node);

	return MENU_ERR_NONE;
}
