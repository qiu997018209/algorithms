#define u32 unsigned int
#define JHASH_GOLDEN_RATIO  0x9e3779b9 

/*mix three value*/
#define __jhash_mix(a, b, c) \
{\
	a -= b; a -= c; a ^= (c>>13);\
	b -= c; b -= a; b ^= (a<<8);\
	c -= a; c -= b; c ^= (b>>13);\
	a -= b; a -= c; a ^= (c>>12);\
	b -= c; b -= a; b ^= (a<<16);\
	c -= a; c -= b; c ^= (b>>5);\
	a -= b; a -= c; a ^= (c>>3);\
	b -= c; b -= a; b ^= (a<<10);\
	c -= a; c -= b; c ^= (b>>15);\
}

static inline u32 jhash_3words(u32 a, u32 b, u32 c, u32 initval)
{
	a += JHASH_GOLDEN_RATIO;
	b += JHASH_GOLDEN_RATIO;
	c += initval;

	__jhash_mix(a, b, c);

	return c;
}

static inline u32 jhash_1words(u32 a, u32 initval)
{		
	return jhash_3words(0,0,a,initval);
}
