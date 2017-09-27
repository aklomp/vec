#include <stddef.h>
#include <stdio.h>

#include <vec/vec.h>

// Get number of elements in an array:
#define NELEM(array) \
	(sizeof(array) / sizeof(*(array)))

// Loop over an array of given size:
#define FOREACH(array, iter) \
	for (__typeof__(*(array)) *iter = (array); \
		iter < (array) + NELEM(array); \
		iter++)

// Print error message:
#define ERROR(fmt, ...) \
	fprintf(stderr, "Error: %s: " fmt "\n", __FUNCTION__, __VA_ARGS__)

// Add individual test functions:
#include "test_offsets.h"
#include "test_sizes.h"

int
main (void)
{
	int ret = 0;

	ret |= test_offsets();
	ret |= test_sizes();

	return ret;
}
