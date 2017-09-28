static int
test_convert_to_int (const union vec a)
{
	union vec v = vec_to_int(a);

	IF_NOT_EQUALS_I ((int32_t) a.x, (int32_t) a.y, (int32_t) a.z, (int32_t) a.w, v)
		return 1;

	return 0;
}

static int
test_convert_to_float (const union vec a)
{
	union vec v = vec_to_float(a);

	IF_NOT_EQUALS_F ((float) a.xi, (float) a.yi, (float) a.zi, (float) a.wi, v)
		return 1;

	return 0;
}

static int
test_convert (void)
{
	int ret = 0;

	for (size_t i = 0U; i < NELEM(fval); i++)
		ret |= test_convert_to_int(vtestf(i));

	for (size_t i = 0U; i < NELEM(ival); i++)
		ret |= test_convert_to_float(vtesti(i));

	return ret;
}
