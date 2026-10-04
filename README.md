
# MFMS
Municipal Financial Management System (MFMS)
Course: PAP521S 
Programming in Practice Project: Project A Foundation System 
Language: ANSI C (C99)
Group Members
#
Name
Student Number
GitHub Username

1
[Phillipus Kamati]
[226043150]
[@226043150-Phillipus Kamati]

2
[Kauluma Natangwe]
[226040127]
[@226040127-kauluma]

3
[Eichas L Sylvia]
[226171752]
[@Slyia-226171752]

4
[Rauna Shindumbu]
[226098710]
[@226098710-Shindumbu]

5
[Hillary Kavilla]
[226095649]
[@226095649-Kavilla]

6
[Josephine Teodol]
[225944226]
[@225044226-Teodol]

7
[Vannesa Tapalo]
[224061011]
[@Vannesa-224061011]

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

main.c

employees.c / employees.h

budget.c    / budget.h

suppliers.c / suppliers.h

assets.c    / assets.h

reports.c   / reports.h

README.md

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
Student 1 – [Phillipus Kamati]
Employee Management
employees.c, employees.h
Student 2 – [Kauluma Natangwe]
Budget Management
budget.c, budget.h
Student 3 – [Eichas L Sylvia]
Supplier Management
suppliers.c, suppliers.h
Student 4 – [Rauna Shindumbu]
Asset Management
assets.c, assets.h
Student 5 – [Hillary Kavilla]
Reports
reports.c, reports.h
Student 6 – [Josephine Teodol]
Functions, integration and validation
main.c, validation helpers
Student 7 – [Vannesa Tapalo]
Testing, documentation and Git coordination,
README.md


Known Limitations
Data is kept in memory only and is lost when the program closes.
Duplicate employee IDs are not yet rejected.
Supplier email and telephone formats are not validated.
Supplier name search is an exact, case-sensitive match.





