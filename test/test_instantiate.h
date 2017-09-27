static int
test_instantiate_vec (const float x, const float y, const float z, const float w)
{
	static const float qx = -1e6f, qy = -1e-6f, qz = 1e-6f, qw = 1e6f;
	union vec v = vec(x, y, z, w);
	union vec q = VEC(qx, qy, qz, qw);

	IF_NOT_EQUALS_F (x, y, z, w, v)
		return 1;

	IF_NOT_EQUALS_F (qx, qy, qz, qw, q)
		return 1;

	return 0;
}

static int
test_instantiate_vec_i (const int32_t x, const int32_t y, const int32_t z, const int32_t w)
{
	static const int32_t qx = INT32_C(-1000);
	static const int32_t qy = INT32_C(-1);
	static const int32_t qz = INT32_C(1);
	static const int32_t qw = INT32_C(1000);
	union vec v = vec_i(x, y, z, w);
	union vec q = VEC_I(qx, qy, qz, qw);

	IF_NOT_EQUALS_I (x, y, z, w, v)
		return 1;

	IF_NOT_EQUALS_I (qx, qy, qz, qw, q)
		return 1;

	return 0;
}

static int
test_instantiate_vec_u (const uint32_t x, const uint32_t y, const uint32_t z, const uint32_t w)
{
	static const uint32_t qx = UINT32_C(0);
	static const uint32_t qy = UINT32_C(1);
	static const uint32_t qz = UINT32_C(1000);
	static const uint32_t qw = UINT32_C(0xFFFFFFFF);
	union vec v = vec_u(x, y, z, w);
	union vec q = VEC_U(qx, qy, qz, qw);

	IF_NOT_EQUALS_U (x, y, z, w, v)
		return 1;

	IF_NOT_EQUALS_U (qx, qy, qz, qw, q)
		return 1;

	return 0;
}

static int
test_instantiate_vec_1 (const float val)
{
	union vec v = vec_1(val);

	IF_NOT_EQUALS_F (val, val, val, val, v)
		return 1;

	return 0;
}

static int
test_instantiate_vec_i1 (const int32_t val)
{
	union vec v = vec_i1(val);

	IF_NOT_EQUALS_I (val, val, val, val, v)
		return 1;

	return 0;
}

static int
test_instantiate_vec_u1 (const uint32_t val)
{
	union vec v = vec_u1(val);

	IF_NOT_EQUALS_U (val, val, val, val, v)
		return 1;

	return 0;
}

static int
test_instantiate_vec_zero (void)
{
	union vec v = vec_zero();

	IF_NOT_EQUALS_F (0.0f, 0.0f, 0.0f, 0.0f, v)
		return 1;

	return 0;
}

static int
test_instantiate_vec_izero (void)
{
	union vec v = vec_izero();

	IF_NOT_EQUALS_I (INT32_C(0), INT32_C(0), INT32_C(0), INT32_C(0), v)
		return 1;

	return 0;
}

static int
test_instantiate_vec_uzero (void)
{
	union vec v = vec_uzero();

	IF_NOT_EQUALS_U (UINT32_C(0), UINT32_C(0), UINT32_C(0), UINT32_C(0), v)
		return 1;

	return 0;
}


static int
test_instantiate (void)
{
	int ret = 0;

	ret |= test_instantiate_vec(1.0f, 2.0f, 4.0f, 8.0f);
	ret |= test_instantiate_vec_i(INT32_C(-1), INT32_C(2), INT32_C(-4), INT32_C(8));
	ret |= test_instantiate_vec_u(UINT32_C(1), UINT32_C(2), UINT32_C(4), UINT32_C(0xFFFFFFFF));
	ret |= test_instantiate_vec_1(42.0f);
	ret |= test_instantiate_vec_i1(INT32_C(-42));
	ret |= test_instantiate_vec_u1(UINT32_C(0xFFFFFFFF));
	ret |= test_instantiate_vec_zero();
	ret |= test_instantiate_vec_izero();
	ret |= test_instantiate_vec_uzero();

	return ret;
}
