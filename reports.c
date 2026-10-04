/*
 * report.c - MFMS project report
 *
 * Prints the written project report for the Municipal Financial
 * Management System (MFMS). Compile standalone with:
 *     gcc -std=c99 -Wall -Wextra -pedantic -DREPORT_STANDALONE report.c -o report
 */

#include <stdio.h>

static void section(const char *title)
{
    printf("\n%s\n", title);
}

void display_project_report(void)
{
    puts("MFMS PROJECT REPORT");
    puts("===================");

    section("1. Introduction");
    puts("The Municipal Financial Management System (MFMS) is a foundation C");
    puts("application developed for a municipality. The purpose of the system is");
    puts("to demonstrate the practical application of programming concepts covered");
    puts("in PAP521S during Weeks 1-8.");
    puts("");
    puts("The application is menu-driven and provides modules for employee");
    puts("management, budget management, supplier management, asset management");
    puts("and reports.");

    section("2. Problem Description");
    puts("A municipality manages financial and operational information involving");
    puts("employees, departmental budgets, suppliers and municipal assets.");
    puts("Managing this information manually can make searching, calculating and");
    puts("reporting more difficult.");
    puts("");
    puts("The MFMS provides a simple foundation for storing information in arrays");
    puts("and performing calculations and searches through a structured C program.");

    section("3. System Objectives");
    puts("The objectives are to:");
    puts("  - Develop a menu-driven C application.");
    puts("  - Accept and validate user input.");
    puts("  - Use appropriate variables and data types.");
    puts("  - Apply arithmetic, relational and logical operators.");
    puts("  - Use decision-making structures.");
    puts("  - Use loops and arrays.");
    puts("  - Manipulate strings.");
    puts("  - Create and use functions.");
    puts("  - Pass parameters and return values.");
    puts("  - Organise the program into logical modules.");

    section("4. System Features");
    puts("Employee Management");
    puts("  Users can add employees, display employee information and search for");
    puts("  employees. Salary information is calculated using the basic salary");
    puts("  and allowances.");
    puts("");
    puts("Budget Management");
    puts("  Users can enter departmental budgets and expenditure. The program");
    puts("  calculates the remaining budget and identifies departments that have");
    puts("  exceeded their allocation.");
    puts("");
    puts("Supplier Management");
    puts("  Users can register suppliers with supplier ID, name, email, telephone");
    puts("  number and location. Suppliers can be displayed and searched.");
    puts("");
    puts("Asset Management");
    puts("  The asset register stores asset ID, name, type, purchase value,");
    puts("  department and condition. Users can display and search assets.");
    puts("");
    puts("Reports");
    puts("  The system provides employee, budget, supplier and asset reports.");

    section("5. Program Design");
    puts("The program is divided into modules rather than placing all");
    puts("functionality inside main().");
    puts("");
    puts("  - main.c           controls the main menu and connects the modules.");
    puts("  - employees.c/.h   handles employee data and salary calculations.");
    puts("  - budget.c/.h      handles budgets and expenditure.");
    puts("  - suppliers.c/.h   handles supplier information.");
    puts("  - assets.c/.h      handles the asset register.");
    puts("  - reports.c/.h     produces summary reports.");
    puts("");
    puts("Arrays store multiple records. Structures group related information");
    puts("into records. Functions receive parameters and return calculated values");
    puts("where appropriate.");
    puts("");
    puts("String functions such as strlen() and strcmp() are used for input");
    puts("validation and searching.");

    section("6. Challenges Encountered");
    puts("Possible development challenges included:");
    puts("  - Validating numerical input.");
    puts("  - Preventing duplicate IDs.");
    puts("  - Organising a large program into modules.");
    puts("  - Passing arrays and counters between functions.");
    puts("  - Calculating and reporting financial information correctly.");
    puts("  - Coordinating code changes between group members.");

    section("7. Solutions Implemented");
    puts("Input helper functions were created to validate integers, decimal");
    puts("values and strings.");
    puts("");
    puts("Separate .c and .h files were used to divide the system into logical");
    puts("modules.");
    puts("");
    puts("Duplicate ID checking was implemented for employees, suppliers and");
    puts("assets.");
    puts("");
    puts("Budget calculations use dedicated functions so that the calculation");
    puts("can be reused in different parts of the program.");
    puts("");
    puts("Reports calculate totals, averages and budget status from the stored");
    puts("arrays.");
    puts("");
    puts("GitHub should be used to track each member's contribution and");
    puts("coordinate integration.");

    section("8. Conclusion");
    puts("The MFMS demonstrates the programming concepts covered during the first");
    puts("part of PAP521S. It provides a functional foundation that can be");
    puts("extended in a future project.");
    puts("");
    puts("The system follows the required flow of input, processing, storage,");
    puts("search, calculation and output. The project can therefore serve as the");
    puts("foundation for further improvements in Project B.");
}

#ifdef REPORT_STANDALONE
int main(void)
{
    display_project_report();
    return 0;
}
#endif
