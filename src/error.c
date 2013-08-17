/*
 * error.c for libmenu
 * by lenormf
 */

#include <stddef.h>
#include <type.h>
#include "error.h"
#include "macro.h"

static struct {
	menu_error_e err;
	char const *str;
} const err_ref[] = {
	{MENU_ERR_NONE, "no error"},
};

char const *menu_error_to_str(menu_error_e err) {
	u32 i;
	for (i = 0; ARRAY_LENGTH(err_ref); i++)
		if (err_ref[i].err == err)
			return err_ref[i].str;

	return NULL;
}
