#include <iostream>

int main() {
    int n, i;
    std::cin >> n >> i;

    int digits[10] = { 0 };
    int digit_at_i = -1;
    int index = 0;

    while (n > 0) {
        int d = n % 10;
        digits[d]++;
        if (index == i) {
            digit_at_i = d;
        }
        n /= 10;
        index++;
    }

    int K = 0;
    for (int j = 0; j < 10; j++) {
        if (digits[j] > 0) {
            K++;
        }
    }

    std::cout << K << std::endl;
    if (digit_at_i != -1) {
        std::cout << digit_at_i << std::endl;
    }

    return 0;
}