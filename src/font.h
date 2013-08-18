/*
 * font.h for libmenu
 * by lenormf
 */

#pragma once

#include "type.h"
#include "error.h"

typedef struct menu_font_s {
	// Path to the font in the filesystem
	char path[128];
	// Size of the characters that will be rendered by the font
	u32 size;

	// Private implementation-dependant data
	void *data;
} menu_font_t;

menu_error_e menu_font_init(menu_font_t*, char const*, u32);
menu_error_e menu_font_free(menu_font_t*);
