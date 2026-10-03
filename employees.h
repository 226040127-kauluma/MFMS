#ifndef EMPLOYEE_H
#define EMPLOYEE_H

// Employee arrays //

int employeeID[100];

char employeeName[100][50];
char department[100][50];
char qualification[100][100];
char gender[100][20];
char phoneNumber[100][20];

int age[100];

float workingHours[100];
float basicSalary[100];
float housingAllowance[100];
float transportAllowance[100];
float otherAllowance[100];


// Function declarations //

void displayMenu();

int addEmployee(int count);

void displayEmployees(int count);

int searchEmployee(int id, int ids[], int size);

void displayEmployee(int position);

float calculateSalary(
    float basic,
    float housing,
    float transport,
    float other
);

#endif
