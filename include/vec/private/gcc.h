// Return float version of a + b:
#ifndef VEC_FN_ADD
#define VEC_FN_ADD
static inline union vec
vec_add (const union vec a, const union vec b)
{
	return (union vec) { .gcc.f = a.gcc.f + b.gcc.f };
}
#endif

// Return signed integer version of a + b:
#ifndef VEC_FN_IADD
#define VEC_FN_IADD
static inline union vec
vec_iadd (const union vec a, const union vec b)
{
	return (union vec) { .gcc.i = a.gcc.i + b.gcc.i };
}
#endif

// Return unsigned integer version of a + b:
#ifndef VEC_FN_UADD
#define VEC_FN_UADD
static inline union vec
vec_uadd (const union vec a, const union vec b)
{
	return (union vec) { .gcc.u = a.gcc.u + b.gcc.u };
}
#endif

// Return float version of a - b:
#ifndef VEC_FN_SUB
#define VEC_FN_SUB
static inline union vec
vec_sub (const union vec a, const union vec b)
{
	return (union vec) { .gcc.f = a.gcc.f - b.gcc.f };
}
#endif

// Return signed integer version of a - b:
#ifndef VEC_FN_ISUB
#define VEC_FN_ISUB
static inline union vec
vec_isub (const union vec a, const union vec b)
{
	return (union vec) { .gcc.i = a.gcc.i - b.gcc.i };
}
#endif

// Return unsigned integer version of a - b:
#ifndef VEC_FN_USUB
#define VEC_FN_USUB
static inline union vec
vec_usub (const union vec a, const union vec b)
{
	return (union vec) { .gcc.u = a.gcc.u - b.gcc.u };
}
#endif

// Return float version of a * b:
#ifndef VEC_FN_MUL
#define VEC_FN_MUL
static inline union vec
vec_mul (const union vec a, const union vec b)
{
	return (union vec) { .gcc.f = a.gcc.f * b.gcc.f };
}
#endif

// Return float version of a / b:
#ifndef VEC_FN_DIV
#define VEC_FN_DIV
static inline union vec
vec_div (const union vec a, const union vec b)
{
	return (union vec) { .gcc.f = a.gcc.f / b.gcc.f };
}
#endif
