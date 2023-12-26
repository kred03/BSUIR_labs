#include "func.h"
#include <iostream>
#include <limits>

int main() {
    setlocale(LC_ALL, "ru");
    int numEmployees = 0;

    std::cout << "������� ���������� �����������: ";
    while (!(std::cin >> numEmployees) || numEmployees <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "������������ ����. ����������, ������� ������������� �����: ";
    }
    std::cin.ignore(); // ������� ������ ����� ����� �����

    Employee* employees = new Employee[numEmployees];

    for (int i = 0; i < numEmployees; i++) {
        std::cout << "��������� #" << (i + 1) << std::endl;
        initializeEmployee(employees[i]);
    }

    std::cout << std::endl;
    std::cout << "������ ����������� �� ������� � ������� �������� �����:" << std::endl;
    printEmployeesByDepartment(employees, numEmployees);

    delete[] employees;

    return 0;
}