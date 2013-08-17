/*
 * main.c for libmenu
 * by lenormf
 */

#include "../utils.h"
#include <vertical.h>
#include <button.h>

#define SIMPLE_MENU_X 10
#define SIMPLE_MENU_Y 5

int main(void) {
	menu_error_e err;
	menu_vertical_t simple_menu;
	menu_button_t quit_button;

	err = menu_vertical_init(&simple_menu, SIMPLE_MENU_X, SIMPLE_MENU_Y);
	if (err != MENU_ERR_NONE)
		fatal("Unable to init menu: %s", menu_error_to_str(err));

	err = menu_button_init(&quit_button, "Quit");
	if (err != MENU_ERR_NONE)
		fatal("Unable to init button: %s", menu_error_to_str(err));

	while (1) {
		// Handle input
		// Display background
		// Display the menu
		simple_menu.render(&simple_menu, 0);
	}

	menu_vertical_free(&simple_menu);

	return 0;
}
