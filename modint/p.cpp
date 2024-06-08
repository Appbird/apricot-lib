#include <iostream>
#include <assert.h>
#include "modint.hpp"

const int64_t p = 998244353;

void test_add() {
    modint x = p - 4;
    modint y = p - 7;
    {
        modint z = -11;
        assert(x + y == z);
        assert(x + y == -11);
        assert(x + (p-7) == -11);
        assert(x + y != -10);
        z += x;
        assert(z == -15);
    }
    {
        modint z = 3;
        assert(x - y == z);
        assert(x - (p-7) == z);
        assert(x - y == 3);
        z -= x;
        assert(z == 7);
    }
}

void test_prod1() {
    modint x = p - 4;
    modint y = p - 7;
    {
        modint z = 28;
        assert(x * y == z);
        assert(x * y == 28);
        assert(x * (p-7) == 28);
        z *= x;
        assert(z == 28 * (-4));
    }
}
void test_prod2() {
    modint x = p - 3;
    modint y = p + 7;
    {
        modint z = -21;
        assert(x * y == z);
        assert(x * y == -21);
        z *= y;
        assert(z == (-21) * 7);
    }
}
void test_div() {
    modint x = 53;
    modint y = 53;
    modint z = 12345678900000;
    modint x_inv = x.inv();
    
    assert(x * x_inv == 1);
    assert(z / 100000 == 123456789);
    assert(x / x == 1);
    x /= y;
    assert(x == 1);
}



// test code of modint
int main(){
    test_add();
    test_prod1();
    test_prod2();
    test_div();
    std::cout << "test completed!" << std::endl;
}