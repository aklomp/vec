// Instantiate a float vector:
#ifndef VEC_FN_
#define VEC_FN_
static inline union vec
vec (const float x, const float y, const float z, const float w)
{
	union {
		float    i[2];
		uint64_t u;
	} lo = { { x, y } }
	, hi = { { z, w } };

	return (union vec) { .neon.f = vcombine_f32(vcreate_f32(lo.u), vcreate_f32(hi.u)) };
}
#endif

// Instantiate a signed integer vector:
#ifndef VEC_FN_I
#define VEC_FN_I
static inline union vec
vec_i (const int32_t x, const int32_t y, const int32_t z, const int32_t w)
{
	union {
		int32_t  i[2];
		uint64_t u;
	} lo = { { x, y } }
	, hi = { { z, w } };

	return (union vec) { .neon.i = vcombine_s32(vcreate_s32(lo.u), vcreate_s32(hi.u)) };
}
#endif

// Instantiate an unsigned integer vector:
#ifndef VEC_FN_U
#define VEC_FN_U
static inline union vec
vec_u (const uint32_t x, const uint32_t y, const uint32_t z, const uint32_t w)
{
	union {
		uint32_t i[2];
		uint64_t u;
	} lo = { { x, y } }
	, hi = { { z, w } };

	return (union vec) { .neon.u = vcombine_u32(vcreate_u32(lo.u), vcreate_u32(hi.u)) };
}
#endif

// Instantiate a float vector with four identical elements:
#ifndef VEC_FN_1
#define VEC_FN_1
static inline union vec
vec_1 (const float val)
{
	return (union vec) { .neon.f = vdupq_n_f32(val) };
}
#endif

// Instantiate a signed integer vector with four identical elements:
#ifndef VEC_FN_I1
#define VEC_FN_I1
static inline union vec
vec_i1 (const int32_t val)
{
	return (union vec) { .neon.i = vdupq_n_s32(val) };
}
#endif

// Instantiate an unsigned integer vector with four identical elements:
#ifndef VEC_FN_U1
#define VEC_FN_U1
static inline union vec
vec_u1 (const uint32_t val)
{
	return (union vec) { .neon.u = vdupq_n_u32(val) };
}
#endif

// Instantiate a float vector set to all zeros:
#ifndef VEC_FN_ZERO
#define VEC_FN_ZERO
static inline union vec
vec_zero (void)
{
	return vec_1(0.0f);
}
#endif

// Instantiate a signed integer vector set to all zeros:
#ifndef VEC_FN_IZERO
#define VEC_FN_IZERO
static inline union vec
vec_izero (void)
{
	return vec_i1(0);
}
#endif

// Instantiate an unsigned integer vector set to all zeros:
#ifndef VEC_FN_UZERO
#define VEC_FN_UZERO
static inline union vec
vec_uzero (void)
{
	return vec_u1(0U);
}
#endif

// Convert a float vector to signed integer:
#ifndef VEC_FN_TO_INT
#define VEC_FN_TO_INT
static inline union vec
vec_to_int (const union vec v)
{
	return (union vec) { .neon.i = vcvtq_s32_f32(v.neon.f) };
}
#endif

// Convert a signed integer vector to float:
#ifndef VEC_FN_TO_FLOAT
#define VEC_FN_TO_FLOAT
static inline union vec
vec_to_float (const union vec v)
{
	return (union vec) { .neon.f = vcvtq_f32_s32(v.neon.i) };
}
#endif
