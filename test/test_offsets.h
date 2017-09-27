static int
test_offsets (void)
{
	int ret = 0;

	struct {
		const char *name;
		size_t expect;
		size_t actual;
	}
	offsets[] = {
		{ ".x",         0U, offsetof(union vec, x)      },
		{ ".y",         4U, offsetof(union vec, y)      },
		{ ".z",         8U, offsetof(union vec, z)      },
		{ ".w",        12U, offsetof(union vec, w)      },
		{ ".xi",        0U, offsetof(union vec, xi)     },
		{ ".yi",        4U, offsetof(union vec, yi)     },
		{ ".zi",        8U, offsetof(union vec, zi)     },
		{ ".wi",       12U, offsetof(union vec, wi)     },
		{ ".xu",        0U, offsetof(union vec, xu)     },
		{ ".yu",        4U, offsetof(union vec, yu)     },
		{ ".zu",        8U, offsetof(union vec, zu)     },
		{ ".wu",       12U, offsetof(union vec, wu)     },
		{ ".elem.f",    0U, offsetof(union vec, elem.f) },
		{ ".elem.i",    0U, offsetof(union vec, elem.i) },
		{ ".elem.u",    0U, offsetof(union vec, elem.u) },
#if defined(VEC_GCC)
		{ ".gcc.f",     0U, offsetof(union vec, gcc.f)  },
		{ ".gcc.i",     0U, offsetof(union vec, gcc.i)  },
		{ ".gcc.u",     0U, offsetof(union vec, gcc.u)  },
#endif
#if defined(VEC_SSE2)
		{ ".sse.f",     0U, offsetof(union vec, sse.f)  },
		{ ".sse.i",     0U, offsetof(union vec, sse.i)  },
		{ ".sse.u",     0U, offsetof(union vec, sse.u)  },
#endif
#if defined(VEC_NEON)
		{ ".neon.f",    0U, offsetof(union vec, neon.f) },
		{ ".neon.i",    0U, offsetof(union vec, neon.i) },
		{ ".neon.u",    0U, offsetof(union vec, neon.u) },
#endif
	};

	FOREACH (offsets, o) {
		if (o->expect != o->actual) {
			ERROR("offsetof(%s) is %zu, expected %zu", o->name, o->actual, o->expect);
			ret = 1;
		}
	}

	return ret;
}
