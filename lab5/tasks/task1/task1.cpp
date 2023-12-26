#include <iostream>

const int N = 3;
const int M = 3;

int main() {
    setlocale(LC_ALL, "RU");

    int matrix[N][M];

    std::cout << "Введите элементы матрицы " << N << "x" << M << ":\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "Исходная матрица:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    int maxBelowDiagonal = matrix[N - 1][0];

    for (int i = N - 2; i >= 0; i--) {
        for (int j = M - (N - i); j < M; j++) {
            if (matrix[i][j] > maxBelowDiagonal) {
                maxBelowDiagonal = matrix[i][j];
            }
        }
    }

    std::cout << "Максимальный элемент ниже побочной диагонали: " << maxBelowDiagonal << "\n";

    return 0;
}