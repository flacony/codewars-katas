#include <iostream>
#include <vector>
#include <cmath>

int getBitsCount(ulong n) {
    int length{0};
    while (n) {
        length++;
        n >>= 1;
    }
    return length;
}

ulong mystery(ulong n) {
    ulong result{0};
    int m = getBitsCount(n);
    while (m) {
        result <<= 1;
        if (n >= pow(2, m - 1)) {
            result += 1;
            n = pow(2, m) - 1 - n;
        }
        --m;
    }
    return result;
}

ulong mysteryInv(ulong n) {
    ulong result{0};
    int m {0};
    while (n) {
        m++;
        if (n & 1) {
            result = pow(2, m) - 1 - result;
        }
        n >>= 1;
    }
    return result;
}

std::string nameOfMystery() {
    return "Gray code";
}