#include <iostream>
#include <algorithm> 
#include<cmath>
//int checking_input_i()
//{
//    char th = getchar();
//    if (th == '\n' || th == ' ')
//    {
//        return 1;
//    }
//    else
//    {
//        std::cin.clear();
//        std::cin.ignore(10000, '\n');
//        return 0;
//    }
//}
int main() {
    long long  n, d, n1, n2, q = 0, n3;
    q = 0;
    n1 = 0;
    n2 = 0;
    d = 0;
    n3 = 0;
    std::cin >> n;
    if (n != 0)
    {
        while (n / (long long)pow(10, q) > 0)
        {
            n1++;
            q++;
        }
        q = 0;
        while ((n - 1) / (long long)pow(10, q) > 0)
        {
            n2++;
            q++;
        }
        n3 = n1 + n2;
        char* a = new  char[n1];
        char* b = new  char[n2];
        char* c = new  char[n3];
        for (long long i = 0; i < n3; i++)
        {
            c[i] = 0;
        }
        for (long long i = 0; i < n1; i++)
        {
            a[i] = n / (long long)pow(10, n1 - 1 - i) % 10 + '0';
        }
        for (long long i = 0; i < n2; i++)
        {
            b[i] = (n - 1) / (long long)pow(10, n2 - 1 - i) % 10 + '0';
        }
        std::reverse(a, a + n1);
        std::reverse(b, b + n2);


        for (long long i = 0; i < n1; i++)
        {
            for (long long j = 0; j < n2; j++)
            {
                c[i + j] += (a[i] - '0') * (b[j] - '0') + d;
                d = c[i + j] / 10;
                c[i + j] %= 10;
            }
            c[i + n2] = d;

            d = 0;
        }
        for (long long i = n3 - 1; i >= 0; i--)
        {
            c[i] += 10 * d;
            d = c[i] % 2;
            c[i] /= 2;
        }
        d = 1;
        for (long long i = 0; i < n3; i++)
        {
            c[i] += d;
            d = c[i] / 10;
            c[i] %= 10;
            c[i] += '0';
        }
        long long ch = 0;
        while (c[n3 - 1] == '0')
        {
            n3--;
        }
        std::reverse(c, c + n3);
        for (long long i = 0; i < n3; i++)
        {
            std::cout << c[i];
        }
        std::cout << '\n';
        delete[] a;
        delete[] b;
        delete[] c;

    }
    else if (n == 0)
    {

        std::cout << 1 << '\n';
    }
}