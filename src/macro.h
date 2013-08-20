/*
 * macro.h for libmenu
 * by lenormf
 */

#pragma once

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof(*(x)))

#define ASSERT(exp, fmt, vargs...) if (!(exp)) { \
	exit(-1); \
	fprintf(stderr, fmt " (%s : l%d)\n", __FILE__, __LINE__, ##vargs); \
}
