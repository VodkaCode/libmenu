/*
 * button.c for libmenu
 * by lenormf
 */

#include <button.h>

menu_error_e menu_button_init(menu_button_t *m, char const *lbl) {
	(void)m;
	(void)lbl;

	return MENU_ERR_NONE;
}

menu_error_e menu_button_free(menu_button_t *m) {
	(void)m;

	return MENU_ERR_NONE;
}
