#ifndef MODINT_HEADER
#define MODINT_HEADER
#include <iostream> 
#include <assert.h>

// snippet
template<int64_t p = 998244353>
struct modint {
    int64_t x = 0;

    int64_t mod(const int64_t& x)       { return (x % p + p) % p; }
    modint()                            {}
    modint(int64_t _x): x(mod(_x))            {}
    bool operator==(const modint& _x)   { return this->x == _x.x; }
    bool operator!=(const modint& _x)   { return this->x != _x.x; }
    modint operator+(const modint& m)   { return { this->x + m.x }; }
    modint operator-(const modint& m)   { return { this->x - m.x }; }
    modint operator*(const modint& m)   { return { this->x * m.x }; }
    modint operator/(const modint& m)   { return *this * m.inv(); }
    modint operator+=(const modint& m)  { return *this = *this + m; }
    modint operator-=(const modint& m)  { return *this = *this - m; }
    modint operator*=(const modint& m)  { return *this = *this * m; }
    modint operator/=(const modint& m)  { return *this = *this / m; }
    /// @brief 二分累乗法によって、x^{-1} = x^{p - 2} (mod p)を求める。この等式の成立はフェルマーの小定理による。
    modint inv() const {
        modint sq = x;
        modint ans = 1;
        for (int64_t q = p - 2; q > 0; q >>= 1, sq = sq * sq) {
            if ((q & 1ll) == 1ll) { ans *= sq; }
        }
        return ans;
    }
};

template<int64_t p = 998244353>
std::ostream& operator<<(std::ostream& os, const modint<p>& m) {
    return os << m.x;
}
template<int64_t p = 998244353>
std::istream& operator>>(std::istream& is, modint<p>& m) {
    return is >> m.x;
}
#endif