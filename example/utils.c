/*
 * utils.c for libmenu
 * by lenormf
 */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void fatal(char const *fmt, ...) {
	va_list ap;
	char buffer[256];

	va_start(ap, fmt);
	vsnprintf(buffer, sizeof(buffer), fmt, ap);
	va_end(ap);

	fprintf(stderr, "%s\n", buffer);

	exit(1);
}
