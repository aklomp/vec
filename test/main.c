#include <stddef.h>
#include <stdio.h>
#include <inttypes.h>
#include <math.h>

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

// Approximate float comparison:
#define APPROX(a, b) \
	(fabsf((a) - (b)) <= fabsf((a) * 0.01f))

// Open an 'if' statement block if float values are not approximately equal
#define IF_NOT_APPROX(xe, ye, ze, we, v) \
	if (!APPROX(v.x, (xe)) || !APPROX(v.y, (ye)) || !APPROX(v.z, (ze)) || !APPROX(v.w, (we))) \
		if (ERROR_EXPECT_F((xe), (ye), (ze), (we), v))

// Random floating-point test vectors:
static const float fval[] = {
	-42.3f,    -0.4f,  0.1f, 5678.9f,
	-3.33f, -2003.0f, 0.99f,  -23.5f,
};

// Signed integer test vectors:
static const int32_t ival[] = {
	INT32_C(-1000000),   INT32_C(-3), INT32_C(0x00000000), INT32_C(0xFFFFFFFF),
	INT32_C(     -42),   INT32_C(27), INT32_C(0xABCDEF03), INT32_C(0x00000FFF),
	INT32_C(0XFFFFFFFF), INT32_C( 0), INT32_C(0xFFFFFFFE), INT32_C(         1),
};

// Unsigned integer test vectors:
static const uint32_t uval[] = {
	UINT32_C(0x00000000), UINT32_C(0xDEADBEEF), UINT32_C(42), UINT32_C(0x12340000),
	UINT32_C(0XFFFFFFFF), UINT32_C(0xFEDCBA98), UINT32_C(17), UINT32_C(0x00012345),
	UINT32_C(0XFFFFFFFF), UINT32_C(0xFFFFFFFE), UINT32_C( 0), UINT32_C(         1),
};

// Return a floating-point vector with values from fval:
static inline union vec
vtestf (const size_t start)
{
	return vec(
		fval[(start + 0U) % NELEM(fval)],
		fval[(start + 1U) % NELEM(fval)],
		fval[(start + 2U) % NELEM(fval)],
		fval[(start + 3U) % NELEM(fval)]
	);
}

// Return a signed integer vector with values from ival:
static inline union vec
vtesti (const size_t start)
{
	return vec_i(
		ival[(start + 0U) % NELEM(ival)],
		ival[(start + 1U) % NELEM(ival)],
		ival[(start + 2U) % NELEM(ival)],
		ival[(start + 3U) % NELEM(ival)]
	);
}

// Return an unsigned integer vector with values from uval:
static inline union vec
vtestu (const size_t start)
{
	return vec_u(
		uval[(start + 0U) % NELEM(uval)],
		uval[(start + 1U) % NELEM(uval)],
		uval[(start + 2U) % NELEM(uval)],
		uval[(start + 3U) % NELEM(uval)]
	);
}

// Add individual test functions:
#include "test_3d.h"
#include "test_arith.h"
#include "test_compare.h"
#include "test_convert.h"
#include "test_instantiate.h"
#include "test_logic.h"
#include "test_offsets.h"
#include "test_sizes.h"

int
main (void)
{
	int ret = 0;

	ret |= test_offsets();
	ret |= test_sizes();
	ret |= test_instantiate();
	ret |= test_convert();
	ret |= test_arith();
	ret |= test_logic();
	ret |= test_compare();
	ret |= test_3d();

	return ret;
}
