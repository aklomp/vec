#define ERROR_CMP_I(a, op, b, v) \
	fprintf(stderr, \
		"  0x%08X %s 0x%08X -> %s\n" \
		"  0x%08X %s 0x%08X -> %s\n" \
		"  0x%08X %s 0x%08X -> %s\n" \
		"  0x%08X %s 0x%08X -> %s\n", \
		a.xi, #op, b.xi, (v.xi) ? "true" : "false", \
		a.yi, #op, b.yi, (v.yi) ? "true" : "false", \
		a.zi, #op, b.zi, (v.zi) ? "true" : "false", \
		a.wi, #op, b.wi, (v.wi) ? "true" : "false")

#define ERROR_CMP_U(a, op, b, v) \
	fprintf(stderr, \
		"  0x%08X %s 0x%08X -> %s\n" \
		"  0x%08X %s 0x%08X -> %s\n" \
		"  0x%08X %s 0x%08X -> %s\n" \
		"  0x%08X %s 0x%08X -> %s\n", \
		a.xu, #op, b.xu, (v.xi) ? "true" : "false", \
		a.yu, #op, b.yu, (v.yi) ? "true" : "false", \
		a.zu, #op, b.zu, (v.zi) ? "true" : "false", \
		a.wu, #op, b.wu, (v.wi) ? "true" : "false")

#define CMP(a, b, elem, op) \
	(((a.elem) op (b.elem)) ? INT32_C(0xFFFFFFFF) : INT32_C(0))

#define IF_NOT_CMP_F(a, op, b, v) \
	IF_NOT_EQUALS_I (CMP(a, b, x, op), \
	                 CMP(a, b, y, op), \
	                 CMP(a, b, z, op), \
	                 CMP(a, b, w, op), v) \

#define IF_NOT_CMP_I(a, op, b, v) \
	IF_NOT_EQUALS_I (CMP(a, b, xi, op), \
	                 CMP(a, b, yi, op), \
	                 CMP(a, b, zi, op), \
	                 CMP(a, b, wi, op), v) \
	if (ERROR_CMP_I(a, op, b, v))

#define IF_NOT_CMP_U(a, op, b, v) \
	IF_NOT_EQUALS_I (CMP(a, b, xu, op), \
	                 CMP(a, b, yu, op), \
	                 CMP(a, b, zu, op), \
	                 CMP(a, b, wu, op), v) \
	if (ERROR_CMP_U(a, op, b, v))

static int
test_compare_eq (const union vec a, const union vec b)
{
	union vec v = vec_eq(a, b);

	IF_NOT_CMP_F (a, ==, b, v)
		return 1;

	return 0;
}

static int
test_compare_ieq (const union vec a, const union vec b)
{
	union vec v = vec_ieq(a, b);

	IF_NOT_CMP_I (a, ==, b, v)
		return 1;

	return 0;
}

static int
test_compare_ueq (const union vec a, const union vec b)
{
	union vec v = vec_ueq(a, b);

	IF_NOT_CMP_U (a, ==, b, v)
		return 1;

	return 0;
}

static int
test_compare_lt (const union vec a, const union vec b)
{
	union vec v = vec_lt(a, b);

	IF_NOT_CMP_F (a, <, b, v)
		return 1;

	return 0;
}

static int
test_compare_ilt (const union vec a, const union vec b)
{
	union vec v = vec_ilt(a, b);

	IF_NOT_CMP_I (a, <, b, v)
		return 1;

	return 0;
}

static int
test_compare_ult (const union vec a, const union vec b)
{
	union vec v = vec_ult(a, b);

	IF_NOT_CMP_U (a, <, b, v)
		return 1;

	return 0;
}

static int
test_compare_le (const union vec a, const union vec b)
{
	union vec v = vec_le(a, b);

	IF_NOT_CMP_F (a, <=, b, v)
		return 1;

	return 0;
}

static int
test_compare_ile (const union vec a, const union vec b)
{
	union vec v = vec_ile(a, b);

	IF_NOT_CMP_I (a, <=, b, v)
		return 1;

	return 0;
}

static int
test_compare_ule (const union vec a, const union vec b)
{
	union vec v = vec_ule(a, b);

	IF_NOT_CMP_U (a, <=, b, v)
		return 1;

	return 0;
}


static int
test_compare_gt (const union vec a, const union vec b)
{
	union vec v = vec_gt(a, b);

	IF_NOT_CMP_F (a, >, b, v)
		return 1;

	return 0;
}

static int
test_compare_igt (const union vec a, const union vec b)
{
	union vec v = vec_igt(a, b);

	IF_NOT_CMP_I (a, >, b, v)
		return 1;

	return 0;
}

static int
test_compare_ugt (const union vec a, const union vec b)
{
	union vec v = vec_ugt(a, b);

	IF_NOT_CMP_U (a, >, b, v)
		return 1;

	return 0;
}


static int
test_compare_ge (const union vec a, const union vec b)
{
	union vec v = vec_ge(a, b);

	IF_NOT_CMP_F (a, >=, b, v)
		return 1;

	return 0;
}

static int
test_compare_ige (const union vec a, const union vec b)
{
	union vec v = vec_ige(a, b);

	IF_NOT_CMP_I (a, >=, b, v)
		return 1;

	return 0;
}

static int
test_compare_uge (const union vec a, const union vec b)
{
	union vec v = vec_uge(a, b);

	IF_NOT_CMP_U (a, >=, b, v)
		return 1;

	return 0;
}

static int
test_compare (void)
{
	int ret = 0;

	// Test floating point math by running through all permutations of the
	// test value array:
	for (size_t i = 0U; i < NELEM(fval); i++) {
		const union vec a = vtestf(i);
		for (size_t j = 0U; j < NELEM(fval); j++) {
			const union vec b = vtestf(j);
			ret |= test_compare_eq(a, b);
			ret |= test_compare_lt(a, b);
			ret |= test_compare_le(a, b);
			ret |= test_compare_gt(a, b);
			ret |= test_compare_ge(a, b);
		}
	}

	// Tests on signed integers;
	for (size_t i = 0U; i < NELEM(ival); i++) {
		const union vec a = vtesti(i);
		for (size_t j = 0U; j < NELEM(ival); j++) {
			const union vec b = vtesti(j);
			ret |= test_compare_ieq(a, b);
			ret |= test_compare_ilt(a, b);
			ret |= test_compare_ile(a, b);
			ret |= test_compare_igt(a, b);
			ret |= test_compare_ige(a, b);
		}
	}

	// Tests on unsigned integers;
	for (size_t i = 0U; i < NELEM(uval); i++) {
		const union vec a = vtestu(i);
		for (size_t j = 0U; j < NELEM(uval); j++) {
			const union vec b = vtestu(j);
			ret |= test_compare_ueq(a, b);
			ret |= test_compare_ult(a, b);
			ret |= test_compare_ule(a, b);
			ret |= test_compare_ugt(a, b);
			ret |= test_compare_uge(a, b);
		}
	}

	return ret;
}
