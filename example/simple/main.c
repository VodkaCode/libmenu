/*
 * main.c for libmenu
 * by lenormf
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vertical.h>
#include <button.h>
#include "../utils.h"

#define SCREEN_W 800
#define SCREEN_H 600

#define SIMPLE_MENU_X 10
#define SIMPLE_MENU_Y 5

#define FONT_PATH ""
#define FONT_SIZE 12

int main(void) {
	SDL_Window *screen;
	SDL_Renderer *renderer;

	menu_error_e err;

	menu_vertical_t simple_menu;
	menu_font_t simple_menu_font;

	menu_button_t quit_button;
	menu_label_t const quit_label = {
		.name = "Quit",
		.color = 0xEAEAEA,
		.font = &simple_menu_font,
	};

	// Several initialization calls (SDL, SDL_TTF)
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		fatal("Unable to init the SDL: %s", SDL_GetError());

	if (TTF_Init() < 0)
		fatal("Unable to init SDL_TTF: %s", TTF_GetError());

	screen = SDL_CreateWindow("Example #1: simple",
				  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				  SCREEN_W, SCREEN_H,
				  SDL_WINDOW_BORDERLESS);
	if (!screen)
		fatal("Unable to create window: %s", SDL_GetError());

	renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer)
		fatal("Unable to create renderer: %s", SDL_GetError());

	// The fun starts here
	err = menu_vertical_init(&simple_menu, SIMPLE_MENU_X, SIMPLE_MENU_Y);
	if (err != MENU_ERR_NONE)
		fatal("Unable to init menu: %s", menu_error_to_str(err));

	err = menu_font_init(&simple_menu_font, FONT_PATH, FONT_SIZE);
	if (err != MENU_ERR_NONE)
		fatal("Unable to init font: %s", menu_error_to_str(err));

	err = menu_button_init(&quit_button, &quit_label, 20, 10);
	if (err != MENU_ERR_NONE)
		fatal("Unable to init button: %s", menu_error_to_str(err));

	err = menu_add_node((menu_t*)&simple_menu, (menu_node_t*)&quit_button);
	if (err != MENU_ERR_NONE)
		fatal("Unable to add button: %s", menu_error_to_str(err));

	u1 quit = 0;
	while (!quit) {
		// Handle input
		//simple_menu.handle_input(&simple_menu);

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
		simple_menu.render(&simple_menu, renderer);

		SDL_RenderPresent(renderer);
	}

	menu_vertical_free(&simple_menu);

	TTF_Quit();
	SDL_Quit();

	return 0;
}
