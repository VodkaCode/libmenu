/*
 * error.h for libmenu
 * by lenormf
 */

#pragma once

typedef enum {
	MENU_ERR_NONE,

	MENU_ERR_INVALID_PARAMETER = 100,

	MENU_ERR_ALLOCATION_FAILURE = 200,

	MENU_ERR_INTERNAL_FAILURE = 300
} menu_error_e;

char const *menu_error_to_str(menu_error_e);
