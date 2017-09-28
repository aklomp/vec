static int
test_arith_add (const union vec a, const union vec b)
{
	union vec v = vec_add(a, b);

	IF_NOT_APPROX (a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w, v)
		return 1;

	return 0;
}

static int
test_arith_iadd (const union vec a, const union vec b)
{
	union vec v = vec_iadd(a, b);

	IF_NOT_EQUALS_I (a.xi + b.xi, a.yi + b.yi, a.zi + b.zi, a.wi + b.wi, v)
		return 1;

	return 0;
}

static int
test_arith_uadd (const union vec a, const union vec b)
{
	union vec v = vec_uadd(a, b);

	IF_NOT_EQUALS_U (a.xu + b.xu, a.yu + b.yu, a.zu + b.zu, a.wu + b.wu, v)
		return 1;

	return 0;
}

static int
test_arith_sub (const union vec a, const union vec b)
{
	union vec v = vec_sub(a, b);

	IF_NOT_APPROX (a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w, v)
		return 1;

	return 0;
}

static int
test_arith_isub (const union vec a, const union vec b)
{
	union vec v = vec_isub(a, b);

	IF_NOT_EQUALS_I (a.xi - b.xi, a.yi - b.yi, a.zi - b.zi, a.wi - b.wi, v)
		return 1;

	return 0;
}

static int
test_arith_usub (const union vec a, const union vec b)
{
	union vec v = vec_usub(a, b);

	IF_NOT_EQUALS_U (a.xu - b.xu, a.yu - b.yu, a.zu - b.zu, a.wu - b.wu, v)
		return 1;

	return 0;
}

static int
test_arith_mul (const union vec a, const union vec b)
{
	union vec v = vec_mul(a, b);

	IF_NOT_APPROX (a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w, v)
		return 1;

	return 0;
}

static int
test_arith_div (const union vec a, const union vec b)
{
	union vec v = vec_div(a, b);

	IF_NOT_APPROX (a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w, v)
		return 1;

	return 0;
}

static int
test_arith (void)
{
	int ret = 0;

	// Test floating point math by running through all permutations of the
	// test value array:
	for (size_t i = 0U; i < NELEM(fval); i++) {
		const union vec a = vtestf(i);
		for (size_t j = 0U; j < NELEM(fval); j++) {
			const union vec b = vtestf(j);
			ret |= test_arith_add(a, b);
			ret |= test_arith_sub(a, b);
			ret |= test_arith_mul(a, b);
			ret |= test_arith_div(a, b);
		}
	}

	// Tests on signed integers;
	for (size_t i = 0U; i < NELEM(ival); i++) {
		const union vec a = vtesti(i);
		for (size_t j = 0U; j < NELEM(ival); j++) {
			const union vec b = vtesti(j);
			ret |= test_arith_iadd(a, b);
			ret |= test_arith_isub(a, b);
		}
	}

	// Tests on unsigned integers;
	for (size_t i = 0U; i < NELEM(uval); i++) {
		const union vec a = vtestu(i);
		for (size_t j = 0U; j < NELEM(uval); j++) {
			const union vec b = vtestu(j);
			ret |= test_arith_uadd(a, b);
			ret |= test_arith_usub(a, b);
		}
	}

	return ret;
}
