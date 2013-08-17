/*
 * menu.c for libmenu
 * by lenormf
 */

#include <menu.h>

menu_error_e menu_init(menu_t *m, u32 x, u32 y) {
	(void)m;
	(void)x;
	(void)y;

	return MENU_ERR_NONE;
}

menu_error_e menu_free(menu_t *m) {
	(void)m;

	return MENU_ERR_NONE;
}
