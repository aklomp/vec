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

// Return cross product of two 3D vectors:
#ifndef VEC_FN_CROSS
#define VEC_FN_CROSS
static inline union vec
vec_cross (const union vec a, const union vec b)
{
	// Make read/write copies of the inputs:
	float32x4_t atmp = a.neon.f, btmp = b.neon.f;
	float32x4_t ret, tmp;

	__asm__ (
		"vext.8    %q0,%q2,%q2,#4  \n\t"	// q0 := ayzwx
		"vext.8    %q1,%q3,%q3,#4  \n\t"	// q1 := byzwx
		"vrev64.32 %f0,%f0         \n\t"	// q0 := ayzxw
		"vrev64.32 %f1,%f1         \n\t"	// q1 := byzxw

		"vtrn.32   %e2,%f2         \n\t"	// q2 := axzyw
		"vtrn.32   %e3,%f3         \n\t"	// q3 := bxzyw
		"vrev64.32 %e2,%e2         \n\t"	// q2 := azxyw
		"vrev64.32 %e3,%e3         \n\t"	// q3 := bzxyw

		"vmulq.f32 %q0,%q0,%q3     \n\t"	// q0 := ayzxw * bzxyw
		"vmlsq.f32 %q0,%q2,%q1     \n\t"	// q0 := ayzxw * bzxyw - azxyw * byzxw

		: "=&w" (ret), "=&w" (tmp),		// Outputs: ret=q0, tmp=q1
		  "+%w" (atmp), "+w" (btmp)		// Outputs (reused inputs): a=q2, b=q3
	);

	return (union vec) { .neon.f = ret };
}
#endif
