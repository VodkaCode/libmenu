/*
 * label.h for libmenu
 * by lenormf
 */

#pragma once

#include "type.h"
#include "font.h"

typedef struct menu_label_s {
	char name[64];

	u32 color;
	menu_font_t const *font;
} menu_label_t;
