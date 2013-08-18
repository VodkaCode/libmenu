/*
 * font.c for libmenu
 * by lenormf
 */

#include <string.h>
#include <SDL2/SDL_ttf.h>
#include <font.h>

menu_error_e menu_font_init(menu_font_t *font, char const *path, u32 size) {
	TTF_Font *f;

	if (!font
	    || !path
	    || !size)
		return MENU_ERR_INVALID_PARAMETER;

	f = TTF_OpenFont(path, size);
	if (!f)
		return MENU_ERR_INTERNAL_FAILURE;
	font->data = f;

	return MENU_ERR_NONE;
}

menu_error_e menu_font_free(menu_font_t *font) {
	if (!font)
		return MENU_ERR_INVALID_PARAMETER;

	TTF_CloseFont(font->data);

	return MENU_ERR_NONE;
}
