/*
 * main.c for libmenu
 * by lenormf
 */

#include <menu.h>

int main(void) {
	menu_error_e err;
	menu_t simple_menu;

	err = menu_init(&simple_menu);
	if (err != MENU_ERR_NONE)
		return 1;

	menu_free(&simple_menu);

	return 0;
}
