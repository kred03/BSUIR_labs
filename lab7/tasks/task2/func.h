#pragma once
#include "struct.h"

// ������� ��� ������������� ������ ����������
void initializeEmployee(Employee& employee);

// ������� ��� ������ ������ ����������� �� ������� � ������� �������� �����
void printEmployeesByDepartment(const Employee* employees, int numEmployees);