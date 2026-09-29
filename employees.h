#ifndef EMPLOYEES_H
#define EMPLOYEES_H
#define MAX_EMPLOYEES 100
struct Employee {
    int id; char name[50]; char department[30];
    float basicSalary, housingAllowance, transportAllowance, totalSalary;
};
extern struct Employee employees[MAX_EMPLOYEES];
extern int employeeCount;
void addEmployee(); void displayEmployees(); void searchEmployee(); void displayEmployeeMenu();
#endif