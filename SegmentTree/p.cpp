#include <cassert>
#include <iostream>

/// -----------------------------------------------------
/// snippet start
/// -----------------------------------------------------

#include <vector>
#include <numeric>
#include <functional>
#include <limits>
/// @note https://qiita.com/ageprocpp/items/f22040a57ad25d04d199
/// 制約: (T, biop)はモノイドをなす必要があり、eはTの単位元でなくてはならない。
struct SegmentTree {
    using T = int32_t;
    const T e = std::numeric_limits<T>::max();
    std::function<T(T,T)> biop = [](const T& x, const T& y){ return std::min(x, y); };
    
    std::vector<T> A; // 1-origin
    size_t N;
    SegmentTree(size_t length){
        N = 1;
        while (N < length) { N <<= 1; }
        A.resize(N<<1, e); // FIXED: N<<1 - 1を引くと範囲外
    }
    SegmentTree(int32_t length) : SegmentTree(size_t(length)) {}
    void update(size_t i, T x) {
        size_t idx = N + i; // NOTE: 1-originにしておくと、0 <= i < Nより-1を引かなくて済む。
        A[idx] = x;
        while (idx > 0) { idx /= 2; A[idx] = biop(A[2*idx], A[2*idx+1]); }
    }
    /// q: query, a: attention
    T query(size_t ql, size_t qr, size_t p, size_t al, size_t ar) const {
        if (qr <= al or ar <= ql) { return e; } // AとQが互いに素のとき、計算に影響しない単位元を返す。
        if (ql <= al and ar <= qr) { return A[p]; } // A subset Qのとき、AはQの区間を構成する一部なので、その部分の解を取り出す。
        size_t mid = (al + ar)/2;
        T l = query(ql, qr, 2*p, al, mid);
        T r = query(ql, qr, 2*p+1, mid, ar);
        return biop(l, r);
    }
    T query(size_t ql, size_t qr) { return query(ql, qr, 1, 0, N); }
};

std::ostream& operator<<(std::ostream& os, const SegmentTree& segtree){
    size_t l = (segtree.A.size())/2;
    size_t r = (segtree.A.size());
    while (l < r) {
        os << "[";
        for (int32_t i = l; i < r; i++) { os << segtree.A[i] << ", "; };
        l /= 2; r /= 2;
        os << "] > ";
    }
    return os;
}

/// -----------------------------------------------------
/// snippet end
/// -----------------------------------------------------



/// @brief accepted in https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A.
int main(){
    int32_t N, Q; std::cin >> N >> Q;
    SegmentTree segtree{N};
    for (size_t i = 0; i < Q; i++) {
        int32_t com, x, y; std::cin >> com >> x >> y;
        switch (com) {
        case 0:
            segtree.update(x, y);
            break;
        
        case 1:
            std::cout << segtree.query(x, y+1) << std::endl;
            break;
        }
    }
    
    return 0;
}