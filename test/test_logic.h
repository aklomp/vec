static int
test_logic_and (const union vec a, const union vec b)
{
	union vec v = vec_and(a, b);

	IF_NOT_EQUALS_U (a.xu & b.xu, a.yu & b.yu, a.zu & b.zu, a.wu & b.wu, v)
		return 1;

	return 0;
}

static int
test_logic_or (const union vec a, const union vec b)
{
	union vec v = vec_or(a, b);

	IF_NOT_EQUALS_U (a.xu | b.xu, a.yu | b.yu, a.zu | b.zu, a.wu | b.wu, v)
		return 1;

	return 0;
}

static int
test_logic_xor (const union vec a, const union vec b)
{
	union vec v = vec_xor(a, b);

	IF_NOT_EQUALS_U (a.xu ^ b.xu, a.yu ^ b.yu, a.zu ^ b.zu, a.wu ^ b.wu, v)
		return 1;

	return 0;
}

static int
test_logic_not (const union vec a)
{
	union vec v = vec_not(a);

	IF_NOT_EQUALS_U (~a.xu, ~a.yu, ~a.zu, ~a.wu, v)
		return 1;

	return 0;
}

static int
test_logic (void)
{
	int ret = 0;

	for (size_t i = 0U; i < NELEM(uval); i++) {
		const union vec a = vtestu(i);
		for (size_t j = 0U; j < NELEM(uval); j++) {
			const union vec b = vtestu(j);
			ret |= test_logic_and(a, b);
			ret |= test_logic_or (a, b);
			ret |= test_logic_xor(a, b);
		}
		ret |= test_logic_not(a);
	}

	return ret;
}
