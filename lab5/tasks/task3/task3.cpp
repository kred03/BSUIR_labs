#include <iostream>

bool isLocalMin(double** matrix, int i, int j, int k, int g) {
    double value = matrix[i][j];
    for (int x = std::max(i - 1, 0); x <= std::min(i + 1, k - 1); x++) {
        for (int y = std::max(j - 1, 0); y <= std::min(j + 1, g - 1); y++) {
            if ((x != i || y != j) && matrix[x][y] <= value) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int k, g;
    std::cin >> k >> g;

    double** matrix = new double* [k];
    for (int i = 0; i < k; i++) {
        matrix[i] = new double[g];
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < g; j++) {
            std::cin >> matrix[i][j];
        }
    }

    int localMinCount = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < g; j++) {
            if (isLocalMin(matrix, i, j, k, g)) {
                localMinCount++;
            }
        }
    }

    std::cout << localMinCount << std::endl;

    for (int i = 0; i < k; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}