#include <iostream> 
#include <string> 

// Функция для разворота строки 
void reverseString(std::string& str) {
    setlocale(LC_ALL, "RU");
    int start = 0;
    int end = str.length() - 1;
    while (start < end) {
        std::swap(str[start], str[end]);
        start++;
        end--;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    int rows, cols;

    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;
 
    std::string** matrix = new std::string * [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new std::string[cols];
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    // Обработка каждой строки матрицы 
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::string& word = matrix[i][j];
            int sum = 0;

            for (char ch : word) {
                sum += static_cast<int>(ch);
            }

            if (sum % 2 == 0) {
                reverseString(word);
            }
        }
    }

    std::cout << "Измененная матрица:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
