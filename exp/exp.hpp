#ifndef EXP_HEADER
#define EXP_HEADER

#include <iostream>
#include <cstdint>
#include <assert.h>

int64_t powint(int64_t a, int64_t N) {
    int64_t result = 1;
    while (N > 0) {
        result *= a;
        N--;
    }
    return result;
}
// base**i <= Nを満たす最大のiを返す。
int64_t logint(int64_t base, int64_t N) {
    assert(N != 0);
    assert(base != 0);
    int64_t ans = 0;
    while (N >= base) {
        N /= base;
        ans++;
    }
    return ans;
}
// N <= base**iを満たす最小のiを返す。
int64_t logint_ceil(int64_t base, int64_t N) {
    assert(N != 0);
    assert(base != 0);
    if (N == 1) { return 0; }
    return logint(base, N-1) + 1;
}
// base**i <= Nを満たす最大のiに対して、base**iを返す。
int64_t hyperfloor(int64_t base, int64_t N) { return powint(base, logint(base, N));}
// N <= base**iを満たす最小のiに対して、base**iを返す。
int64_t hyperceil(int64_t base, int64_t N) { return powint(base, logint_ceil(base, N));}

int64_t lower_pow2(int64_t N)   { return hyperfloor(2, N); };
int64_t upper_pow2(int64_t N)   { return hyperceil(2, N); };
#endif