CFLAGS += -std=c11 -march=native
CFLAGS += -I ../include

# Binary files to generate.
BINS = test-gcc test-generic test-host
OBJS = $(BINS:=.o)

.PHONY: all clean test

all: $(BINS)

# Suppress platform-dependent hardware SIMD support, which leaves
# GCC vector extensions and generic functions.
test-gcc: CFLAGS += -DVEC_SUPPRESS_HW

# Suppress SIMD and GCC vector extension support, which leaves
# only generic functions.
test-generic: CFLAGS += -DVEC_SUPPRESS_HW -DVEC_SUPPRESS_GCC

$(OBJS): main.c
	$(CC) $(CFLAGS) -o $@ -c $^

$(BINS): %: %.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	$(RM) $(BINS) $(OBJS)

test: clean $(BINS)
	./test-gcc
	./test-generic
	./test-host
