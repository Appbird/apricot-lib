#include <cassert>
#include <iostream>
using std::abs;
#define snap(x) std::cerr << #x << "=" << (x) << std::endl;

/// -----------------------------------------------------
/// snippet start
/// -----------------------------------------------------

#include <vector>
#include <functional>
/// @note 配列は1-originなので、add, sumを使う際も1-originで指定すること
struct FenwickTree {
    using T = int32_t;
    const T e = 0;
    const std::function<T(T,T)> biop = [](const T& a, const T& b){ return a + b; };
    // A[i]: iを終端とする長さlsb(i)の区間和
    std::vector<T> A;
    FenwickTree(size_t N): A(N+1, e) {}
    FenwickTree(int32_t N): A(N+1, e) {}
    void add(size_t i, T dx) {
        for (; i < A.size(); i += (i&-i)) { A[i] = biop(A[i], dx); }
    }
    T sum(size_t i) const {
        T x = 0;
        for (; i > 0; i -= (i&-i)) { x = biop(x, A[i]); }
        return x;
    }
    T sum(size_t l, size_t r) { return sum(r) - sum(l-1); }
};

std::ostream& operator<<(std::ostream& os, const FenwickTree& bit) {
    os << "{";
    for (size_t i = 1; i < bit.A.size(); i++) {
        os << "[" << i + 1 - (i&-i) << "," << i + 1 << ")=";
        os << bit.A[i] << ", ";
    }
    return os << "}";
}

/// -----------------------------------------------------
/// snippet end
/// -----------------------------------------------------


/// @brief accepted in https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B
int main(){
    int32_t N, Q; std::cin >> N >> Q;
    FenwickTree bit{N};
    for (size_t i = 0; i < Q; i++) {
        int32_t com, x, y; std::cin >> com >> x >> y;
        //snap(bit);
        switch (com) {
        case 0:
            bit.add(x, y);
            break;
        
        case 1:
            std::cout << bit.sum(x, y) << std::endl;
            break;
        }
    }
    
    return 0;
}