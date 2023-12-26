#include <iostream>
#include <algorithm>
#include "func.h"

// Функция для инициализации данных сотрудника
void initializeEmployee(Employee& employee) {
    setlocale(LC_ALL, "ru");
    std::cout << "Введите Ф.И.О. сотрудника: ";
    std::getline(std::cin >> std::ws, employee.fullName);

    std::cout << "Введите номер отдела: ";
    std::cin >> employee.departmentNumber;

    std::cout << "Введите должность: ";
    std::getline(std::cin >> std::ws, employee.position);

    std::cout << "Введите дату начала работы: ";
    std::getline(std::cin >> std::ws, employee.startDate);
}

// Функция для вывода списка сотрудников по отделам в порядке убывания стажа
void printEmployeesByDepartment(const Employee* employees, int numEmployees) {
    setlocale(LC_ALL, "ru");
    Employee* sortedEmployees = new Employee[numEmployees];
    std::copy(employees, employees + numEmployees, sortedEmployees);

    std::sort(sortedEmployees, sortedEmployees + numEmployees, [](const Employee& a, const Employee& b) {
        return a.startDate > b.startDate;
        });

    int currentDepartment = -1;
    for (int i = 0; i < numEmployees; i++) {
        const Employee& employee = sortedEmployees[i];
        if (employee.departmentNumber != currentDepartment) {
            currentDepartment = employee.departmentNumber;
            std::cout << "Отдел " << currentDepartment << ":" << std::endl;
        }
        std::cout << "Ф.И.О.: " << employee.fullName << std::endl;
        std::cout << "Должность: " << employee.position << std::endl;
        std::cout << "Дата начала работы: " << employee.startDate << std::endl;
        std::cout << std::endl;
    }

    delete[] sortedEmployees;
}