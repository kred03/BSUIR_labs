#include <iostream>
#include <string>

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "rus");

    std::string word;
    std::cout << "Введите слово (латинские буквы):" << std::endl;
    std::getline(std::cin, word);

    const int alphabetSize = 26;
    int letterCount[alphabetSize] = { 0 };

    for (char letter : word) {
        if (isalpha(letter)) {
            letter = toupper(letter);
            letterCount[letter - 'A']++;
        }
    }

    unsigned long long totalAnagrams = factorial(word.size());

    for (int i = 0; i < alphabetSize; ++i) {
        if (letterCount[i] > 1) {
            totalAnagrams /= factorial(letterCount[i]);
        }
    }

    std::cout << "Количество анаграмм: " << totalAnagrams << std::endl;

    return 0;
}