#include "func.h"
#include <iostream>
#include <limits>

int main() {
    setlocale(LC_ALL, "ru");
    int numEmployees = 0;

    std::cout << "Введите количество сотрудников: ";
    while (!(std::cin >> numEmployees) || numEmployees <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Некорректный ввод. Пожалуйста, введите положительное число: ";
    }
    std::cin.ignore(); // Очистка буфера после ввода числа

    Employee* employees = new Employee[numEmployees];

    for (int i = 0; i < numEmployees; i++) {
        std::cout << "Сотрудник #" << (i + 1) << std::endl;
        initializeEmployee(employees[i]);
    }

    std::cout << std::endl;
    std::cout << "Список сотрудников по отделам в порядке убывания стажа:" << std::endl;
    printEmployeesByDepartment(employees, numEmployees);

    delete[] employees;

    return 0;
}