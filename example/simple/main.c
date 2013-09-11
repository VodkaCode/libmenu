/*
 * main.c for libmenu
 * by lenormf
 */

#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vertical.h>
#include <button.h>
#include "../utils.h"

#define SCREEN_W 800
#define SCREEN_H 600

#define vmenu_X 10
#define vmenu_Y 5

#define FONT_PATH "../data/GeosansLight.ttf"
#define FONT_SIZE 20

// Abstraction of a vertical menu
// For more transparency, it's possible to forward calls from
// my_menu.{render,handle_input} to my_menu.vmenu.{render,handle_input}
// with a macro or function pointers
typedef struct my_menu_s {
	menu_vertical_t vmenu;
	menu_font_t vmenu_font;

	menu_button_t play_button;
	menu_label_t play_label;

	menu_button_t quit_button;
	menu_label_t quit_label;
} my_menu_t;

void my_menu_init(my_menu_t *m, SDL_Renderer *renderer) {
	menu_error_e err;

	// Initialize labels
	strncpy(m->quit_label.name, "Quit", sizeof(m->quit_label.name));
	// Color code format: 0xRRGGBB
	m->quit_label.color = 0xEAEAEA;
	m->quit_label.font = &m->vmenu_font;

	strncpy(m->play_label.name, "Play", sizeof(m->play_label.name));
	m->play_label.color = 0xEAEAEA;
	m->play_label.font = &m->vmenu_font;

	// Load the font that will be used in our menus
	err = menu_font_init(&m->vmenu_font, FONT_PATH, FONT_SIZE);
	if (err != MENU_ERR_NONE)
		fatal("Unable to init font: %s", menu_error_to_str(err));

	// Create a new menu with a vertical layout
	err = menu_vertical_init(&m->vmenu, vmenu_X, vmenu_Y, renderer);
	if (err != MENU_ERR_NONE)
		fatal("Unable to init menu: %s", menu_error_to_str(err));

	// Space between the nodes of the menu
	// By default, the vertical menu will place the nodes between one another
	menu_vertical_set(MENU_VERTICAL_VAR_VSPACING, FONT_SIZE);

	// Create a button 20x10 pixels wide
	// The label contains the text that will be rendered,
	// a color code, and a pointer to the font used
	err = menu_button_init(&m->quit_button, &m->quit_label, 20, 10, renderer);
	if (err != MENU_ERR_NONE)
		fatal("Unable to init button: %s", menu_error_to_str(err));

	err = menu_button_init(&m->play_button, &m->play_label, 20, 10, renderer);
	if (err != MENU_ERR_NONE)
		fatal("Unable to init button: %s", menu_error_to_str(err));

	// Assign the buttons previously initialized to the main menu
	// The nodes will be rendered in the order they were assigned to the menu
	err = menu_add_node((menu_t*)&m->vmenu, (menu_node_t*)&m->play_button);
	if (err != MENU_ERR_NONE)
		fatal("Unable to add button: %s", menu_error_to_str(err));

	err = menu_add_node((menu_t*)&m->vmenu, (menu_node_t*)&m->quit_button);
	if (err != MENU_ERR_NONE)
		fatal("Unable to add button: %s", menu_error_to_str(err));
}

void my_menu_free(my_menu_t *m) {
	menu_vertical_free(&m->vmenu);
}

int main(void) {
	SDL_Window *screen;
	SDL_Renderer *renderer;

	my_menu_t my_menu;

	// Several initialization calls (SDL, SDL_TTF)
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		fatal("Unable to init the SDL: %s", SDL_GetError());

	if (TTF_Init() < 0)
		fatal("Unable to init SDL_TTF: %s", TTF_GetError());

	if (SDL_CreateWindowAndRenderer(SCREEN_W, SCREEN_H,
					SDL_WINDOW_BORDERLESS,
					&screen, &renderer) < 0)
		fatal("Unable to create window/renderer: %s", SDL_GetError());

	// The fun starts here
	my_menu_init(&my_menu, renderer);

	u1 quit = 0;
	while (!quit) {
		// Handle input
		//my_menu.vmenu.handle_input(&my_menu.vmenu);

		SDL_Event ev;
		while (SDL_PollEvent(&ev)) {
			switch (ev.type) {
				case SDL_QUIT:
					quit = 1;
					break;
				default: break;
			}
		}

		SDL_RenderClear(renderer);

		// Display background
		// Display the menu
		my_menu.vmenu.render(&my_menu.vmenu);

		SDL_RenderPresent(renderer);
	}

	my_menu_free(&my_menu);

	TTF_Quit();
	SDL_Quit();

	return 0;
}
