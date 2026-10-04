# MFMS
Municipal Financial Management System (MFMS)
Course: PAP521S – Programming in Practice Project: Project A – Foundation System Group Number: [GROUP NUMBER] Language: ANSI C (C99)
Group Members
#
Name
Student Number
GitHub Username
1
[Name]
[Number]
[@username]
2
[Name]
[Number]
[@username]
3
[Name]
[Number]
[@username]
4
[Name]
[Number]
[@username]
5
[Name]
[Number]
[@username]
6
[Name]
[Number]
[@username]
7
[Name]
[Number]
[@username]

Project Description
The MFMS is a menu-driven console application written in C for managing the basic financial and administrative records of a municipality. It covers employees, departmental budgets, suppliers and municipal assets, and produces summary reports. This is the foundation version, which will be extended and refactored in Project B.
System Features
Main Menu

Clear, numbered navigation with handling of invalid choices.

Employee Management

Add, display and search employees
Salary calculation (basic salary + housing allowance + transport allowance, etc.)

Budget Management

Enter departmental budgets and expenditure
Calculate remaining budget and show WITHIN BUDGET / EXCEEDED status
Identify departments that exceeded their budget

Supplier Management

Add, display and search suppliers (ID, name, email, telephone, town)

Asset Management

Asset register (ID, name, type, purchase value, department, condition)
Display and search assets

Reports

Employee report (total, average, highest, lowest salary)
Budget report (total allocated, total expenditure, remaining, departments over budget)
Supplier report
Asset report

Data Validation

Rejects negative salaries/budgets, empty names, invalid numbers and invalid menu choices.
Project Structure
MFMS/

├── main.c

├── employees.c / employees.h

├── budget.c    / budget.h

├── suppliers.c / suppliers.h

├── assets.c    / assets.h

├── reports.c   / reports.h

├── README.md

└── TEST_PLAN.md
Compilation Instructions
Requires GCC.

gcc -std=c99 -Wall -Wextra main.c employees.c budget.c suppliers.c assets.c reports.c -o mfms

(On Windows with MinGW the output will be mfms.exe.)
How to Run
./mfms          # Linux / macOS / Git Bash

mfms.exe        # Windows Command Prompt

Then use the number keys to choose an option from the main menu.
Individual Responsibilities
Member
Responsibility
Files / Functions
Student 1 – [Name]
Employee Management
employees.c, employees.h
Student 2 – [Name]
Budget Management
budget.c, budget.h
Student 3 – [Name]
Supplier Management
suppliers.c, suppliers.h
Student 4 – [Name]
Asset Management
assets.c, assets.h
Student 5 – [Name]
Reports
reports.c, reports.h
Student 6 – [Name]
Functions, integration and validation
main.c, validation helpers
Student 7 – [Name]
Testing, documentation and Git coordination
TEST_PLAN.md, README.md, report

Testing
See TEST_PLAN.md for test cases and results.
Known Limitations
[List anything not implemented, e.g. data is not saved after exit]

