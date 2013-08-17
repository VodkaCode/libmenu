/*
 * vertical.c for libmenu
 * by lenormf
 */

#include <vertical.h>

menu_error_e menu_vertical_init(menu_vertical_t *m, u32 x, u32 y) {
	(void)m;
	(void)x;
	(void)y;

	return MENU_ERR_NONE;
}

menu_error_e menu_vertical_free(menu_vertical_t *m) {
	(void)m;

	return MENU_ERR_NONE;
}
