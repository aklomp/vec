static int
test_sizes (void)
{
	int ret = 0;
	union vec v;

	struct {
		const char *name;
		size_t expect;
		size_t actual;
	}
	sizes[] = {
		{ "union vec", 16U, sizeof(v)        },
		{ ".x",         4U, sizeof(v.x)      },
		{ ".y",         4U, sizeof(v.y)      },
		{ ".z",         4U, sizeof(v.z)      },
		{ ".w",         4U, sizeof(v.w)      },
		{ ".xi",        4U, sizeof(v.xi)     },
		{ ".yi",        4U, sizeof(v.yi)     },
		{ ".zi",        4U, sizeof(v.zi)     },
		{ ".wi",        4U, sizeof(v.wi)     },
		{ ".xu",        4U, sizeof(v.xu)     },
		{ ".yu",        4U, sizeof(v.yu)     },
		{ ".zu",        4U, sizeof(v.zu)     },
		{ ".wu",        4U, sizeof(v.wu)     },
		{ ".elem.f",   16U, sizeof(v.elem.f) },
		{ ".elem.i",   16U, sizeof(v.elem.i) },
		{ ".elem.u",   16U, sizeof(v.elem.u) },
#if defined(VEC_GCC)
		{ ".gcc.f",    16U, sizeof(v.gcc.f)  },
		{ ".gcc.i",    16U, sizeof(v.gcc.i)  },
		{ ".gcc.u",    16U, sizeof(v.gcc.u)  },
#endif
#if defined(VEC_SSE2)
		{ ".sse.f",    16U, sizeof(v.sse.f)  },
		{ ".sse.i",    16U, sizeof(v.sse.i)  },
		{ ".sse.u",    16U, sizeof(v.sse.u)  },
#endif
#if defined(VEC_NEON)
		{ ".neon.f",   16U, sizeof(v.neon.f) },
		{ ".neon.i",   16U, sizeof(v.neon.i) },
		{ ".neon.u",   16U, sizeof(v.neon.u) },
#endif
	};

	FOREACH (sizes, s) {
		if (s->expect != s->actual) {
			ERROR("sizeof(%s) is %zu, expected %zu", s->name, s->actual, s->expect);
			ret = 1;
		}
	}

	return ret;
}
