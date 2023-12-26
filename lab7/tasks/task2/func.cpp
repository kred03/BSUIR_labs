#include <iostream>
#include <algorithm>
#include "func.h"

// ������� ��� ������������� ������ ����������
void initializeEmployee(Employee& employee) {
    setlocale(LC_ALL, "ru");
    std::cout << "������� �.�.�. ����������: ";
    std::getline(std::cin >> std::ws, employee.fullName);

    std::cout << "������� ����� ������: ";
    std::cin >> employee.departmentNumber;

    std::cout << "������� ���������: ";
    std::getline(std::cin >> std::ws, employee.position);

    std::cout << "������� ���� ������ ������: ";
    std::getline(std::cin >> std::ws, employee.startDate);
}

// ������� ��� ������ ������ ����������� �� ������� � ������� �������� �����
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
            std::cout << "����� " << currentDepartment << ":" << std::endl;
        }
        std::cout << "�.�.�.: " << employee.fullName << std::endl;
        std::cout << "���������: " << employee.position << std::endl;
        std::cout << "���� ������ ������: " << employee.startDate << std::endl;
        std::cout << std::endl;
    }

    delete[] sortedEmployees;
}