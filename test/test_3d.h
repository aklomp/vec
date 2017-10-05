static int
test_3d_dot (const union vec a, const union vec b)
{
	float expect = a.x * b.x + a.y * b.y + a.z * b.z;
	float result = vec_dot(a, b);

	if (!APPROX(expect, result)) {
		ERROR("expected %0.2f, got %0.2f", expect, result);
		return 1;
	}

	return 0;
}

static int
test_3d_cross (const union vec a, const union vec b)
{
	union vec v = vec_cross(a, b);

	IF_NOT_APPROX(a.y * b.z - a.z * b.y,
	              a.z * b.x - a.x * b.z,
	              a.x * b.y - a.y * b.x, 0.0f, v)
		return 1;

	return 0;
}

static int
test_3d (void)
{
	int ret = 0;

	for (size_t i = 0U; i < NELEM(fval); i++) {
		const union vec a = vtestf(i);
		for (size_t j = 0U; j < NELEM(fval); j++) {
			const union vec b = vtestf(j);
			ret |= test_3d_dot  (a, b);
			ret |= test_3d_cross(a, b);
		}
	}

	return ret;
}
