#include <iostream>

int rowSum(int* row, int k) {
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += row[i];
    }
    return sum;
}

void swapRows(int** array, int row1, int row2) {
    int* temp = array[row1];
    array[row1] = array[row2];
    array[row2] = temp;
}

void sortRows(int** array, int n, int k) {
    for (int i = 0; i < n - 1; i++) {
        int minSum = rowSum(array[i], k);
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            int currSum = rowSum(array[j], k);

            if (currSum < minSum) {
                minSum = currSum;
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swapRows(array, i, minIndex);
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int n, k;
    std::cout << "Введите размеры двумерного массива (n и k): ";
    std::cin >> n >> k;

    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[k];
    }

    std::cout << "Введите элементы массива:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            std::cin >> arr[i][j];
        }
    }

    sortRows(arr, n, k);

    std::cout << "Отсортированный массив:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}