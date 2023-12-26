#include <iostream>
#include <string>

int main() {
    setlocale(LC_ALL, "ru");

    std::cout << "������� ���������� �����, ������� �� ������ ������.\n";
    int n;
    std::cin >> n;

    std::string* a = new std::string[n];
    std::cout << "������� ������ ��������, ��������� �� �����, ����������� ���������.\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    long long* aNum = new long long[n];
    for (int i = 0; i < n; i++) {
        aNum[i] = std::stoll(a[i]);
    }
    long long temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (aNum[j] > aNum[j + 1]) {
                // ������ �������� �������
                temp = aNum[j];
                aNum[j] = aNum[j + 1];
                aNum[j + 1] = temp;
            }
        }
    }
    std::cout << "����� ���� ������ � ������� ����������� �� ��������:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << aNum[i] << "\t";
    }

    delete[] a;
    delete[] aNum;
}
