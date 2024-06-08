#include <vector>
#include <cassert>
#include <iostream>
#include "exp.hpp"
using std::abs;

int main(){
    assert(powint(3, 3) == 27);
    assert(powint(3, 4) == 27 * 3);
    assert(powint(-1, 3) == -1);
    assert(powint(-1, 4) == 1);
    assert(powint(6, 0) == 1);

    assert(logint(10, 1) == 0);
    assert(logint(10, 4) == 0);
    assert(logint(10, 100) == 2);
    assert(logint(10, 141) == 2);
    assert(logint(10, 999) == 2);
    assert(logint_ceil(10, 141) == 3);
    assert(logint_ceil(10, 999) == 3);
    assert(logint(10, 1000) == 3);


    assert(hyperfloor(10, 100) == 100);
    assert(hyperfloor(10, 141) == 100);
    assert(hyperfloor(10, 1000) == 1000);
    assert(hyperceil(10, 100) == 100);
    assert(hyperceil(10, 141) == 1000);
    assert(hyperceil(10, 1000) == 1000);

    assert(lower_pow2(4) == 4);
    assert(lower_pow2(5) == 4);
    assert(lower_pow2(7) == 4);
    assert(lower_pow2(8) == 8);
    
    assert(upper_pow2(4) == 4);
    assert(upper_pow2(5) == 8);
    assert(upper_pow2(7) == 8);
    assert(upper_pow2(8) == 8);
    
    return 0;
}