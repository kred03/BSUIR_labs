#include <iostream>

const int MAX_SIZE = 100;

void shiftArray(int array[], int size, int shift) {

    int temp[MAX_SIZE];

    for (int i = 0; i < shift; i++) {
        temp[i] = array[size - shift + i];
    }

    for (int i = size - 1; i >= shift; i--) {
        array[i] = array[i - shift];
    }

    for (int i = 0; i < shift; i++) {
        array[i] = temp[i];
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    int k;

    std::cout << "Введите размер массива: ";
    std::cin >> k;

    int array[MAX_SIZE];

    std::cout << "Введите элементы массива:\n";
    for (int i = 0; i < k; i++) {
        std::cin >> array[i];
    }

    int p;

    std::cout << "Введите значение p: ";
    std::cin >> p;

    std::cout << "Исходный массив: ";
    for (int i = 0; i < k; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

    shiftArray(array, k, p);

    std::cout << "Результат сдвига на " << p << " позиций вправо: ";
    for (int i = 0; i < k; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

    return 0;
}