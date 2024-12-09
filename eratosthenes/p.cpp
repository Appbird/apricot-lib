#include <iostream>

/// -----------------------------------------------------
/// snippet start
/// -----------------------------------------------------

#include <vector>
// reference: https://algo-method.com/descriptions/64
std::vector<bool> eratosthenes_sieve(size_t N) {
    std::vector<bool> prime(N + 1, true);
    prime[0] = false;
    prime[1] = false;
    for (int64_t p = 0; p <= N; ++p) {
        if (not prime[p]) { continue; }
        for (int64_t q = p * 2; q <= N; q += p) {
            prime[q] = false;
        }
    }
    return prime;
}

/// -----------------------------------------------------
/// snippet end
/// -----------------------------------------------------

/// @brief accepted: https://algo-method.com/tasks/330
int32_t main() {
    int32_t N; std::cin >> N;
    auto primes = eratosthenes_sieve(N);
    int32_t ans = 0;
    for (int32_t i = 0; i <= N; i++) { ans += (primes[i] ? 1 : 0); }
    std::cout << ans << std::endl;
}