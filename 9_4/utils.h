#pragma once

// 素数判别
bool isPrime(size_t n) {
    size_t i;
    size_t sup1 = n / 2;

    for (i = 2; i < sup1 || i * i <= n; i++) {
        if (n % i) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}
