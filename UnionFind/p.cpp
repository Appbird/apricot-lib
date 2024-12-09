#include <iostream>
#include <cassert>
using std::abs;
#define snap(x) std::cerr << #x << "=" << (x) << std::endl;

/// -----------------------------------------------------
/// snippet start
/// -----------------------------------------------------

#include <vector>
/// @brief 経路圧縮を行うUnion-find Tree。
struct UnionFind {
    std::vector<int32_t> A;
    UnionFind(size_t N)     : A(N, -1) { }
    UnionFind(int32_t N)    : A(N, -1) { }
    int32_t leader(int32_t i) {
        if (A[i] == -1) { return i; }
        return A[i] = leader(A[i]);
    }
    bool same(int32_t i, int32_t j) {
        return leader(i) == leader(j);
    }
    void merge(int32_t i, int32_t j) {
        i = leader(i); j = leader(j);
        if (i == j) { return; }
        A[i] = j;
    }
};

std::ostream& operator<<(std::ostream& os, const UnionFind& uf) {
    os << "[";
    for (size_t i = 0; i < uf.A.size(); i++) { os << uf.A[i] << ", "; }
    return os << "]";
}

/// -----------------------------------------------------
/// snippet end
/// -----------------------------------------------------

/// @brief accepted in https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A.
int main(){
    int32_t N, Q; std::cin >> N >> Q;
    UnionFind uf{N};
    for (size_t i = 0; i < Q; i++) {
        int32_t com, x, y; std::cin >> com >> x >> y;
        //snap(uf);
        switch (com) {
        case 0:
            uf.merge(x, y);
            break;
        
        case 1:
            std::cout << uf.same(x, y) << std::endl;
            break;
        }
    }
    
    return 0;
}