// Return float version of a / b:
#ifndef VEC_FN_DIV
#define VEC_FN_DIV
static inline union vec
vec_div (const union vec a, const union vec b)
{
	float32x4_t ret, tmp;

	__asm__ (
		"vrecpeq.f32 %q0,%q3      \n\t"
		"vrecpsq.f32 %q1,%q3,%q0  \n\t"
		"vmulq.f32   %q0,%q1,%q0  \n\t"
		"vrecpsq.f32 %q1,%q3,%q0  \n\t"
		"vmulq.f32   %q0,%q1,%q0  \n\t"
		"vmulq.f32   %q0,%q2,%q0  \n\t"

		: "=&w" (ret), "=&w" (tmp)		// Outputs: ret=q0, tmp=q1
		: "%w" (a.neon.f), "w" (b.neon.f)	// Inputs: a=q2, b=q3
	);

	return (union vec) { .neon.f = ret };
}
#endif
