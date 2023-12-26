#include <iostream>

int main() {
    setlocale(LC_ALL, "RU");
    int N;

    std::cout << "Введите размер матрицы: ";
    std::cin >> N;

    double** matrix = new double* [N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new double[N];
    }

    std::cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "Исходная матрица:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    int maxRow = 0;
    for (int i = 1; i < N; i++) {
        if (matrix[i][0] > matrix[maxRow][0]) {
            maxRow = i;
        }
    }

    int minColumn = 0;
    for (int j = 1; j < N; j++) {
        if (matrix[0][j] < matrix[0][minColumn]) {
            minColumn = j;
        }
    }

    double scalarProduct = 0.0;
    for (int j = 0; j < N; j++) {
        scalarProduct += matrix[maxRow][j] * matrix[j][minColumn];
    }

    std::cout << "Скалярное произведение строки " << maxRow << " и столбца " << minColumn << ": " << scalarProduct << "\n";

    for (int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}