#pragma once
#include "struct.h"

// Функция для инициализации данных сотрудника
void initializeEmployee(Employee& employee);

// Функция для вывода списка сотрудников по отделам в порядке убывания стажа
void printEmployeesByDepartment(const Employee* employees, int numEmployees);