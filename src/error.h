/*
 * error.h for libmenu
 * by lenormf
 */

#pragma once

typedef enum {
	MENU_ERR_NONE,
} menu_error_e;

char const *menu_error_to_str(menu_error_e);
