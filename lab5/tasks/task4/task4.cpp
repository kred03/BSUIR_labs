#include <iostream>
#include <cmath>
int main() {
    long long n;
    std::cin >> n;
    long long a = std::sqrt(n);
    if (n == a * a) {
        std::cout << a - 1 << " " << 0;
        return 0;
    }
    if (n - a * a <= a) {
        std::cout << n - a * a - 1 << " " << a;
        return 0;
    }
    else {
        std::cout << a << " " << a - (n - a * a) % (a + 1);
    }
}