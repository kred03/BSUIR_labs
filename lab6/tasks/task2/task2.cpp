#include <iostream>

void insertionSort(double arr[], int start, int end) {
    for (int i = start + 1; i <= end; i++) {
        double key = arr[i];
        int j = i - 1;

        while (j >= start && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void selectionSort(double arr[], int start, int end) {
    for (int i = start; i < end; i++) {
        int minIndex = i;

        for (int j = i + 1; j <= end; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            double temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void sortHalfArray(double arr[], int size) {
    int middle = size / 2;

    // Сортировка первой половины массива с использованием сортировки вставками
    insertionSort(arr, 0, middle - 1);

    // Сортировка второй половины массива с использованием сортировки выбором
    selectionSort(arr, middle, size - 1);
}

int main() {
    setlocale(LC_ALL, "rus");
    double* arr;
    int size;

    std::cout << "Введите количество элементов массива: ";
    std::cin >> size;

    arr = new double[size];

    std::cout << "Введите " << size << " элементов массива: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    sortHalfArray(arr, size);

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;

    return 0;
}
