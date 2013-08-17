/*
 * menu.h for libmenu
 * by lenormf
 */

#pragma once

#include "error.h"

typedef struct menu_s {
} menu_t;

menu_error_e menu_init(menu_t*);
menu_error_e menu_free(menu_t*);
