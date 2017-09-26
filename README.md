# vec

A small, header-only, cross-platform SIMD vector library for C11. Provides an
abstraction of 128-bit vectors divided into four 32-bit elements, which can be
floating or integer. Does this using a clever `union` type. Oriented mainly
towards 3D graphics, but can be used for any type of 32×4 bit vector.

## License

MIT license. See `LICENSE` file for details.
