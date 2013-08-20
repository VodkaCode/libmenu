/*
 * error.c for libmenu
 * by lenormf
 */

#include <stdio.h>
#include <SDL2/SDL_error.h>
#include <type.h>
#include <error.h>
#include <macro.h>

#define MENU_ERROR_STRING_LENGTH 256

static struct {
	menu_error_e err;
	char const *str;
} const err_ref[] = {
	{MENU_ERR_NONE, "no error"},
	{MENU_ERR_INVALID_PARAMETER, "invalid parameter"},
	{MENU_ERR_ALLOCATION_FAILURE, "allocation failure"},
	{MENU_ERR_INTERNAL_FAILURE, "internal failure"},
};

char const *menu_error_to_str(menu_error_e err) {
	static char err_str[MENU_ERROR_STRING_LENGTH];

	u32 i;
	for (i = 0; ARRAY_LENGTH(err_ref); i++)
		if (err_ref[i].err == err) {
			if (err == MENU_ERR_INTERNAL_FAILURE) {
				snprintf(err_str, ARRAY_LENGTH(err_str), "%s: %s", err_ref[i].str, SDL_GetError());
				SDL_ClearError();
			} else {
				snprintf(err_str, ARRAY_LENGTH(err_str), "%s", err_ref[i].str);
			}

			return err_str;
		}

	return NULL;
}
