#include <stddef.h>
#include <stdio.h>
#include <inttypes.h>

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

// Print error message about expected float values:
#define ERROR_EXPECT_F(xe, ye, ze, we, v) \
	ERROR("expected (%0.2f, %0.2f, %0.2f, %0.2f)," \
	          " got (%0.2f, %0.2f, %0.2f, %0.2f)", \
		xe, ye, ze, we, v.x, v.y, v.z, v.w)

// Print error message about expected signed integer values:
#define ERROR_EXPECT_I(xe, ye, ze, we, v) \
	ERROR("expected (%" PRIi32 ", %" PRIi32 ", %" PRIi32 ", %" PRIi32 ")," \
	          " got (%" PRIi32 ", %" PRIi32 ", %" PRIi32 ", %" PRIi32 ")", \
		xe, ye, ze, we, v.xi, v.yi, v.zi, v.wi)

// Print error message about expected unsigned integer values:
#define ERROR_EXPECT_U(xe, ye, ze, we, v) \
	ERROR("expected (%" PRIu32 ", %" PRIu32 ", %" PRIu32 ", %" PRIu32 ")," \
	          " got (%" PRIu32 ", %" PRIu32 ", %" PRIu32 ", %" PRIu32 ")", \
		xe, ye, ze, we, v.xu, v.yu, v.zu, v.wu)

// Open an 'if' statement block if float values do not match the vector:
#define IF_NOT_EQUALS_F(xe, ye, ze, we, v) \
	if (v.x != (xe) || v.y != (ye) || v.z != (ze) || v.w != (we)) \
		if (ERROR_EXPECT_F((xe), (ye), (ze), (we), v))

// Open an 'if' statement block if signed integer values do not match the vector:
#define IF_NOT_EQUALS_I(xe, ye, ze, we, v) \
	if (v.xi != (xe) || v.yi != (ye) || v.zi != (ze) || v.wi != (we)) \
		if (ERROR_EXPECT_I((xe), (ye), (ze), (we), v))

// Open an 'if' statement block if unsigned integer values do not match the vector:
#define IF_NOT_EQUALS_U(xe, ye, ze, we, v) \
	if (v.xu != (xe) || v.yu != (ye) || v.zu != (ze) || v.wu != (we)) \
		if (ERROR_EXPECT_U((xe), (ye), (ze), (we), v))

// Add individual test functions:
#include "test_instantiate.h"
#include "test_offsets.h"
#include "test_sizes.h"

int
main (void)
{
	int ret = 0;

	ret |= test_offsets();
	ret |= test_sizes();
	ret |= test_instantiate();

	return ret;
}
