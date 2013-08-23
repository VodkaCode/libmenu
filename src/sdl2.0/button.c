/*
 * button.c for libmenu
 * by lenormf
 */

#include <string.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <button.h>
#include <menu.h>
#include "macro.h"

static menu_error_e button_renderer(menu_node_t *n, u32 x, u32 y) {
	menu_button_t *b;
	SDL_Renderer *renderer;
	SDL_Texture *texture;
	SDL_Rect dst;

	// TODO: display a background

	if (!n
	    || !x
	    || !y)
		return MENU_ERR_INVALID_PARAMETER;

	b = (menu_button_t*)n;

	ASSERT(b->node.data != NULL, "No texture to display");
	ASSERT(b->node.parent_menu, "The node doesn't belong to any menu");
	ASSERT(b->node.parent_menu->data, "No renderer set in the parent menu");

	renderer = b->node.parent_menu->data;
	texture = b->node.data;

	dst.x = (int)x;
	dst.y = (int)y;

	if (SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h) < 0)
		return MENU_ERR_INTERNAL_FAILURE;

	if (SDL_RenderCopy(renderer, texture, NULL, &dst) < 0)
		return MENU_ERR_INTERNAL_FAILURE;

	return MENU_ERR_NONE;
}

static menu_error_e button_create_label_surface(menu_button_t *b) {
	SDL_Surface *s;
	SDL_Texture *t;
	SDL_Renderer *r;
	// FIXME: incorrect masks, use SDL_GetRGB
	SDL_Color const col = {
		.r = b->label.color & 0xFF0000,
		.g = b->label.color & 0x00FF00,
		.b = b->label.color & 0x0000FF,
	};

	ASSERT(b->node.data != NULL, "No renderer given");

	r = b->node.data;

	s = TTF_RenderText_Blended(b->label.font->data, b->label.name, col);
	if (!s)
		return MENU_ERR_INTERNAL_FAILURE;

	t = SDL_CreateTextureFromSurface(r, s);

	SDL_FreeSurface(s);

	b->node.data = t;

	return MENU_ERR_NONE;
}

menu_error_e menu_button_init(menu_button_t *b, menu_label_t const *lbl, u32 w, u32 h, void *d) {
	menu_error_e err;

	if (!b
	    || !lbl)
		return MENU_ERR_INVALID_PARAMETER;

	err = menu_node_init(&b->node, w, h, d, (node_renderer_t)&button_renderer);
	if (err != MENU_ERR_NONE)
		return err;

	memcpy(&b->label, lbl, sizeof(menu_label_t));

	err = button_create_label_surface(b);
	if (err != MENU_ERR_NONE)
		return err;

	return MENU_ERR_NONE;
}

menu_error_e menu_button_free(menu_button_t *b) {
	if (!b)
		return MENU_ERR_INVALID_PARAMETER;

	menu_node_free(&b->node);

	if (b->node.data)
		SDL_DestroyTexture(b->node.data);

	return MENU_ERR_NONE;
}
